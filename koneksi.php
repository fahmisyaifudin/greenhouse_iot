<?php
    $dbhost = 'localhost';
    $dbuser = 'root';
    $dbpass = '';
    $dbname = 'db_septi';
    $koneksi = new mysqli($dbhost, $dbuser, $dbpass, $dbname);
    
    if(!$koneksi ){
        die('Could not connect: ' . mysqli_error());
    }
    //echo 'Connected successfully';
?>