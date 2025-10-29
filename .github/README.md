# Installation steps

Clone the repository and checkout the files.

```sh
cd
git clone --bare git@github.com:ershn/dotfiles.git .dotfiles.git
dotfiles() { git --git-dir="$HOME/.dotfiles.git" --work-tree="$HOME" "$@"; }
dotfiles config --local status.showUntrackedFiles no
dotfiles checkout
```

Put machine specific git configuration like username and email in `~/.gitconfig_local`.
