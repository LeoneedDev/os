#! /bin/bash

ls -l

echo ""

for f in $(ls -l | head -3); do
	echo $f
done


echo ""

IFS='
'
for f in $(ls -l | head -3); do
	echo $f
done
