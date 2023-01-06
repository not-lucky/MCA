<?php
$con=mysqli_connect("localhost:3306","root","","MCA");
// Check connection
if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }
$res = mysqli_query($con,"SELECT * FROM Reg where Age<18");
echo "NAME";
  echo "<br>";
echo"_________________";
echo "<br>";
while($row = mysqli_fetch_array($res))
  {
  
  echo $row['FirstName'] . " " . $row['LastName']. "".$row['Age'];

  echo "<br>";
  }

mysqli_close($con);
?>