<?php
$log_file = 'sound_log.txt';
$data = $_POST['data'];
$today = date("Y-m-d H:i:s");
$str = $today.','.$data."\n";
//echo "This is from the server";
if(file_exists($log_file)){
	$fp=fopen($log_file,"a");
	fwrite($fp,$str);
	fclose($fp);
	}else{
			$fp = fopen($log_file,"w");
			fwrite($fp,$str);
			fclose($fp);
		}
echo "Data is stored\n";
?>
