BEGIN {
    print "Employee ID Employee_First_Name Employee_Last_Name Location Designation Net_Salary Specialization Project Joining_Month Joining_Year\n"
    max = 0
    max_row = 0
}

($4 == "Delhi") {
    if ($6>max) { 
        max=$6
        max_row = $NA
    }

} 

END {
    print max_row
}
