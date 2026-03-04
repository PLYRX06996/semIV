#!/bin/bash
#prime and non prime
echo -n "Enter a number: "
read num

#numbers less than 1 are not prime numbers
if [ $num -le 1 ]; then
	echo "Not Prime"
	exit 0
fi

#assuming number is prime
isPrime=1
#checking condition
for((i=2; i<=num/2; i++))
do
	if [ $((num%i)) -eq 0 ]; then
	isPrime=0
	break
	fi
done

#printing the result
if [ $isPrime -eq 1 ]; then
	echo "Prime"
else
	echo "Not Prime"
fi
