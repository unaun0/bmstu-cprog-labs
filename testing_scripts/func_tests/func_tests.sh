#!/bin/sh
counter=0;
numbers="01 02 03 04 05 06 07 08 09 10"
for num in $numbers ; do
    if [ -e "../data/neg_${num}_in.txt" ]; then
        in_test="neg_${num}_in.txt"
        eval "./neg_case.sh $in_test"
        result=$(eval "echo $?")
        if [ -n "$1" ]; then
            if [ "$1" = "show" ]; then
                if [ "$result" = 0 ]; then
                    echo "Test $in_test: pass"
                else
                    echo "Test $in_test: fail"
                    counter=$((counter+1))
                fi
            else
                echo "Error: wrong parameter $1."
            fi
        else
            if [ "$result" = 1 ]; then
                counter=$((counter+1))
            fi
        fi
    fi
    if [ -e "../data/pos_${num}_in.txt" ]; then
        in_test="pos_${num}_in.txt"
        out_test="pos_${num}_out.txt"
        eval "./pos_case.sh $in_test $out_test"
        result=$(eval "echo $?")
        if [ -n "$1" ]; then
            if [ "$1" = "show" ]; then
                if [ "$result" = 0 ]; then
                    echo "Test $in_test: pass"
                else
                    counter=$((counter+1))
                    echo "Test $in_test: fail"
                fi
            else
                echo "Error: wrong parameter $1."
            fi
        else
            if [ "$result" = 1 ]; then
                counter=$((counter+1))
            fi
        fi
    fi
done
echo "Failed Tests: $counter"
