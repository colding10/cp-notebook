# cp-notebook

![GitHub repo size](https://img.shields.io/github/repo-size/colding10/cp-notebook?style=for-the-badge)

This repo is a collection of:

- my templates (C++) for coding contests
- solutions to various online judge problems
- and a handy neovim plugin to search for a template and paste it

I will also be adding tools, resources, and such as I find and use them.

### How to use the plugin

Clone this repo, take the `nvim-plugin` folder, and install it to (neo)vim with a package manager of your choice.

### Project structure

```bash
.
├── LICENSE
├── README.md
├── nvim-plugin
│   ├── lua
│   │   └── algo-ds
│   │       └── init.lua
│   └── plugin
│       └── algo-ds.vim
├── solutions                     [solutions to various online judges]
│   │
│   ├── codeforces                all of my codeforces solutions
│   ├── cses.fi                   all of my cses solutions
│   ├── usaco-contest             usaco solutions (needs organizing)
│   └── usaco-training            usaco training (needs organizing)
└── templates                     [where i keep my templates]
    ├── BST
    ├── DP
    ├── Examples
    ├── Geometry
    ├── Graphs
    ├── Main
    │   ├── basic_types.h
    │   ├── ckmin_max.h
    │   ├── long-template.cpp
    │   ├── minimal-template.cpp
    │   ├── short-template.cpp
    │   └── vector_types.h
    ├── Math
    ├── Other
    ├── RangeQuery
    ├── Strings
    └── Trie
```
