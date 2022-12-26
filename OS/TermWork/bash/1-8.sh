echo "Shell script to find and display the sum of the following series 1 + 2! + 3! + 4! + 5! + 6! + ... + N!, where N is user entered number."

echo "Enter a positive integer:"
read n
let sum=0
let f=1

for ((num = 1; num <= $n; num++)); do
    f=$(($f * $num))
    sum=$(($sum + $f))
done

echo "The solution for the given series when n = $n is: $sum"
