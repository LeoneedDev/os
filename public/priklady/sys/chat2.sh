#!/bin/bash

F_TO="spravy.txt.$2"
F_ME="spravy.txt.$1"

touch "$F_TO" "$F_ME"
tail -n0 -f "$F_ME" &

trap "kill $!;exit 0" INT

while read line;
do
    echo $line >>"$F_TO"
done

kill $!
