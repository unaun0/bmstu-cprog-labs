#!/bin/sh
gcc -std=c99 -c -Wall -Werror -O2 -Wpedantic -Wextra main.c 
gcc -o app.exe main.o
