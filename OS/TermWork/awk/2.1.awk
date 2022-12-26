BEGIN {
    print "Following are the records (Employee Id, Name, location, and Designation) of employees having designations as ‘Manager’:\n"
    print "Employee ID, Name, Location, Designation\n"
}


($5 == "Manager") {
    print $1 ", " $2 " " $3 ", " $4 ", " $5 
}