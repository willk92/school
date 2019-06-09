#!/bin/bash
# Convert string to ascii characters

STRING="$1"

for i in $(seq 0 ${#STRING})
    	do array[$i]=${STRING:$i:1}
done

for each in "${array[@]}"
do
	printf "%d\n" \'"$each"
done
