#!/bin/bash
# William Kelley
# Day of the Week
# ITE315-Scripting

DATE=$(date +%A)

case "$DATE" in
	"Sunday") echo "Sunday Funday"
	;;
	"Monday") echo "Slowest day to exist"
	;;
	"Tuesday") echo "Almost to hump day"
	;;
	"Wednesday") echo "Hump Day"
	;;
	"Thursday") echo "TGIAF"
	;;
	"Friday") echo "TGIF"
	;;
	"Saturday") echo "Have to mow the grass"
	;;
esac
