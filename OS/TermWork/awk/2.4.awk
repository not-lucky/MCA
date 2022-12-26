BEGIN {
    print "Employee ID, Employee First_Name, Employee Last_Name, Location, Designation, Net Salary, Specialization, Project, Joining Month, Joining_Year\n"
}


(($6 > 45000 && $6 < 65000) && ($10 >= 2000 && $10 <= 2005)) {
    print $1 ", " $2 ", " $3 ", " $4 ", " $5 ", " $6 ", " $7 ", " $8 ", " $9 ", " $10
}