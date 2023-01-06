<?php

$number = 123456789;
$digit = 3;

$pos = strpos((string)$number, (string)$digit);

if ($pos !== false) {
  echo "The digit $digit was found at position $pos in the number $number.";
} else {
  echo "The digit $digit was not found in the number $number.";
}

?>
