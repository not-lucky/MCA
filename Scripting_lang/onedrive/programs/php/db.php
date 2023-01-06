<?php
$con=mysqli_connect("localhost:3306","root","","MCA2022");
// Check connection
if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }

// Create table
$sql="CREATE TABLE Reg(FirstName CHAR(30),LastName VARCHAR(30),Age INT)";

// Execute query
if (mysqli_query($con,$sql))
  {
  echo "Table created successfully";
  }
else
  {
  echo "Error creating table: " . mysqli_error($con);
  }


mysqli_close($con);
?>