#!/bin/sh
mask="[-+]?[0-9]"
first_out="$(eval grep -oE  "$mask" "$1")"
second_out="$(eval grep -oE  "$mask" "$2")"
if [ "$first_out" = "$second_out" ]; then
    exit 0
else
    exit 1
fi


