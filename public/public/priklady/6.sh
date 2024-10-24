#! /bin/bash

zoznam=(jeden dva tri styri pat "sest cele sedem")

echo $zoznam
echo ${zoznam[2]}
echo ${#zoznam[2]}
echo ${#zoznam[5]}
echo ${#zoznam[@]}

echo ${zoznam[@]:2:4}

zoznam1=(${zoznam[@]:0:6} sedem ${zoznam[$((7-${#zoznam[@]}))]})

echo ""

#zoznam=(${zoznam[@]} osem)
zoznam2=(${zoznam[@]} osem)
echo ${#zoznam2[@]}
echo ${zoznam2[@]}

zoznam2=("${zoznam[@]}" osem)
echo ${#zoznam2[@]}
echo ${zoznam2[@]}

for prvok in "${zoznam[@]}"; do 
	echo "$prvok"
done

echo ""

