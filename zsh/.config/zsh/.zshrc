# CLEAN $HOME
PATH="$PATH:$HOME/.local/bin"
export XDG_DATA_HOME=$HOME"/.local/share"
export XDG_CONFIG_HOME=$HOME"/.config"
export GNUPGHOME="$XDG_DATA_HOME/gnupg"
export HISTFILE="$XDG_DATA_HOME"/bash/history
export CCACHE_CONFIGPATH="$XDG_CONFIG_HOME"/ccache.config
export CCACHE_DIR="$XDG_CACHE_HOME"/ccache
export CARGO_HOME="$XDG_DATA_HOME"/cargo
export GOPATH="$XDG_DATA_HOME"/go
export XAUTHORITY="$XDG_RUNTIME_DIR"/Xauthority
export CUDA_CACHE_PATH="$XDG_CACHE_HOME"/nv
export _JAVA_OPTIONS=-Djava.util.prefs.userRoot="$XDG_CONFIG_HOME"/java

# Get color support for 'less'
export LESS="--RAW-CONTROL-CHARS"

# Use colors for less, man, etc.
[[ -f ~/.LESS_TERMCAP ]] && . ~/.LESS_TERMCAP

export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

export EDITOR="nvim"
export PATH="$HOME/opt/cross/bin:$PATH:$HOME/.scripts"
export BROWSER="/usr/bin/urlportal.sh"

# Enable colors and change prompt:
autoload -U colors && colors
#PS1="%B%{$fg[red]%}[%{$fg[yellow]%}%n%{$fg[green]%}@%{$fg[blue]%}%M %{$fg[magenta]%}%~%{$fg[red]%}]%{$reset_color%}$%b "
PS1="%F{cyan}%~ %f> "
alias fd='nvim'
alias jk='cd'
alias ls='ls --color'
alias la='ls -A'
alias install='sudo pacman -Sy --noconfirm'
alias search='sudo pacman -Sys'
alias upgrade='sudo pacman -Syu --noconfirm'
alias remove='sudo pacman -R'
alias xclip='xclip -selection c'
alias ytmp3='youtube-dl --extract-audio --audio-format mp3 -o "%(title)s.%(ext)s"'
alias ytdl='youtube-dl -o "%(title)s.%(ext)s"'
alias monerod='monerod --data-dir "$XDG_DATA_HOME"/bitmonero'
alias gfjk='grep --color=auto'
alias ejk='exit'

# Basically just Luke Smiths zsh config

# History in cache directory:
HISTSIZE=10000
SAVEHIST=10000
HISTFILE=~/.cache/zsh/history

# Basic auto/tab complete:
autoload -U compinit
zstyle ':completion:*' menu select
zmodload zsh/complist
compinit
_comp_options+=(globdots)		# Include hidden files.

# vi mode
bindkey -v
export KEYTIMEOUT=1

# Use vim keys in tab complete menu:
bindkey -M menuselect 'h' vi-backward-char
bindkey -M menuselect 'k' vi-up-line-or-history
bindkey -M menuselect 'l' vi-forward-char
bindkey -M menuselect 'j' vi-down-line-or-history
bindkey -v '^?' backward-delete-char

# Change cursor shape for different vi modes.
function zle-keymap-select {
  if [[ ${KEYMAP} == vicmd ]] ||
     [[ $1 = 'block' ]]; then
    echo -ne '\e[1 q'
  elif [[ ${KEYMAP} == main ]] ||
       [[ ${KEYMAP} == viins ]] ||
       [[ ${KEYMAP} = '' ]] ||
       [[ $1 = 'beam' ]]; then
    echo -ne '\e[5 q'
  fi
}
zle -N zle-keymap-select
zle-line-init() {
    zle -K viins # initiate `vi insert` as keymap (can be removed if `bindkey -V` has been set elsewhere)
    echo -ne "\e[5 q"
}
zle -N zle-line-init
echo -ne '\e[5 q' # Use beam shape cursor on startup.
preexec() { echo -ne '\e[5 q' ;} # Use beam shape cursor for each new prompt.

# Use lf to switch directories and bind it to ctrl-o
lfcd () {
    tmp="$(mktemp)"
    lf -last-dir-path="$tmp" "$@"
    if [ -f "$tmp" ]; then
        dir="$(cat "$tmp")"
        rm -f "$tmp"
        [ -d "$dir" ] && [ "$dir" != "$(pwd)" ] && cd "$dir"
    fi
}
bindkey -s '^o' 'lfcd\n'

# Edit line in vim with ctrl-e:
autoload edit-command-line; zle -N edit-command-line
bindkey '^e' edit-command-line


# Load aliases and shortcuts if existent.
[ -f "$HOME/.config/shortcutrc" ] && source "$HOME/.config/shortcutrc"
[ -f "$HOME/.config/aliasrc" ] && source "$HOME/.config/aliasrc"

# Load zsh-syntax-highlighting; should be last.
source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh 2>/dev/null
