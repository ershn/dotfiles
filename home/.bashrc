# Environment variables
PATH="${PATH}:${HOME}/.local/bin"
export EDITOR=vim

# Alias
alias ls='ls -GF'
alias la='ls -a'
alias ll='ls -lh'
alias lla='ls -lha'
alias emacs='emacs -nw'
alias ssh='TERM=screen ssh'

# rbenv
if hash rbenv > /dev/null; then
	eval "$(rbenv init -)"

  if hash brew > /dev/null; then
    export RUBY_CONFIGURE_OPTS="--with-openssl-dir=$(brew --prefix openssl) --with-readline-dir=$(brew --prefix readline) $RUBY_CONFIGURE_OPTS"
  fi
fi

# nodebrew
NODEBREW_BIN=$HOME/.nodebrew/current/bin

if [ -d "$NODEBREW_BIN" ]; then
  PATH=$NODEBREW_BIN:$PATH
fi

# jEnv
if hash jenv 2> /dev/null; then
  eval "$(jenv init -)"
fi

# Golang
GOROOT=/usr/local/opt/go/libexec

if [ -d $GOROOT ]; then
  export GOROOT
  PATH=$PATH:$(go env GOPATH)/bin:$GOROOT/bin
fi

# Google cloud
GCLOUD_HOME=/usr/local/Caskroom/google-cloud-sdk/latest/google-cloud-sdk

if [ -d $GCLOUD_HOME ]; then
  source $GCLOUD_HOME/completion.bash.inc
  source $GCLOUD_HOME/path.bash.inc
fi

# pyenv
if which pyenv > /dev/null; then
  eval "$(pyenv init -)"
fi

# Git
GIT_PS1_SHOWDIRTYSTATE=true

# Bash completion
for file in /usr/local/etc/bash_completion.d/*; do
  if [ -f "$file" ]; then
    source "$file"
  fi
done

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
    lci)
      shift
      /usr/bin/env git log --pretty='%h' "$@"
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
