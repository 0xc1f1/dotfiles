nnoremap ; :
nnoremap : ;

nnoremap <M-d> :!make<CR>
nnoremap <M-r> :!make run<CR>
nnoremap <M-o> :tabe
nnoremap <M-s> :w<CR>

nnoremap <S-k> :tabn<CR>
nnoremap <S-j> :tabp<CR>

" open the neovim config
nnoremap ev :tabe ~/.config/nvim/init.vim<CR>

" reload(source) the neovim config
nnoremap er :so ~/.config/nvim/init.vim<CR>

map gh <Plug>(Vman)

nnoremap <S-h> :call ToggleHiddenAll()<CR>

" UltiSnips keybinds
let g:UltiSnipsExpandTrigger="<tab>"
let g:UltiSnipsJumpForwardTrigger="<tab>"
let g:UltiSnipsJumpBackwardTrigger="<s-tab>"
