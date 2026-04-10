#!/bin/bash

# Function to process a string into its "canonical" (sorted) form
canonical_form() {
  # Read from stdin, convert to lowercase, split into chars, sort, and rejoin
  tr '[:upper:]' '[:lower:]' | grep -o . | sort | tr -d '\n'
}

echo -n "Enter the first string: "
read str1

echo -n "Enter the second string: "
read str2

# An optimization: if lengths are different, they can't be anagrams.
if [ ${#str1} -ne ${#str2} ]; then
  echo "The strings have different lengths, so they are not anagrams."
  exit 0
fi

# Pass the strings to the function and get their canonical forms
sorted_str1=$(echo -n "$str1" | canonical_form)
sorted_str2=$(echo -n "$str2" | canonical_form)

# Compare the final sorted strings
if [ "$sorted_str1" = "$sorted_str2" ]; then
  echo "'$str1' and '$str2' are anagrams."
else
  echo "'$str1' and '$str2' are NOT anagrams."
fi
