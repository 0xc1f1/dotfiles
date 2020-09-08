set nocompatible              " be iMproved, required
filetype off                  " required

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

map fe :!make<CR>
map fre :!make run<CR>
map fw :!sudo make clean install<CR>
map fa :tabe
map K :tabn<CR>
map J :tabp<CR>

map gre <ESC>a //
map gcc <ESC>i /*  */<ESC>hh
map gff <ESC>0i//<ESC>

" nnoremap <C-J> <C-W>j
" nnoremap <C-K> <C-W>k
" nnoremap <C-L> <C-W>l
" nnoremap <C-H> <C-W>h

map <C-n> :NERDTreeToggle<CR>

map E $
map B 0

inoremap fs <ESC>:w<CR>
vnoremap fs <ESC>:w<CR>
map fs :w<CR>
map fq :q<CR>
map ffq :q!<CR>

nnoremap <C-J> <C-W>j
nnoremap <C-K> <C-W>k
nnoremap <C-L> <C-W>l
nnoremap <C-H> <C-W>h

call plug#begin('~/.vim/plugged')
Plug 'dylanaraps/fff.vim'
call plug#end()
