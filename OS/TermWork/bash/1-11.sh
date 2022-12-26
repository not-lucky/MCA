echo "Shell script to find largest and smallest elements of a given array."

echo "Enter size of array: "
read n

echo "Enter the elements:"
for ((i = 0; i < n; i++)); do
    read arr[$i]
done

smallest=${arr[0]}
largest=${arr[0]}
for ((i = 0; i < n; i++)); do
    if [[ ${arr[$i]} -lt $smallest ]]; then
        smallest=${arr[$i]}
    fi
    if [[ ${arr[$i]} -gt $largest ]]; then
        largest=${arr[$i]}
    fi
done

echo "Smallest number in the array is: $smallest"
echo "Largest number in the array is: $largest"
