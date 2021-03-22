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
        require_once('View/index.php');
        break;
    }

    
    
}

    





?>