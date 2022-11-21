echo "Shell script to sequentially search for an elements inside an array"

echo "Enter length of array:"
read n

echo "Enter elements of the array:"
for ((i=0;i<n;i++)); do
    read arr[$i]
done

echo "Enter the element to search for:"
read ele

let not_found=1
for((i=0;i<n;i++)); do
    if [[ $ele -eq ${arr[$i]} ]]; then
        echo "The element \"$ele\" found at index position $i of the array."
        not_found=0
    fi
done

if [[ $not_found -eq 1 ]]; then
    echo "Element \"$ele\" not found in the array."
fi