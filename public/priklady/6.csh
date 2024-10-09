#! /bin/csh

set zoznam = (jeden dva tri styri pat "sest cele sedem")

echo $zoznam[2]
echo $#zoznam

echo ""

#set zoznam = ($zoznam osem)
set zoznam = ($zoznam:q osem)

#set zoznam = ($zoznam[1-6]:q sedem $zoznam[7-$#zoznam]:q)
set zoznam = ($zoznam[-6]:q sedem $zoznam[7-]:q)

set zoznam2 = ($zoznam:q)

while ($#zoznam > 0)

	echo "$zoznam[1]"

	shift zoznam

end

echo ""

@ i = $#zoznam2

while ($i > 0)

	echo "$zoznam2[$i]"

	@ i --

end
