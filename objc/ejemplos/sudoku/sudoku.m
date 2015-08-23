#include <stdio.h>
#include <Foundation/Foundation.h>
#include <stdlib.h>

#define LADO 3 // Es la longitud del ancho de cada caja
#define CAJAS 9 // Caja son los cuadrados de 3x3 números
#define SE_VEN 3 // esel número de números que ven al empezar

@interface  Celda : NSObject
/*
Las celdas conforman el tablero. Cada celda tiene dos
atributos. El NÚMERO, que tiene que cumplir las condi-
ciones impuestas por las reglas del juego, y el ESTADO,
que puede ser visible o no. Los número se vuelven vi-
sibles a medida que el jugador acierta.
 */
{
  int _numero;
  int _estado;
}
- (id) init;
- (void) setNumero:(int) arg;
- (int) numero;
- (void) setEstado:(int) arg;
- (int) estado;
@end

@implementation Celda

- (id) init 
{
  [super init];
    if(self)
      {
	//	int randomNumber = rand() % 9;
	//[self setNumero: randomNumber];
	//[self setEstado: 1];
      }
    return self;
}

- (void) setNumero:(int) arg {  _numero = arg; }
- (int) numero { return _numero;}
- (void) setEstado:(int) arg {  _estado = arg; }
- (int) estado { return _estado;}

@end	

// falta hacer todo el main

@interface  Tablero : NSObject
/*
Obiamente, el tablero contine las celdas, pero nos 
referiremos a ellas a través de dos vectores de 
punteros.
*/
{
	Celda *celdas[CAJAS][LADO][LADO];
	Celda **ptrtab[2][9][9];

  /* 
ptrtab es un vector de punteros a celdas.
tenemos que CAJAS = 9 y LADO = 3, y que
(* 9 3 3) 81. Asimismo,
(* 2 9 9) 162.
Esto es porque  ptrtab[0] son las filas y
ptrtab[1] son las columnas del tablero (o sea
son dos maneras de verlo).
   */
}
- (id) init;
- (void) dibujarCaja:(int) caja;
- (void) dibujar3CajasDesde:(int) desde Hasta:(int) hasta;
- (void) dibujarTablero;
- (void) mostrar3CajasDesde:(int) desde Hasta:(int) hasta;
- (void) mostrarTablero;
- (void) set_estadosT;
- (void) set_filPointersDesde:(int) desde Hasta:(int) hasta;
- (void) set_colPointersDesde:(int) desde Hasta:(int) hasta;
- (void) setPointers;
- (int) getPointerNum:(int) filCol Nro:(int) nro Cel: (int) cel;
- (void) mostrar_pointers;
- (int) get_numeroCaja:(int) caja Fila:(int) fila Columna:(int) columna; 
- (Celda *) celdaCaja:(int) caja Fila:(int) fil Columna:(int) col;
@end

@implementation Tablero

- (id) init
{
  [super init];
  if(self) {
    int i, j, k;
    [self setPointers];      
    for(i = 0; i < CAJAS ; ++i){
      for(j = 0; j < LADO; ++j){
	for(k = 0; k < LADO; ++k){
	  [[self celdaCaja: i Fila: j Columna: k] setNumero: (rand() % 9) + 1];
	}
      }
    }
  }
  return self;
}

-(void) dibujarCaja:(int) caja
{
  int j, k;
  for(j = 0; j < LADO; ++j)
    {
      printf("  \n");
      for(k = 0; k < LADO; ++k)
	{
	  printf("%d", [[self celdaCaja: caja Fila: j Columna: k] numero]);
	}
    }
}

-(void) dibujar3CajasDesde:(int) desde Hasta:(int) hasta 
{
  int i, j, k;
  for(j = 0; j < LADO ; ++j)
    {
      printf("\nFila %d ", j);
      for(i = desde; i < hasta + 1; ++i)
	{
	  printf("  ");
	  for(k = 0; k < LADO; ++k)
	    {
	      printf("%d", [celdas[i][j][k] numero]);
	    }
	}
    }
}

-(void) dibujarTablero
  // Acá se dibuja el tablero usando la función
  // dibujar3CajasDesde:Hasta:
{
  [self dibujar3CajasDesde:0 Hasta:2];
  printf("\n");
  [self dibujar3CajasDesde:3 Hasta:5];
  printf("\n");
  [self dibujar3CajasDesde:6 Hasta:8];
  printf("\n");
}

-(int) get_numeroCaja:(int) caja Fila:(int) fila Columna:(int) columna
{
	return [celdas[caja][fila][columna] numero];
}

-(void) mostrar3CajasDesde:(int) desde Hasta:(int) hasta
{	
  int i, j, k;
  for(j = 0; j < LADO ; ++j)
    {
      printf("\nFila %d ",  j);
      for(i = desde; i < hasta + 1; ++i)
	{
	  printf("  ");
	  for(k = 0; k < LADO; ++k)
	    {
	      if([celdas[i][j][k] estado] == 1)
		{
		  printf("%d", [celdas[i][j][k] numero]) ;
		}
	      else printf(" ");
	    }
	}
    }
}

- (void) mostrarTablero
{
 [self mostrar3CajasDesde: 0 Hasta: 2];
  printf("\n");
 [self mostrar3CajasDesde: 3 Hasta: 5];
  printf("\n");
 [self mostrar3CajasDesde: 6 Hasta: 8];
  printf("\n");
}

-(void) set_estadosT
{
  int i, j, k;
  for(i = 0; i < CAJAS; ++i)
    {
      for(j = 0; j < LADO; ++j)
	{
	  for(k = 0; k < LADO; ++k) //los 2 lados son iguales xq es cuadrado.
	    {
	      if((rand() % CAJAS) < SE_VEN) [celdas[i][j][k] setEstado:1];
	      else [celdas[i][j][k] setEstado:0];
	    }
	}
    }
}

 -(void) set_filPointersDesde:(int) desde Hasta:(int) hasta 
{
  /*
Hay que tener cuidado con los args. Pueden ser:
(0,2), (3,5) y (6,8), nada más. Acá lo que se hace
es correlacionar las "celdas" con los "ptrtabs".
Hay que chequear si se puede hacer así como está,
es decir accediendo directamente, o si es mejor 
usar seter y getter.
  */
  int i, j, k, l;
  for(j = 0; j < LADO ; ++j){
    l = 0;
    for(i = desde; i < hasta + 1; ++i)
      {
	for(k = 0; k < LADO; ++k)
	  {
	    ptrtab[0][j+desde][l++] = &celdas[i][j][k];
	  }
      }
  }
}

 -(void) set_colPointersDesde:(int) desde Hasta:(int) hasta 
  {
    /*
colPointers porque son las columnas.
Hay que tener cuidado con los args.
Pueden ser: (0,7), (1,8) y (2,9). Nada más.
Ídem lo de arriba.
    */
  int i, j, k, l;
  for(k = 0; k < LADO ; ++k)
    {
      l = 0;
      for(i = desde; i < hasta; i += 3)
	{
	  for(j = 0; j < LADO; ++j)
	    {
	      ptrtab[1][k+desde*3][l++] = &celdas[i][j][k];
	      // el 1 es porque es colPointers
	    }
	}
    }
  }
 
-(void) setPointers
{
  int i;
  for(i = 0; i < 7; i += 3)
    { [self set_filPointersDesde: i
			   Hasta: i+2];
    }
  for(i = 0; i < 3; ++i)
    { [self set_colPointersDesde: i
			   Hasta: i+7];
    }
}

-(int) getPointerNum:(int) filCol Nro:(int) nro Cel:(int) cel
{
	return [*ptrtab[filCol][nro][cel] numero];
}

-(void) mostrar_pointers
{
  int i, j, k;
  for(i = 0; i < 2; ++i)
    {
      printf( "FIL/COL: %d\n", i);
      for(j = 0; j < 9; ++j)
	{
	  printf("\n   nro: %d ", j);
	  for(k = 0; k < 9; ++k)
	    {
	      printf("%d",  [self getPointerNum:i Nro:j Cel: k]);
	    }
	}
    }
}

- (Celda *) celdaCaja:(int) caja Fila:(int) fil Columna:(int) col
  {
    return celdas[caja][fil][col];
  }
@end

int main(void)
{
  //	int i, j, k;
  printf("\n\n Un printf previo \n\n");
  //  [[Tablero alloc] init];
    
	Tablero *elTablero = [[Tablero alloc] init];
	[elTablero dibujarTablero];
	[elTablero set_estadosT];
	[elTablero mostrarTablero];
	printf("\n get: ");
	[elTablero mostrar_pointers];
	printf("\n\n%d", rand() % 9);
	printf("\n\n\n\n ACA HAY UN PRINTF \n\n\n");
	//std::cout << elTablero.getPointerum(0,1,2);
	//elTablero.mostrar_pointers();
	return 0;
}

