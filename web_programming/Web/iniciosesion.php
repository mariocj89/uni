<?php
if( $_REQUEST["password"]=="MITIENDA"){
	echo("<script>location.href='sesion2.php'; </script>");
	$_SESSION["acceso"]="si";
	
}
else{
	
	echo("<script> alert('contraseņa incorrecta'); location.href='sesion.php' </script>");
	}

?>