<?php

Class Opcion {

    public $texto;

    public function __construct($texto) {
        $this->texto = $texto;
    }

    public function str($name, $value) {
        return "<input type=\"radio\" name=\"$name\" value=\"$value\">$this->texto";
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
//$name = "p".$this->id;
  $str = "<table><th colspan=$len>$this->pregunta</th>"."\n"."<tr>";

  for ($i = 0; $i < $len; $i++) {
    $str .= "<td>".$this->opciones[$i]->str("p".$this->id, "op".i)."</td>"."\n";
  }

  $str .= "</tr>"."\n"."</table>";
  return $str;
 }

}

/*/ Instancias

$optArr = [new Opcion("Opcion 1"),
           new Opcion("Opcion 2"),
           new Opcion("Opcion 3"),
           new Opcion( "Opcion 4")];

$pregu1 = new Item(01, "la primera pregunta", $optArr);
$pregu2 = new Item(02, "la segunda pregunta", $optArr);

echo $pregu1->str();
echo $pregu2->str();
*/
?>