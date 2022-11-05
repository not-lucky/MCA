echo "Shell script to find and display the sum of the following series 1 + 2! + 3! + 4! + 5! + 6! + ... + N!, where N is user inputed number."

echo "Enter a postive integer:"
read n
let sum=0

for ((num = 1; num <= $n; num++)); do
    let f=1
    for ((i = 2; i <= num; i++)); do
        f=$(($f * $i))
    done
    sum=$(($sum + $f))
done

echo "The solution for the given series when n = $n is: $sum"
