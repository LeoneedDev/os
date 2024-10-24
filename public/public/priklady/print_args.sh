#!/bin/bash

echo "arg \$0: '$0'"

i=1
while (($#))
do
	echo "arg \$$((i++)): '$1'"
	shift
done
