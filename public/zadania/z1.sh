#! /bin/bash
#
# Meno: <meno>
# Kruzok: <kruzok>
# Datum: <datum>
# Zadanie: zadanie01
#
# Text zadania:
#
# V zadanych adresaroch uvedenych ako argumenty najdite adresare, v ktorych
# je suma poctov riadkov vsetkych obycajnych suborov najvacsia. Prehladavajte
# vsetky zadane adresare a aj ich podadresare. Sumy pocitajte len pre subory,
# ktore su priamo v adresari.
# Ak nebude uvedena ako argument ziadna cesta, prehladava sa aktualny pracovny
# adresar (teda .).
# Ak bude skript spusteny s prepinacom -w, najde adresare, v ktorych je suma
# poctov slov obycajnych suborov najvacsia.
# Ak bude skript spusteny s prepinacom -c, najde adresare, v ktorych je suma
# poctov znakov obycajnych suborov najvacsia.
#
# Syntax:
# zadanie.sh [-h] [-c] [-w] [cesta ...]
#
# Vystup ma tvar:
# Output: '<cesta k najdenemu adresaru> <celkovy pocet riadkov>'
#
# Priklad vystupu (zadanie1.sh /public/testovaci_adresar /public/ucebnove):
# Output: '/public/testovaci_adresar/testdir1 30'
# Output: '/public/testovaci_adresar/testdir2 30'
# Output: '/public/ucebnove/historia 30'
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
# Debug: vypis .
#
# Poznamky: (sem vlozte pripadne poznamky k vypracovanemu zadaniu)
#
# Riesenie:
