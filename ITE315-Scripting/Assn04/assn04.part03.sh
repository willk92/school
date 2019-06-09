#!/bin/bash
# Decifer week number from entry or print out current week number
# Source: https://stackoverflow.com/questions/3237882/get-week-of-year-from-day-of-year

if [ "$1" != "" ]; then
	/bin/date -d "$1" +%V
else
	/bin/date +%V
fi
