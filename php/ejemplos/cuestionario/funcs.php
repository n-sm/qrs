<?php

$optArr = ["Opcion 1", "Opcion 2", "Opcion 3", "Opcion 4"];

Class Opcion {

public $texto;

public function __construct($texto) {
$this->texto = $texto;
}
public function str($name, $value) {
return "<input type=\"radio\" name=\"$name\" value=\"$value\">$this->texto"
    }
}
Class Item {

 public $id;
 public $pregunta;
 public $opciones;

 public function __construct($id, $pregunta, $opciones) {
 $this->id = $id;
 $this->pregunta = $pregunta;
 $this->opciones = $opciones;
 }

 public function str() {
$len = count($this->opciones);
$str = "<table><th colspan=$len>$this->pregunta</th><tr>";
for ($i = 0; $i <$len; $i++) {
$str .= "<td>".$this->opciones[i]->str("p".$this->id, "op".i)."</td>";
}
$str .= "</tr></table>"
 }

}
<?