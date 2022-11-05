echo "Shell script to check that the given number is prime or not."

echo "Enter a positive integer: "
read n

if [[ $n -eq 0 || $n -eq 1 ]]; then
    echo "The number $n is NOT prime."
    exit
fi

for ((i = 2; i <= n / 2; i++)); do
    if [[ $(($n % $i)) -eq 0 ]]; then
        echo "The number $n is NOT prime."
        exit
    fi
done

echo "The number $n is prime."
