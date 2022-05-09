#!/bin/sh
path_app="../../app.exe"
path_to_data="../data"
if [ -n "$1" ]; then
    if [ -n "$2" ]; then
        if [ -e "$path_to_data/$1" ]; then
            if [ -e "$path_to_data/$2" ]; then
                in_test="$path_to_data/$1"
                out_test="$path_to_data/$2"
                result_test="$path_to_data/out.txt"
                if [ -n "$USE_VALGRIND" ]; then
                    valrind --log-file=log.txt -q $path_app "$path_app" < "$in_test" > "$result_test"
                else
                    eval "$path_app < $in_test > $result_test"
                fi
                eval "./comparator.sh $out_test $result_test"
                result_exit=$(eval "echo $?")
                if [ "$result_exit" = 0 ]; then
                    exit 0
                else
                    exit 1
                fi
            else
                echo "Error: second file not found."
            fi
        else
            echo "Error: first file not found."
        fi
    else
        echo "Error: enter the second file."
    fi
else
    echo "Error: enter the first file."
fi
