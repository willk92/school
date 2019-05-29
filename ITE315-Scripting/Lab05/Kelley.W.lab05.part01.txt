#!/bin/bash
#File:		lab05.part01.sh
#Author:	wkelley2@my.athens.edu
#Purpose:	Average a set of numbers
#
#!/bin/bash
SCORE=0
AVERAGE=0
SUM=0
NUM=0

while true; do
	echo -n "Enter a test score (0-100) or 'q' to quit: ";
	read SCORE
	if (( SCORE < 0 )) || (( SCORE > 100 ));
	then
		echo "Let's try that again! Scores must be between 0 and 100"
	elif [ $SCORE == "q" ]; then
		echo "Quitting."
		echo "The average was $AVERAGE" >> lab05.part02.txt
		break
	else
		echo "The score entered was $SCORE" >> lab05.part02.txt
		SUM=$[$SUM+$SCORE]
		NUM=$[$NUM+1]
		AVERAGE=$[$SUM/$NUM]
	fi
done
