#!/bin/bash
echo -n "Enter a string:"
#for cheching character at any given position p
#charAt="${str:p:1}"
read str
firstChar="${str:0:1}"
lastChar="${str: -1:1}"

if [ "$firstChar" = "A" ]
then
echo "string starts with A."
else
echo "string doesn't starts with A"
fi

if [ "$lastChar" = "Z" ]
then
echo ", and string ends with Z."
else
echo ", and string doesn't ends with Z."
fi
