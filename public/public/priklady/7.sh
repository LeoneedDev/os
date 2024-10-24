#! /bin/bash

#cesta="/public/ucebnove/seminar _1/vim.txt"
cesta=/public/ucebnove/seminar_1/vim.txt

echo $(dirname $cesta)
echo $(basename $cesta)
echo $(dirname $(dirname $cesta))
echo $(basename $(dirname $cesta))

