# Environment variables
PATH="${PATH}:${HOME}/.local/bin"
export EDITOR=vim

# Alias
alias ls='ls -GF'
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

# Git commands
git() {
  case "$1" in
    b)
      /usr/bin/env git status -sb
      ;;
    bs)
      shift
      /usr/bin/env git branch "$@"
      ;;
    bc)
      shift
      local branch=$(/usr/bin/env git branch "$@" | cut -b 3- | peco)
      /usr/bin/env git checkout "${branch}"
      ;;
    s)
      shift
      /usr/bin/env git status "$@"
      ;;
    svn)
      shift
      git_svn "$@"
      ;;
    *)
      /usr/bin/env git "$@"
      ;;
  esac
}

git_svn() {
  case "$1" in
    fetch | rebase | dcommit)
      local command=$1
      shift
      /usr/bin/env git svn "$command" --localtime "$@"
      ;;
    *)
      /usr/bin/env git svn "$@"
      ;;
  esac
}

# Source homesick
source "$HOME/.homesick/repos/homeshick/homeshick.sh"
source "$HOME/.homesick/repos/homeshick/completions/homeshick-completion.bash"

homeshick --quiet refresh
