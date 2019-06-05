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
echo "The above doesn't work and not sure how to make it work"
for (( x=1;x<10;x++ ))
do
	echo −n "Roll #$x: "
	echo −n $(( $RANDOM %6 + 1 ))
	echo $(( $RANDOM %6 + 1 ))
done
