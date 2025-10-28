# Installation

```sh
cd
git clone --bare git@github.com:ershn/dotfiles.git .dotfiles.git
dotfiles() { git --git-dir="$HOME/.dotfiles.git" --work-tree="$HOME" "$@"; }
dotfiles config --local status.showUntrackedFiles no
dotfiles checkout
```
