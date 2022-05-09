#!/bin/sh
./build_gcov.sh
./code_run.sh
gcov ./main.c

