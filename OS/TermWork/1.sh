#!/bin/bash

files=0
dir=0
echo  "asdasdad"
for i in $(ls)
do
if [ -f "$i" ]
then
files=$(($files + 1))
elif [ -d $i ]
then
dir=$(($dir + 1))
fi
done
echo "Files = $files"
echo "Dir = $dir"