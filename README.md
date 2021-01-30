This repository is macOS specific.

## Installation

Install brew:

```sh
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Install git:

```sh
brew install git
```

Install homeshick and clone this repository:

```sh
git clone git://github.com/andsens/homeshick.git $HOME/.homesick/repos/homeshick
$HOME/.homesick/repos/homeshick/bin/homeshick clone ershn/dotfiles
```

Inside your `.profile`, add the following:

```sh
export VPN_NAME='xxxx'
export GITLAB_URL='xxxx'
```

Install additional programs:

```sh
brew install diff-so-fancy
```
