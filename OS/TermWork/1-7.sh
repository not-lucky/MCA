echo "Shell script to display all prime numbers in between 1 to user inputed number."

echo "Enter a positive integer: "
read n

echo "The prime numbers between 1 and $n are as follows: "
for ((num = 2; num <= n; num++)); do
    let prime=1
    for ((i = 2; i <= num / 2; i++)); do
        if [[ $(($num % $i)) -eq 0 ]]; then
            prime=0
            break
        fi
    done
    if [[ $prime -eq 1 ]]; then
        echo $num
    fi
done
