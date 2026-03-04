#!/bin/bash

echo -n  "Enter marks of 5 subjects:"
read m1 m2 m3 m4 m5

total=$((m1 + m2 + m3 + m4 + m5))
per=$((total / 5))

echo "Percentage = $per"

if [ $per -gt 95 ]; then
    echo "Grade: A+"
elif [ $per -gt 85 ]; then
    echo "Grade: A"
elif [ $per -gt 75 ]; then
    echo "Grade: B+"
elif [ $per -gt 65 ]; then
    echo "Grade: B"
elif [ $per -gt 55 ]; then
    echo "Grade: C"
else
    echo "Grade: D"
fi
