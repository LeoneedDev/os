#! /bin/bash
#
# Meno: <meno>
# Kruzok: <kruzok>
# Datum: <datum>
# Zadanie: zadanie03
#
# Text zadania:
#
# Vypiste vsetkych pouzivatelov, ktori neboli za poslednu dobu (odkedy system
# zaznamenava tieto informacie) prihlaseni. Ignorujte pouzivatelov, ktori
# nemaju povolene prihlasovanie.
# Ak bude skript spusteny s prepinacom -g <group>, vypise len pouzivatelov,
# ktori neboli za poslednu dobu prihlaseni a patria do skupiny <group>, ktora
# je zadana ako cislo.
# Pomocka: pouzite prikaz last a informacie zo suborov
# /public/samples/wtmp.2020 /public/samples/passwd.2020.
#
# Syntax:
# zadanie.sh [-h] [-g <group>]
#
# Format vypisu bude nasledovny:
# Output: '<login_name> <group>'
#
# Priklad vystupu:
# Output: 'cernicka 520'
# Output: 'chudik 520'
#
#
# Program musi osetrovat pocet a spravnost argumentov. Program musi mat help,
# ktory sa vypise pri zadani argumentu -h a ma tvar:
# Meno programu (C) meno autora
#
# Usage: <meno_programu> <arg1> <arg2> ...
#    <arg1>: xxxxxx
#    <arg2>: yyyyy
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
