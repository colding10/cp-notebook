local template_dir = "/Users/colin/cp-notebook/templates"

local actions = require "telescope.actions"
local action_state = require "telescope.actions.state"

local function Filter(lines)
    local filteredLines = {}
    local skipping = true

    for _, line in ipairs(lines) do
        if skipping and not (line:match("^%s*#") or line == "using namespace std;") then
            skipping = false
        end

        if not skipping then
            table.insert(filteredLines, line)
        end
    end

    return filteredLines
end

local function run_selection(prompt_bufnr, map)
    actions.select_default:replace(function()
        actions.close(prompt_bufnr)
        local file = action_state.get_selected_entry()

        if #file > 0 then
            local file_path = template_dir .. "/" .. file[1]
            local content = vim.fn.readfile(file_path)

            if not string.find(file[1], "template") then
                content = Filter(content)
            end

            vim.fn.append(vim.fn.line("."), content)
        end

    end)
    return true
end

local function AlgDS()
    local file = require("telescope.builtin").find_files({
        cwd = template_dir,
        previewer = true,
        attach_mappings = run_selection
    })
end

-- Creates an object for the module. All of the module's
-- functions are associated with this object, which is
-- returned when the module is called with `require`.
local M = {}

-- Routes calls made to this module to functions in the
-- plugin's other modules.
M.run = AlgDS

return M
