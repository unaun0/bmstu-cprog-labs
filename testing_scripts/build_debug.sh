#!/bin/sh
gcc -std=c99 -c --debug -O0 -Wall -Werror -Wpedantic -Wextra main.c
gcc -o app.exe main.o
