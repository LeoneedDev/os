#! /bin/bash
#
# Meno: <meno>
# Kruzok: <kruzok>
# Datum: <datum>
# Zadanie: zadanie05
#
# Text zadania:
#
# Zistite, ktori pouzivatelia sa prihlasuju na server OS z viac ako 10tich roznych
# strojov za poslednu dobu (odkedy system zaznamenava tieto informacie).
# Ak bude skript spusteny s prepinacom -n <pocet>, zistite, ktori pouzivatelia
# sa hlasia z viac ako <pocet> strojov.
# Ignorujte prihlasenia, pre ktore nepoznate IP adresu stroja.
# Pomocka: pouzite prikaz last a udaje zo suboru /public/samples/wtmp.2020
#
# Syntax:
# zadanie.sh [-h][-n <pocet>]
#
# Format vypisu bude nasledovny:
# Output: '<meno pouzivatela> <pocet roznych strojov, z ktorych sa hlasil>'
#
# Priklad vystupu:
# Output: 'login1 25'
# Output: 'login2 24'
# Output: 'login3 23'
#
#
# Program musi osetrovat pocet a spravnost argumentov. Program musi mat help,
# ktory sa vypise pri zadani argumentu -h a ma tvar:
# Meno programu (C) meno autora
#
# Usage: <meno_programu> <arg1> <arg2> ...
# <arg1>: xxxxxx
# <arg2>: yyyyy
#
# Parametre uvedene v <> treba nahradit skutocnymi hodnotami.
# Ked ma skript prehladavat adresare, tak vzdy treba prehladat vsetky zadane
# adresare a vsetky ich podadresare do hlbky.
# Pri hladani maxim alebo minim treba vzdy najst maximum (minimum) vo vsetkych
# zadanych adresaroch (suboroch) spolu. Ked viacero suborov (adresarov, ...)
# splna maximum (minimum), treba vypisat vsetky.
#
# Korektny vystup programu musi ist na standardny vystup (stdout).
# Chybovy vystup programu by mal ist na chybovy vystup (stderr).
# Chybovy vystup musi mat tvar (vratane apostrofov):
# Error: 'adresar, subor, ... pri ktorom nastala chyba': popis chyby ...
# Ak program pouziva nejake pomocne vypisy, musia mat tvar:
# Debug: vypis ...
#
# Poznamky: (sem vlozte pripadne poznamky k vypracovanemu zadaniu)
#
# Riesenie:
