#!/bin/bash

help="Help: $0 arg1 arg2 arg3 ... argN"

if [ "$#" == "0" ]; then
    echo "$help"
    exit 1
fi

unset debug
echo "Argumenty: $@"
#echo $1 ; shift ; echo $1

while (( "$#" )); do
    case "$1" in
        -d|-D)
            debug=''
            shift
            break
            ;;
        abc|cba)
            echo "pokracujem dalej"
            ;;
        -h)
            echo "$help"
            exit 0
            ;;
        -*)
            echo "Neznamy prepinac \"$1\""
            exit 1
            ;;
        *)
            break
            ;;
    esac
    shift
done
if [[ -v debug ]]; then echo "Dalsie argumenty: $@"; fi
