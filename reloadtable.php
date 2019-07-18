<?php


include 'koneksi.php';
$query = mysqli_query($koneksi, "TRUNCATE TABLE data" );
header("location: index.php")


?>