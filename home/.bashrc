# Environment variables
PATH="${PATH}:${HOME}/.local/bin"
export EDITOR=vim

# Alias
alias la='ls -a'
alias ll='ls -lh'
alias lla='ls -lha'

# Switch between git branches
git() {
  if [ "$1" = bc ]; then
    shift
    local branch=$(/usr/bin/env git branch "$@" | cut -b 3- | peco)
    git checkout "${branch}"
  else
    /usr/bin/env git "$@"
  fi
}

# Source homesick
source "$HOME/.homesick/repos/homeshick/homeshick.sh"
source "$HOME/.homesick/repos/homeshick/completions/homeshick-completion.bash"

homeshick --quiet refresh
