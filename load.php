 <table id="myTable" class="display table">
  <thead class="thead-light">
    <tr>
      <th scope="col">Waktu</th>
      <th scope="col">Suhu</th>
      <th scope="col">Kelembapan</th>
      <th scope="col">Keterangan</th>
    </tr>
  </thead>
  <tbody>
 <?php

include 'koneksi.php';
$query = mysqli_query($koneksi, "SELECT * FROM data" );
                                    while ($row = mysqli_fetch_array($query)) {
                                    	if ($row['kelembapan'] < 15) {
                                    		$status = 'Lampu Nyala';
                                    	}else if ($row['kelembapan'] > 40) {
                                    		$status = 'Kipas Nyala';
                                    	}else{
                                    		$status = 'Kipas dan Lampu Mati';
                                    	}
                                echo         '<tr>
                                                <th scope="row">'.$row['waktu'].'</th>
                                                <td>'.$row['suhu'].'</td>
                                                <td>'.$row['kelembapan'].'</td>
                                                <td>'.$status.'</td>
                                                </tr>';
                                    }
                                    ?>

 </tbody>
</table>