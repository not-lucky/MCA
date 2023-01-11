read n
for((i=0;i<n;i++)); do
    read a[$i]
done

for((i=0;i<n;i++));do
    p=$(($i-1))
    if [[ $p -eq -1 ]]; then
        p=$(($n-1))
    fi
    p_ele=${a[$p]}
    square=$(($p_ele*$p_ele))
    if [[ $square -eq ${a[$i]} ]]; then
        echo ${a[$i]}
    fi
done