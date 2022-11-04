#!/usr/bin/bash

echo "Enter the number of elements:"
read n

echo "Enter the elements:"
for ((i=0;i<n;i++)); do
	read arr[$i]
done

sum=0
for ((i=0;i<n;i++)); do
	sum=$((sum + ${arr[$i]}))
done

echo "Sum of all elements in the array is: "$sum