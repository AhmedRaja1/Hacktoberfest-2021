<?php
/*
* PHP Arrays
*/

//Indexed Arrays
$brands = array("Samsung", "Nokia", "Apple", "Motorola");

$phones[10] = "Galaxy S10";
$phones[20] = "iPhone 11";
$phones[30] = "Nokia 6.2";

//Associative Arrays
$persons = array("Kashif"=>"00123454", "Aslam"=>"012457896", "Rasahid"=>"6579478" );
//echo "Kashif's Phone Number Is: ".$persons["Kashif"];

$products = array(
    array(1, "Galaxy S10",10,799),
    array(2, "iPhone 11", 20, 999),
    array(3, "Nokia 6.2", 10, 499)
);
//echo $products[1][1]."'s Price is $".$products[1][3]." and stock count is ".$products[1][2];
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Arrays in PHP</title>
</head>
<body>
    <h2>Brands</h2>
    <ul>
    <?php 
        foreach($brands as $value) {
            echo "<li>".$value."</li>";
        }
    ?>
    </ul>
    <h2>Phones</h2>
    <ul>
    <?php 
        foreach($phones as $value2) {
            echo "<li>".$value2."</li>";
        }
    ?>
    </ul>
    <h2>Phone Numbers</h2>
    <table>
        <thead>
            <tr>
                <th>Name</th>
                <th>Phone Number</th>
            </tr>
        </thead>
        <tbody>
            <?php
                foreach ($persons as $x => $y) {
                    echo "<tr><td>".$x."</td><td>".$y."</td></tr>";
                }
            ?>
        </tbody>
    </table>
    <h2>Products</h2>
    <table>
        <thead>
            <tr>
                <th>ID </th>
                <th>Product Name</th>
                <th>Stock</th>
                <th>Price</th>
            </tr>
        </thead>
        <tbody>
            <?php
                foreach($products as $row) {
                    echo "<tr>";
                        foreach ($row as $col) {
                            echo "<td>".$col."</td>";
                        }
                    echo "</tr>";
                }
            ?>
        </tbody>
    </table>
</body>
</html>