if exists("g:loaded_algods")
    finish
endif

let g:loaded_algods = 1

" " Defines a package path for Lua. This facilitates importing the
" " Lua modules from the plugin's dependency directory.
" let s:lua_rocks_deps_loc =  expand("<sfile>:h:r") . "/../lua/algo-ds/deps"
" exe "lua package.path = package.path .. ';" . s:lua_rocks_deps_loc . "/lua-?/init.lua'"

" Exposes the plugin's functions for use as commands in Neovim.
command! -nargs=0 ADS lua require("algo-ds").run()
