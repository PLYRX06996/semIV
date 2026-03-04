#!/bin/bash
echo "Enter a number:"
read n
if [ $n -lt 0 ]; then
    echo "Invalid input! Factorial not defined for negative numbers."
    exit 0
fi

fact=1
while [ $n -gt 0 ]
do
    fact=$((fact * n))
    n=$((n - 1))
done
echo "Factorial = $fact"
