#!/bin/bash

F_TO="spravy.$2"
F_ME="spravy.$1"

[ -p "$F_TO" ] ||mkfifo "$F_TO"
[ -p "$F_ME" ] ||mkfifo "$F_ME"

tail -f "$F_ME" &

trap "kill $!;exit 0" INT

while read line;
do
    echo $line >"$F_TO"
done

kill $!
