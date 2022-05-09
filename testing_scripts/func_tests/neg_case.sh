#!/bin/sh
path_app="../../app.exe"
path_to_data="../data"
if [ -n "$1" ]; then
    if [ -e "$path_to_data/$1" ]; then
        in_test="$path_to_data/$1"
        result_test="$path_to_data/out.txt"
        if [ -n "$USE_VALGRIND" ]; then
            valrind --log-file=log.txt -q $path_app "$path_app" < "$in_test" > "$result_test"
        else
            eval "$path_app < $in_test > $result_test"
        fi
        result_exit=$(eval "echo $?")
        if [ "$result_exit" = 0 ]; then
            exit 1
        else
            exit 0
        fi
    else
        echo "Error: file not found."
    fi
else
    echo "Error: enter a file."
fi
