<?php
$rutas = scandir('06_funciones');
foreach ($rutas as $r) {
    if (!is_dir('06_funciones/'.$r)) {
        echo $r,"\n";
    }
}
