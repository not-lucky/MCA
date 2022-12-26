echo "Shell script to count and display numbers of files and directory present in the current directory."

let files=0
let directory=0
for i in $(ls); do
	if [[ -f $i ]]; then
		files=$(($files + 1))
	elif [[ -d $i ]]; then
		directory=$(($directory + 1))
	fi
done
echo "There are $files files in current working directory."
echo "There are $directory directories in current working directory."