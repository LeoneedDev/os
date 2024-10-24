#! /bin/csh

set veta = "Ahoj svet"
#set veta = Ahoj svet

@ pocet = 3

while ($pocet > 0)
	echo $pocet $veta

	echo $pocet     $veta

	echo "$pocet     $veta"

	echo '$pocet     $veta'

	echo \$pocet     \$veta

	echo ""

	@ pocet --
end
