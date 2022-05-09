#!/bin/sh
gcc -std=c99 --debug -O0 --coverage -Wall -Werror -Wpedantic -Wextra -c main.c
gcc -o app.exe main.o --coverage

