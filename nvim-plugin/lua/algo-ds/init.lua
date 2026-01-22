---@diagnostic disable: undefined-global
local template_dir = "/Users/colin/cp-notebook/templates"

local actions = require "telescope.actions"
local action_state = require "telescope.actions.state"

local function Filter(lines)
    local filteredLines = {}
    local start_index = 1

    -- Look for delimiter comment (e.g., "// ---") to mark end of preamble
    for i, line in ipairs(lines) do
        if line:match("^%s*// ?%-%-%-") then
            start_index = i + 1
            break
        end
    end

    -- If no delimiter found, fall back to old behavior: skip #includes and using namespace std;
    if start_index == 1 then
        local skipping = true
        for _, line in ipairs(lines) do
            if skipping and not (line:match("^%s*#") or line:match("^%s*using namespace std;%s*$") or line:match("^%s*typedef long long ll;%s*$")) then
                skipping = false
            end
            if not skipping then
                table.insert(filteredLines, line)
            end
        end
    else
        for i = start_index, #lines do
            table.insert(filteredLines, lines[i])
        end
    end

    return filteredLines
end

local function run_selection(prompt_bufnr, _)
    actions.select_default:replace(function()
        actions.close(prompt_bufnr)
        local file = action_state.get_selected_entry()

        if file then
            local file_path = template_dir .. "/" .. file[1]
            local content = vim.fn.readfile(file_path)

            if not (string.find(file[1], "template") or string.find(file[1], "preamble")) then
                content = Filter(content)
            end

            -- insert content properly without leaving blank lines
            local buf = 0
            local row = vim.api.nvim_win_get_cursor(0)[1] - 1
            if vim.api.nvim_buf_get_lines(buf, row, row + 1, false)[1]:match("^%s*$") then
                vim.api.nvim_buf_set_lines(buf, row, row + 1, false, content)
            else
                vim.api.nvim_buf_set_lines(buf, row + 1, row + 1, false, content)
            end
        end
    end)
    return true
end

local function AlgDS()
    require("telescope.builtin").find_files({
        cwd = template_dir,
        previewer = true,
        attach_mappings = run_selection
    })
end

local M = {}
M.run = AlgDS

return M
