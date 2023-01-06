<?php
$con=mysqli_connect("localhost:3306","root","","MCA2022");
// Check connection
if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }

//Insert 
if(mysqli_query($con,"INSERT INTO Reg (FirstName, LastName, Age)VALUES ('Amita', 'Singh',20)"))

  {
  echo "record inserted successfully";
  }
else
  {
  echo "Error inserting records: " . mysqli_error($con);
  }


mysqli_close($con);
?>