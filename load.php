 <table class="table">
  <thead class="thead-light">
    <tr>
      <th scope="col">Waktu</th>
      <th scope="col">Suhu</th>
      <th scope="col">Kelembapan</th>
    </tr>
  </thead>
  <tbody>
 <?php

include 'koneksi.php';
$query = mysqli_query($koneksi, "SELECT * FROM data" );
                                    while ($row = mysqli_fetch_array($query)) {
                                echo         '<tr>
                                                <th scope="row">'.$row['waktu'].'</th>
                                                <td>'.$row['suhu'].'</td>
                                                <td>'.$row['kelembapan'].'</td>
                                                </tr>';
                                    }
                                    ?>

 </tbody>
</table>