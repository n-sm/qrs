# esto solo hace git status, hay que seguirlo.
find -maxdepth 2 -name ".git" \
    | awk -v dir="quick-refs" \
	  ' { system ( "git -C " \
gensub(/\/.git/, "", "g" ) " status  --porcelain") } '
