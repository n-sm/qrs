# This script expects the switch -c and a company name.
# is also allowed.
#--help (-h)

#shopt -s -o nounset
declare -rx SCRIPT=${0##*/}
declare -r OPTSTRING=”hc:”
declare SWITCH
declare COMPANY

# Make sure there is at least one parameter
if [ $# -eq 0 ] ; then
    printf “%s\n” “Type --help for help.”
    exit 192
fi
# Examine individual options

while getopts “$OPTSTRING” SWITCH ; do
    case $SWITCH in
        h) printf “%s\n” “usage: $SCRIPT [-h] -c companyid”
            exit 0
            ;;
        c) COMPANY=”$OPTARG”
            ;;
        \?) exit 192
            ;;
        *) printf “$SCRIPT:$LINENO: %s\n” “script error: unhandled argument”
            exit 192
            ;;
    esac
done

printf “$SCRIPT: %s\n” “Processing files for $COMPANY...”
echo hl
