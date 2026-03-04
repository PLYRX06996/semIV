#!/bin/bash
a=$1
b=$2
c=$3

if [ $a -gt $b ] && [ $a -gt $c ]; then
    echo "$a is the biggest"
elif [ $b -gt $c ]; then
    echo "$b is the biggest"
else
    echo "$c is the biggest"
fi
