
declare DIR="quick-refs"

STATUS_OUT=$(git -C "$DIR" status --porcelain)

declare -i UNTRACKED_COUNT=$( echo "$STATUS_OUT" | grep -c "^??" )
# alternaive:
# echo "$da" | awk ' /^\?\?/ { count++ } END { print count } '

declare -a UNTRACKED=$(echo "$STATUS_OUT" | awk ' /^\?\?/ { print $2 } ')



stageUF () {
    while read -r line
    do
	git -C "$DIR" add "$line"
    done <<< "${UNTRACKED}"
}
 	
			     
stageAUF () {
    echo "$STATUS_OUT" \
	| awk -v dir=$DIR"/" ' /^\?\?/ { system( "cat " dir $2 ) } '
}
