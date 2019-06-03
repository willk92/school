#!/bin/bash
# William Kelley
# Assignment 02 Part 01 - Switch Statement for Command Line Statements
# ITE315-Scripting

echo 	"Welcome to Will's Command Line Tool"

echo 	"-----------------------------------"
echo 	"(a) Display a list of files and directories in the current directory
(b) Display a long list of the contents of the current directory
(c) Display a list of the last n messages in /var/log/messages,
	prompting for the value of n
(d) Display the contents of this script
(e) Display the contents of this script in reverse
(f) Exit the script
"

INPUT='a'

while [ $INPUT == '[a-e]' ];
do
	echo "Hello world"
#	case "$INPUT" in
#		"a") echo "Im an a"
#		;;
#	esac
done


