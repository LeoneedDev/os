#! /bin/bash

words=$(grep -wEo "\<[a-zA-Z]{1,}\>" /public/zaciatocnik.txt | sort | uniq)
max=0
max_w=""
for w in $words;
do
	len=${#w}
	if (($len > $max));
	then
		max=$len
		max_w=$w
	fi	
	
done
echo $max
echo $max_w
