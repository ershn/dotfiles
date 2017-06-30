# Environment variables
PATH="${PATH}:${HOME}/.local/bin"
export EDITOR=vim

# Alias
alias la='ls -a'
alias ll='ls -lh'
alias lla='ls -lha'
alias emacs='emacs -nw'

# jEnv
if hash jenv 2> /dev/null; then
  eval "$(jenv init -)"
fi

# Golang settings
GOROOT=/usr/local/opt/go/libexec

if [ -d $GOROOT ]; then
  export GOROOT
  PATH=$PATH:$(go env GOPATH)/bin:$GOROOT/bin
fi

# Google cloud settings
GCLOUD_HOME=/usr/local/Caskroom/google-cloud-sdk/latest/google-cloud-sdk

if [ -d $GCLOUD_HOME ]; then
  source $GCLOUD_HOME/completion.bash.inc
  source $GCLOUD_HOME/path.bash.inc
fi

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
