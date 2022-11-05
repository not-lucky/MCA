echo "Shell script to check that a number that is taken as input is divisible by 3 or not."

echo "Enter a positive number: "
read n

if [[ $(($n % 3)) -eq 0 ]]; then
    echo "The number $n is divisible by 3."
else
    echo "The number $n is NOT divisible by 3."
fi
