#!/bin bash

#veta=ahoj svet
veta="ahoj svet"
pocet=3

while [ $pocet -gt 0 ]; do
	echo $pocet $veta
	echo $pocet	$veta
	echo "$pocet	$veta"
	echo '$pocet	$veta'
	echo \$pocet	\$veta
	echo ""
	((pocet--))
done
