autocmd BufWritePost *.tex silent! execute "!pdflatex % >/dev/null 2>&1 &" | redraw!

" set nocompatible              " be iMproved, required
" filetype off                  " required

set exrc
set secure
set number
syntax on

set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab

inoremap jk <ESC>
vnoremap jk <ESC>

nnoremap fe :!make<CR>
nnoremap fre :!make run<CR>
nnoremap fw :!sudo make clean install<CR>
nnoremap fa :tabe
nnoremap K :tabn<CR>
nnoremap J :tabp<CR>

nnoremap gre <ESC>a //
nnoremap gcc <ESC>i /*  */<ESC>hh
nnoremap gff <ESC>0i//<ESC>

nnoremap <C-J> <C-W>j
nnoremap <C-K> <C-W>k
nnoremap <C-L> <C-W>l
nnoremap <C-H> <C-W>h

nnoremap <C-n> :NERDTreeToggle<CR>

nnoremap E $
nnoremap B 0

inoremap fs <ESC>:w<CR>
vnoremap fs <ESC>:w<CR>
nnoremap fs :w<CR>
nnoremap fq :q<CR>
nnoremap ffq :q!<CR>

call plug#begin('~/.vim/plugged')
Plug 'dylanaraps/fff.vim'
Plug 'junegunn/goyo.vim'
call plug#end()
