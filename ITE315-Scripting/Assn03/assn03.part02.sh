#!/bin/bash
# William Kelley
# Print whether the file is executable, writeable, and wehther the file is greater than 1MB in size
# ITE315-Scripting

FILE="$1"

[ $# -eq 0 ] && exit 1

if [ -w "$FILE" ]
then
	echo "Write permission is granted on $FILE"
else
	echo "Write permission is NOT granted on $FILE"
fi
if [ -r "$FILE" ]
then
        echo "Read permission is granted on $FILE"
else
        echo "Read permission is NOT granted on $FILE"
fi
if [ -x "$FILE" ]
then
        echo "Execute permission is granted on $FILE"
else
        echo "Execute permission is NOT granted on $FILE"
fi
FILESIZE=$(stat --format=%s "$FILE")
if [ $FILESIZE > 1000000 ]
then
	echo "$FILESIZE : File size is larger than 1MB"
else
	echo "File size is NOT larger than 1MB"
fi
