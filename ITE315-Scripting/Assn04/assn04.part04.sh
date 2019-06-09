#!/bin/bash
# Convert all files of one file type to another

if [  "$2" == "" ]; then
	echo "Need to submit two file types"
else
	files=($(ls -d *$1))
	for each in "${files[@]}"
	do
		filename=$each
		file_prefix="${filename%.*}"
		echo "Converting file $file_prefix$1 to $file_prefix$2"
		mv "$file_prefix$1" "$file_prefix$2"
	done
fi
