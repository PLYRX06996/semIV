#!/bin/bash
echo "Enter date (dd-mm-yyyy):"
read date
d=${date:0:2}
m=${date:3:2}
y=${date:6:4}

if [ $d -ge 1 ] && [ $d -le 31 ] && [ $m -ge 1 ] && [ $m -le 12 ] && [ $y -ge 1000 ]; then
    echo "Valid Date"
else
    echo "Invalid Date"
fi
