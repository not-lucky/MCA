<?php
function ref(&$var)
{
    $var=$var*10;
}

$a=5;
ref($a);
echo"Call by reference  ";
echo $a;

function byval($var)
{
    $var++;
}
byval($a);
echo"<br>Call by value";
echo " ".$a;
?>