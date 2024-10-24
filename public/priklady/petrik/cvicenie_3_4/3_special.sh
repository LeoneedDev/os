#!/bin/bash

list=( \"\`a\"  '"a d"' '"a|b"' '"a\nb"' )

echo "${list[@]}"

echo ""
echo ""

for x in ${list[@]}
do
        echo $x
        echo '$x'
done

echo ""

for x in ${list}
do
        echo "${x}"
done

echo ""

for x in ${list[@]}
do
	echo "${x}"
done

echo ""
IFS="|"
for x in ${list[@]}
do
        echo "${x}"
done

echo ""
IFS=" "
for x in ${list[@]}
do
        echo "${x}"
done

echo ""
