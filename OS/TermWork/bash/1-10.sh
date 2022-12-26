echo "Shell script to copy files only from the current directory to another directory."

echo "Enter destination directory (directory files to be copied to):"
read dir
for i in $(ls); do
	if [[ -f $i ]]; then
		$(cp $i $dir)
	fi
done