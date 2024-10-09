#!/bin/bash

for d in /public/prednasky /public/ucebnove /public/priklady
do
	echo -n $d
	ls $d | wc -l
done

#podobne ako v C
#     init  podm  vyraz
for (( i=0 ; i<5 ; i++ ))
do
    echo "opakovanie $i"
done
