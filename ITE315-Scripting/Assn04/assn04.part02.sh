#!/bin/bash
# Convert string to ascii characters
# Sources: Lots of stack overflow for help
# Had trouble converting to character array and then converting each
# Ran into an issue where it prints the EOL delimiter

STRING="$1"

for i in $(seq 0 ${#STRING})
    	do array[$i]=${STRING:$i:1}
done

for each in "${array[@]}"
do
	printf "%d\n" \'"$each"
done
