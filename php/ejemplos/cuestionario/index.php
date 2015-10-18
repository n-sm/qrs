<html>
  <head>
    <title>Cuestionario</title>
    <link rel="stylesheet" href="styles.css">
  </head>
  
  <body>
    
    <h3>Cuestionario</h3>
    <?php include 'foo.php'; ?>
    <?php
//      echo phpversion()."<br>\n";

      // Instancias

      $optArr = [new Opcion("Opcion 1"),
      new Opcion("Opcion 2"),
      new Opcion("Opcion 3"),
      new Opcion( "Opcion 4"),
      new Opcion( "OPCION CINCO")];

      $optArr2 = $optArr;
// no func!     $optArr2.push(new Opcion("Opcion TRES"));
      $pregu1 = new Item(01, "la primera pregunta", $optArr);
      $pregu2 = new Item(02, "la segunda pregunta", $optArr);
      
      echo $pregu1->str();
    echo $pregu2->str();

      ?>
  </body>
</html>
