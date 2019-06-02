#!/bin/bash
# Find the phone number for a specific person/place
# William Kelley
# Assn01Part01.sh
IFS=","
while read p1 p2 p3
do
	if ($p1 = $1);
	then
		echo "$1's phone number is $p3"
	fi
done < phone.csv
