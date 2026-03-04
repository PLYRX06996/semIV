#!/bin/sh
# take two numbers from the user
echo "Enter two numbers: "
read a b
# check
if [ $a == $b ]
then
 echo "Numbers are equal."
else
 echo "Numbers are not equal."
fi
echo "End of script."
