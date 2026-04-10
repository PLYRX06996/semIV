#!/bin/bash
read -p "Enter three number:" n1 n2 n3
echo "number in sorted:"
printf "%s\n" $n1 $n2 $n3 | sort -n

