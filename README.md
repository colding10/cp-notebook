# cp-notebook

![GitHub repo size](https://img.shields.io/github/repo-size/colding10/cp-notebook?style=for-the-badge)

This repo is a collection of:

- my templates (C++) for coding contests
- solutions to various online judge problems
- and a handy neovim plugin to search for a template and paste it

I will also be adding tools, resources, and such as I find and use them.

## How to use the plugin

Clone this repo, take the `nvim-plugin` folder, and install it to (neo)vim with a package manager of your choice.

 gcc-pragmas.cpp  preamble.cpp  template-minimal.cpp
 grid-dydx.cpp  setio.cpp  template-multiTC.cpp

## Project structure

```zsh
.
├── LICENSE
├── README.md                     [file you're reading right now]
│
├── nvim-plugin                   [the nvim plugin]
│   ├── lua
│   │   └── algo-ds
│   │       └── init.lua
│   └── plugin
│       └── algo-ds.vim
│
├── solutions                     [solutions to various online judges]
│   ├── codeforces                all of my codeforces solutions
│   ├── cses.fi                   all of my cses solutions
│   ├── usaco-contest             usaco solutions 
│   └── usaco-training            usaco training 
│
└── templates                     [where i keep my templates]
    ├── Main                      [generic templates]
    │   ├── preamble.cpp
    │   ├── setio.cpp
    │   ├── template-minimal.cpp
    │   ├── template-multiTC.cpp
    │   ├── grid-dydx.cpp
    │   ├── setio.cpp
    └── Etc....                   [and a bunch of other folders w/ code]
```
