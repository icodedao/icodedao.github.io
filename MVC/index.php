<?php
    require_once('./Model/DBConfig.php');
    $database = new Database();
    $database->connect();

    if ( isset($_GET['viewpage']) ){
        $viewPage = $_GET['viewpage']; 
    }
    else{
        $viewPage = '';
    }

    switch ($viewPage){
        case 'thanh-vien':{
            require_once('Controller/ThanhVien.php');
            break;
        }

        default:{
            require_once('Controller/Home.php');
        }
      
    }
    

?>