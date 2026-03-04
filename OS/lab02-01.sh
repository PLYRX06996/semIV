#!/bin/bash
a=5
b=6
echo "$((a+b))" #11
echo "$((a-b))" #-1
echo "$((a*b))" #30
echo "$((a/b))" #0
echo "$((a%b))" #5
echo "$((2**3))" #2*2*2
((a++)) #a=a+1
echo $a
((a+=3))
echo $a
