#!/bin/bash
echo "Enter number:"
read num
echo "Enter limit:"
read n
i=1
while [ $i -le $n ]
do
    echo "$num x $i = $((num * i))"
    i=$((i + 1))
done
