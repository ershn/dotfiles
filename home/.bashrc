# Environment variables
PATH="${PATH}:${HOME}/.local/bin"
export EDITOR=vim

# Alias
alias la='ls -a'
alias ll='ls -lh'
alias lla='ls -lha'

# Source homesick
source "$HOME/.homesick/repos/homeshick/homeshick.sh"
source "$HOME/.homesick/repos/homeshick/completions/homeshick-completion.bash"

homeshick --quiet refresh