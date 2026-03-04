#!/bin/sh
echo -n "Enter a number:"
read num
if [ $num -le 20 ] && [ $num -ge 10 ]
 then
echo "The entered number is in range"
else
echo "The entered number is out of range"
fi
