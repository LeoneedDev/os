#!/bin/bash

for f in [A-Z]*; do
	echo "$f" | tr 'A-Z' 'a-z'
	mv -i "$f" "$(echo "$f" | tr A-Z a-z)"
	#mv -i "$f" "`echo "$f" | tr A-Z a-z`"
done

