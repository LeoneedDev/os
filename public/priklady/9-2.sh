#!/bin/bash 
echo "PID: $$"
if [ "$1" == "druhy raz" ]; then
    echo "a = $a"
    echo "b = $b"
    exit 2
elif [ "$1" == "treti raz" ]; then
    if [ -u a ]; then
        exit 1
    fi
    echo "a = $a"
    echo "b = $b"
    exit 3
elif [ "$1" == "stvrty raz" ]; then
    echo "$1 zo source"
    echo "a = $a"
    echo "b = $b"
    echo '$#' = $#
    echo "\$1 = $1"
elif [ "$1" == "piaty raz" ]; then
    echo "$1 z exec"
    echo "a = $a"
    echo "b = $b"
    exit 5
fi

if [ $# -ne 0 ]; then
    echo "Spustam piaty raz"
    exec $0 "piaty raz"
    echo "Debug: piaty raz, status = $?"
    echo koniec 
    exit 0
fi

a=premenna_shellu
export b=premenna_prostredia
#setenv b premenna_prostredia

echo "Spustam druhy raz"
$0 "druhy raz"
echo "Debug: druhy raz, status = $?"

echo "Spustam treti raz"
$0 "treti raz"
echo "Debug: treti raz, status = $?"

echo "Spustam stvrty raz"
#source $0 "stvrty raz"
#source $0 
set "stvrty raz"
. $0
echo "Debug: stvrty raz, status = $?"

