nnoremap ; :
nnoremap : ;

nnoremap <M-d> :!make<CR>
nnoremap <M-r> :!make run<CR>

norm Q gq

" tab stuff
nnoremap <M-o> :tabe
nnoremap <S-k> :tabn<CR>
nnoremap <S-j> :tabp<CR>

" open the neovim config
nnoremap ev :tabe ~/.config/nvim/<CR>

" reload(source) the neovim config
nnoremap er :so ~/.config/nvim/init.vim<CR>

" UltiSnips keybinds
let g:UltiSnipsExpandTrigger="<tab>"
let g:UltiSnipsJumpForwardTrigger="<tab>"
let g:UltiSnipsJumpBackwardTrigger="<s-tab>"
