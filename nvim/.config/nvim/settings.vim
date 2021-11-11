" Latex auto compile and redraw
autocmd BufWritePost *.tex silent! execute "!pdflatex % >/dev/null 2>&1 &" | redraw!

" Groff auto compile and redraw
autocmd BufWritePost *.ms silent! execute "!eqn % -Tpdf | groff -Tpdf -ms > main.pdf&" | redraw!

syntax on

set exrc
set secure
set number
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
set ttimeoutlen=0
