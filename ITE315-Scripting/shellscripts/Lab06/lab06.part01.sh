#bin/bash
#File:		lab06.part01.sh
#Author:	wkelley2@my.athens.edu
#Purpose:	Average a set of numbers
#
#!/bin/bash
SCORE=0
AVERAGE=0
SUM=0
NUM=0

while read -r SCORE; do
	if (( SCORE < 0 )) || (( SCORE > 100 ));
	then
		echo "File contains bad input at Line $NUM: $SCORE" >&2
	elif [ $SCORE == "q" ]; then
		echo "Quitting." >&2
		break
	else
		echo "Score: $SCORE" >&2
		SUM=$[$SUM+$SCORE]
		NUM=$[$NUM+1]
		AVERAGE=$[$SUM/$NUM]
	fi
done
echo "The Average of $NUM tests was $AVERAGE" >&lab06.err.txt
echo $AVERAGE
