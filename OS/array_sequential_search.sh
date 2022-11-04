#!/usr/bin/bash

echo "Enter the number of elements:"
read n

echo "Enter the elements:"
for ((i=0;i<n;i++)); do
	read arr[$i]
done

echo "Enter the element needs to be searched:"
read ele
for ((i=0;i<n;i++)); do
	if [[ ${arr[$i]} -eq $ele ]]; then
		echo "Element found!!!"
		exit;
	fi
done

echo "Element not found!!!"