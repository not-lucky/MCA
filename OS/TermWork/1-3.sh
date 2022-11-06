echo "Shell script to check that a number that is taken as input is an even number or odd number."

echo "Enter a positive integer: "
read n

if [[ $((n % 2)) -eq 0 ]]; then
    echo "The number $n is even."
else
    echo "The number $n is odd."
fi
