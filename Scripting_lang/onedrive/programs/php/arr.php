<html>
<body>
<?php

$numbers = array( 1,2,"Hello",4,"QW",23,'m', 5);
foreach( $numbers as $value )
{
  echo "Value is $value <hr />";
}
var_dump($numbers);
/* Second method to create array. */
$numbers1[0] = "one";
$numbers1[1] = "Two";
$numbers1[2] = "three";

$numbers1[3] = "four";
$numbers1[4] = "five";

print_r($numbers1);
rsort($numbers1);
print_r($numbers1);
?>
</body>
</html>