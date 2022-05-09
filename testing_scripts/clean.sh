#!/bin/sh
temp_file_ext=".txt .exe .o .out .dSYM .tmp .gcov .gcda .gcno"
for ext in $temp_file_ext; do
    find  . -name "*$ext" ! \( -name "pos_*??_??*.txt" -o -name "neg_*??_??*.txt" \)  -delete
done
