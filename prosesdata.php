<?php

include 'koneksi.php';
$kelembapan = isset($_GET['kelembapan']) ? $_GET['kelembapan'] : false;
$suhu = isset($_GET['suhu']) ? $_GET['suhu'] : false;

mysqli_query($koneksi, "INSERT INTO data (waktu, suhu, kelembapan) VALUES (now(), '$suhu', '$kelembapan')");

?>