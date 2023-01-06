<?php
echo chr(28) . "<br>"; // Decimal value
echo chr(062) . "<br>"; // Octal value
echo chr(0x52) . "<br>"; // Hex value
echo "<br>".str_replace("rld","Peter","Hello world!");
echo"<br>";
echo strchr("<br>this is world nice .Hello world! welcome this is nice","world");



//The chunk_split() function splits a string into a series of smaller parts.
$str = "Hello world! this is a beautiful day";
echo "<br>".chunk_split($str,2," ");

//The implode() function returns a string from the elements of an array.
$arr = array('Hello','World!',10,'Day!');
echo "<br>".implode(".",$arr);

$arr = array('Hello','World!','Beautiful','Day!');
echo "<br>".join(" ",$arr);

//The explode() function breaks a string into an array.
$str = "Hello world. It's a beautiful day.";
echo"<br>";
print_r (explode(" ",$str));
$z=explode(" ",$str);

foreach($z as $a)
echo"<br>".$a;

echo "<br>No. of words in the string-> Hello world are :".str_word_count("Hello   world!. welcome to php        this is gud");


echo "<br>".strcmp("Hello world!","Hello world!");

echo "<br>".strcmp("hello world!","Hello world!");

echo "<br>".strcmp("Hello World!","Hello WorLd!");

//The strchr() function searches for the first occurrence of a string inside another string return the rest of the string



echo "<br>".strchr("Hello world! this is amazing","world");


//stripos finds the first occurence of a string

//The strpos() function finds the position of the first occurrence of a string inside another string.(case sensitive)

echo "<br>".stripos(" is a server side PhP scripting language. PhP is called Hypertext preprocessor","PHP");


//The strripos() function finds the position of the last occurrence of a string inside another string. strrpos -casesensitive

echo "<br>".strripos("PHP is a server side scripting language. PHP is called Hypertext PHP preprocessor","PHP");

echo "<br>".strrev("Hello World!");
?>
