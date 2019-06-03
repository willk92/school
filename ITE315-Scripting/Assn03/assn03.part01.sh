#!/bin/bash
# William Kelley
# Larger of Two Numbers
# ITE315-Scripting (Assn03 Part01)

if (( $1 > $2 ));
	then
	echo "$1 is larger."
else
	echo "$2 is larger."
fi
