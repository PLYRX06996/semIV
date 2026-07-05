echo "Enter a, b, c:"
read a b c
# Calculate discriminant
d=$((b*b - 4*a*c))
if [ $d -lt 0 ]; then
    echo "Roots are imaginary."
else
    # Scale=2 ensures 2 decimal places in bc
    root1=$(echo "scale=2; (-$b + sqrt($d)) / (2*$a)" | bc)
    root2=$(echo "scale=2; (-$b - sqrt($d)) / (2*$a)" | bc)
    echo "Roots are $root1 and $root2"
fi