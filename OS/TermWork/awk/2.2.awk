BEGIN {
    print "Following are the records (Employee_ID, Name, Specialization, Location) of employees who are specialized in Java Programming and are working at Delhi or Pune locations:\n"
    print "Employee_ID, Name, Specialization, Location\n"
}


($7 == "java" && ($4 == "Delhi" || $4 == "Pune")) {
    print $1 ", " $2 " " $3 ", " $7 ", " $4 
}