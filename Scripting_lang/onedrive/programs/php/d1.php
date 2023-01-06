<?php
$con=mysqli_connect("localhost:3306","root","");
// Check connection
if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }

// Create database
$sql="CREATE DATABASE MCA2022";
if (mysqli_query($con,$sql))
  {
  echo "Database MCA2022 created successfully";
  }
else
  {
  echo "Error creating database: " . mysqli_error($con);
  }
mysqli_close($con);
?>
