" Latex auto compile and redraw
autocmd BufWritePost *.tex silent! execute "!pdflatex % >/dev/null 2>&1 &" | redraw!

set exrc
set secure
set number
syntax on

set fillchars=eob:\ 

set lazyredraw

set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
set relativenumber
set nohlsearch
set hidden
set noerrorbells
set nowrap

set noshowmode
set noruler
set laststatus=0
set noshowcmd

let $NVIM_TUI_ENABLE_TRUE_COLOR=1

set ttimeoutlen=0
