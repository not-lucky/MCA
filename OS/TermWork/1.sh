echo "Shell Script to sort an array (whose elements are numbers)"

echo "Enter length of array to sort:"
read n

echo "Enter elements of the array:"
for ((i=0;i<n;i++)); do
    read arr[$i]
done

for((i=0;i<n-1;i++)); do
    small=${arr[$i]}
    index=$i

    for((j=i+1;j<n;j++)); do
        if [[ ${arr[$j]} -lt small ]]; then
            small=${arr[$j]}
            index=$j
        fi
    done
    temp=${arr[$i]}
    arr[$i]=$small
    arr[$index]=$temp
done

echo "Sorted array is:"
echo ${arr[*]}