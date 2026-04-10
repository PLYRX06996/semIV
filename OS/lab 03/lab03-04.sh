#!/bin/bash
# Using "read -p" combines the echo and read commands into one line.
read -p "Enter first string: " str1
read -p "Enter second string: " str2

if [ ${#str1} -ne ${#str2} ]; then
    echo "both string are of different length -> not anagram."
    exit 0
fi

# This part is already very good. Creating variables is clear.
sorted_str1=$(echo -n "$str1" | tr '[:upper:]' '[:lower:]' | grep -o . | sort | tr -d '\n')
sorted_str2=$(echo -n "$str2" | tr '[:upper:]' '[:lower:]' | grep -o . | sort | tr -d '\n')

if [ "$sorted_str1" = "$sorted_str2" ]; then
  echo "'$str1' and '$str2' are anagrams."
else
  echo "'$str1' and '$str2' are NOT anagrams."
fi
