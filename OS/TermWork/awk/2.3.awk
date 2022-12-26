BEGIN {
    print "Following are the records (Employee Id, Name, location, Designation, Joining Month, Joining_Year) of all those employees who joined after Jan 2000 but before December 2005:\n"
    print "Employee Id, Name, location, Designation, Joining Month, Joining_Year\n"
}


(($9 != "January" && $10 >= 2000) && ($9 != "December" && $10 <= 2005)) {
    print $1 ", " $2 " " $3 ", " $4 ", " $5 ", " $9 ", " $10
}