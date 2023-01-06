

<?php
$number = 24;
$str = "India";
$file = fopen("tt.txt","w");
echo fprintf($file,"There are %u million bicycles in %s.",$number,$str);
?>
