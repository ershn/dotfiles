# Environment variables
export PATH="${HOME}/bin:${PATH}:${HOME}/.local/bin"
export EDITOR=vim

# Prompt
git_branch() {
  git branch 2> /dev/null | sed -ne 's/^\* \(.*\)$/\1/p'
}

PS1='\[\e[33m\]\W\[\e[0m\] \[\e[31m\]$(git_branch)\[\e[0m\]\n\$ '
PROMPT_COMMAND='printf "%%%$((COLUMNS-1))s\\r"'

# ls
export LSCOLORS=Exfxcxdxbxegedabagacad

# Alias
alias ls='ls -GF'
alias la='ls -a'
alias ll='ls -lh'
alias lla='ls -lha'
alias emacs='emacs -nw'
alias ssh='TERM=screen ssh'
alias dk='docker-compose'

# rbenv
if hash rbenv 2> /dev/null; then
  eval "$(rbenv init -)"

  if hash brew 2> /dev/null; then
    export RUBY_CONFIGURE_OPTS="--with-openssl-dir=$(brew --prefix openssl) --with-readline-dir=$(brew --prefix readline)"
  fi
fi

# nodenv
if hash nodenv 2> /dev/null; then
  eval "$(nodenv init -)"
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
if hash pyenv 2> /dev/null; then
  eval "$(pyenv init -)"
fi

# Git
GIT_PS1_SHOWDIRTYSTATE=true

test -e "/usr/local/etc/bash_completion.d/git-completion.bash" && source "/usr/local/etc/bash_completion.d/git-completion.bash"

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

# direnv
if hash direnv 2> /dev/null; then
  eval "$(direnv hook bash)"
fi

# autojump
[ -f /usr/local/etc/profile.d/autojump.sh ] && source /usr/local/etc/profile.d/autojump.sh

# Source homesick
source "$HOME/.homesick/repos/homeshick/homeshick.sh"
source "$HOME/.homesick/repos/homeshick/completions/homeshick-completion.bash"

homeshick --quiet refresh
export PATH="$HOME/.buyma_utils/bin:$PATH"
