#!/bin/bash

if [ $# -ne 2 ]
	then
		echo "Usage: spell_check dictionary filename" 1>&2
		echo "dictionary: list of correct spellings" 1>&2
		echo "filename: file to be checked" 1>&2
		exit 1
fi

if [ ! -r "$1" ]
	then
		echo "spell_check: $1 is not readable" 1>&2
		exit 1
fi
if [ ! -r "$2" ]
	then
		echo "spell_check: $2 is not readable" 1>&2
		exit 1
fi
aspell list < "$2"
while read line
do
	if ! grep "^$line$" "$1" > /dev/null
		then
		echo $line
	fi
done
