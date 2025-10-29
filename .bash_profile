dotfiles()
{
	git --git-dir="$HOME/.dotfiles.git" --work-tree="$HOME" "$@"
}

_git_fzf_status()
{
	local filenames
	filenames=$(command git status -s | fzf --nth 2 --accept-nth 2 --multi --bind 'left:toggle,right:toggle-all')
	local exit_code=$?

	if [[ $exit_code -ne 0 ]]; then
		return $exit_code
	fi

	echo git "$@" -- $filenames
	command git "$@" -- $filenames
}

git()
{
	if [[ $# -eq 0 ]]; then
		command git
		return
	fi

	local subcommand=$1
	shift

	case "$subcommand" in
	ds)
		command git diff "$@" -- '*.cs'
		;;
	fck)
		_git_fzf_status checkout "$@"
		;;
	fadd)
		_git_fzf_status add "$@"
		;;
	*)
		command git "$subcommand" "$@"
		;;
	esac
}
