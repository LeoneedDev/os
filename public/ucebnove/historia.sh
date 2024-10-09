#!/bin/bash

grezo=$(cat grezo02102024.history | cut -d " " -f5- | sort | uniq)
echo $grezo
#for d in /public/prednasky /public/ucebnove /public/priklady
#do
#	echo -n $d
#	ls $d | wc -l
#done
