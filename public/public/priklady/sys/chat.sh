#!/bin/bash

F="spravy.txt"

touch "$F"
tail -n0 -f "$F" &

trap "kill $!;exit 0" INT

while read line;
do
    echo $line >>"$F"
done

kill $!
