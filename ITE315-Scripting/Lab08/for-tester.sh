#!/bin/bash
#William Kelley
#Lab08-For Loops(for-tester.sh)
#
echo "Cartoon character names"
for name in daffy, bugs, yosemite, foghorn
do
	echo $name
done
#This isn't doing anything
for fname in *
do
	if [ -d "$fname" ]
	then
		echo $fname
	fi
done
