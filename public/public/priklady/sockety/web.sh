#!/usr/bin/env bash
base=$(pwd)
#PRECITAME SI HTTP REQUEST (napr. "GET /subor.txt HTTP/1.0")
read request
#PRECITAME A ZAHODIME HLAVICKY
#while /bin/true; do
#echo "citam cestu"
#read header
#[ "$header" == $'\r' ] && break;
#done
#VYPARSUJEME URL Z REQUESTU (dalo by sa aj cez awk alebo sed)
#VID https://www.tldp.org/LDP/abs/html/string-manipulation.html
#ODSTRIHNEME PREFIX
url="${request#GET }"
#ODSTRIHNEME SUFIX
url="${url% HTTP/*}"
#VYSKLADAME SI CESTU V SUBOROVOM SYSTEME
filename="$base$url"
echo "cesta v suborovom systeme: $filename" >> web.log
#AK EXISTUJE SUBOR, TAK HO POSLEME DO WEB KLIENTA AJ SO SPRAVNYMI HLAVICKAMI
if [ -f "$filename" ]; then
    echo -e "HTTP/1.1 200 OK\r"
    echo -e "Content-Type: `/usr/bin/file -bi \"$filename\"`\r"
    echo -e "\r"
    cat "$filename"
    echo -e "\r"
else
    echo -e "HTTP/1.1 404 Not Found\r"
    echo -e "Content-Type: text/html\r"
    echo -e "\r"
    echo -e "404 Not Found\r"
    echo -e "Not Found

    The requested resource was not found\r"

echo -e "\r"
fi
