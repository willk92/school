#bin/bash
#File:		hardlinks.sh
#Author:	wkelley2@my.athens.edu
#Purpose:	Hardlinks
#
#!/bin/bash
if [ $# -eq 0 -o $# -gt 2 ]; then
	echo "Usage: hardlinks.sh file [directory]" 1>&2
	exit 1
fi
if [ -d "$1"]; then
	echo "First argument cannot be a directory." 1>&2
	echo "Usage: hardlinks.sh file [directory]" 1>&2
	exit 1
else
	file="$1"
fi
if [ $# -eq 1 ]; then
	directory="."
	elif [ -d "$2" ]; then
		directory="$2"
	else
		echo "Optional second argmuent must be a directory." 1>&2
		echo "Usage: hardlinks.sh file [directory]" 1>&2
		exit 1
fi
# Check to see if the file exists and is an ordinary file
if [ ! -f "$file" ]; then
	echo "lnks: $file not found or is a special file" 1>&2
	exit 1
fi
set -- $(ls -l "$file")
linkcnt=$2
if [ "$linkcnt" -eq 1 ]; then
	echo "lnks: no other hard links $file" 1>&2
	exit 0
fi
# Get the inode of the given file
set -- $(ls -i "$file")

inode=$1
# Find and print the files with that inode number
echo "lnks: using find to search for links . . ." 1>&2
find "$directory" -xdev -inum $inode -print
