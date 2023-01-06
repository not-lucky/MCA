<?php
// A two-dimensional array:
$cars = array(array(1,2,3,4,5,100,96),
array("BMW",60,59),
array("Toyota",110));
for($i=0;$i<3;$i++)
{
echo $cars[0][$i];

}
print_r($cars);
?>