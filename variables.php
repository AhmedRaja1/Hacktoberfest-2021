<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Variables & Output Statements</title>
    <style>
        .label {
            color: red;
        }
    </style>
</head>
<body>
<?php

$student_id = 10;
$student_name = "Hamza Ali";

echo '<span class="label">Student ID:</span>'.$student_id.' <span class="label">Student Name: </span>'.$student_name;
/* Multiple variables Output
echo $student_id, $student_name;
*/

//print $student_id;
?>
</body>
</html>