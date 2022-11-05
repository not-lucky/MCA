echo "Shell script to find the factorial of a given number."

echo "Enter a postive integer: "
read n
let f=1

for ((i = 2; i <= n; i++)); do
    f=$(($f * $i))
done

echo "The factorial of $n is $f."
