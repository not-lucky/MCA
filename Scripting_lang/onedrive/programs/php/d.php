<?php
$con=mysqli_connect("localhost:3306","root","","MCA2019");
// Check connection
if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }

$fn=$_POST['fn1'];
	
$ln=$_POST['ln'];
$a=$_POST['a'];
if(!mysqli_query($con,"INSERT INTO reg (FirstName, LastName, Age)VALUES ('$fn', '$ln',$a)"))
{
  die('Error: ' . mysqli_error());
  }
echo "1 record added";


$res = mysqli_query($con,"SELECT * FROM reg");
echo "<br><br>NAME              Age";
  echo "<br>";
echo"_________________";
echo "<br>";
while($row = mysqli_fetch_array($res))
  {
    echo $row['FirstName']. " " . $row['LastName'] . "         " . $row['Age'] ;
  echo "<br>";
  }
mysqli_close($con);

?>


