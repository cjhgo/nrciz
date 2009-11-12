#!/usr/bin/php
<?php
if ($argc != 3) {
	die("Usage: gcd-yetist.php <number> <number>\n");
}

$a = $argv[1];
$b = $argv[2];
for(;;)
{
	$c = $a % $b;
	echo "$a,$b,$c,\n";
	if ($c == 0)
		break;
	$a = $c;
	list($a, $b) = array($b, $a);
}
echo "common divisor is $b\n"; 
?>
