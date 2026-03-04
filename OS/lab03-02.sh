#!/bin/sh
echo "calculating N / (2^M)."
echo -n "Enter N:"
read N
echo -n "Enter M:"
read M

# Previous method (integer bit-shifting):
# ((shifted_right = N >> M))
# echo "by right shifting N, M times, it becomes $shifted_right"

# Current method (floating-point division):
result=$(echo "scale=4; $N / (2^$M)" | bc)
echo "The result of N / (2^M) is: $result"
