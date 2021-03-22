<?php

require_once('./Model/DBConfig.php');
$db = new Database();
$db->connect();

if (isset($_GET['action'])) {
    $action = $_GET['action'];
} else {
    $action = '';
}

switch ($action) {
    case '': {
        require_once('View/ThanhVien/index.php');
        break;
    }
    
    case 'add': {
        if (isset($_POST['add-user'])) {
            $hoten = $_POST['hoten'];
            $namsinh = $_POST['namsinh'];

            $tableName   = 'thanhvien'; //tên table
            $tablePropsTemp = ['id', 'hoTen', 'namSinh']; //thuộc tính table
            $valueTemp = ['NULL', "'" . $hoten . "'", "'" . $namsinh . "'"]; //giá trị

            $tableProps = implode(',', $tablePropsTemp);  //implode: convert Array to String
            $value = implode(",", $valueTemp);

            $db->InsertData($tableName, $tableProps, $value);
        }

        require_once('View/ThanhVien/add_user.php');
        break;
    }

    
}


?>