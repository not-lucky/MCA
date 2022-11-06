echo "Shell script to find sum of all elements of a given array."

echo "Enter the size of array: "
read n

echo "Enter the elements:"
for ((i = 0; i < n; i++)); do
    read arr[$i]
done

sum=0
for ((i = 0; i < n; i++)); do
	sum=$(($sum + ${arr[$i]}))
done

echo "Sum of all elements in the array is: $sum"