" Vim-plug

"call plug#begin('~/.vim/plugged')

" Plugins
"Plug 'neoclide/coc.nvim', {'branch': 'release'}

"call plug#end()

" End vim-plug

set nocompatible              " be iMproved, required
filetype off                  " required

set exrc
set secure
set number
syntax on
" noremap ; l
" noremap l k
" noremap k j
" noremap j h
set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
" Remove newbie crutches in Command Mode
cnoremap <Down> <Nop>
cnoremap <Left> <Nop>
cnoremap <Right> <Nop>
cnoremap <Up> <Nop>

" Remove newbie crutches in Insert Mode
inoremap <Down> <Nop>
inoremap <Left> <Nop>
inoremap <Right> <Nop>
inoremap <Up> <Nop>

" Remove newbie crutches in Normal Mode
nnoremap <Down> <Nop>
nnoremap <Left> <Nop>
nnoremap <Right> <Nop>
nnoremap <Up> <Nop>

" Remove newbie crutches in Visual Mode
vnoremap <Down> <Nop>
vnoremap <Left> <Nop>
vnoremap <Right> <Nop>
vnoremap <Up> <Nop>

inoremap jk <ESC>
vnoremap jk <ESC>

inoremap fd <ESC>
vnoremap fd <ESC>

map <F8> :tabn<CR>
map <F7> :tabp<CR>
map <F6> :tabe

map <F5> :!make<CR>
map <F4> :!make run<CR>

map fe :!make<CR>
map fre :!make run<CR>
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
map fs <Esc>:w<CR>
map fq <Esc>:q<CR>
map ffq <Esc>:q!<CR>
