/* El problema con este programa esta en que supone posible armar un
tablero encasos donde no esta garantizado que se pueda lelgar.
entonces se forma un loop infinito.
*/

#include <stdio.h>
#include <Foundation/Foundation.h>
#include <stdlib.h>

#define LADO 3 // Es la longitud del ancho de cada caja
#define CAJAS 9 // Caja son los cuadrados de 3x3 números
#define SE_VEN 3 // esel número de números que ven al empezar
#define COUNTER 99999
@interface  Celda : NSObject
/*
Las celdas conforman el tablero. Cada celda tiene dos
atributos. El NÚMERO, que tiene que cumplir las condi-
ciones impuestas por las reglas del juego, y el ESTADO,
que puede ser visible o no. Los número se vuelven vi-
sibles a medida que el jugador acierta.
 */
{
  int celNumber;
  int celState;
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
	[self setNumero: -1];
	[self setEstado: 1];
      }
    return self;
}

- (void) setNumero:(int) arg {  celNumber = arg; }
- (int) numero { return celNumber;}
- (void) setEstado:(int) arg {  celState = arg; }
- (int) estado { return celState;}

@end	

// falta hacer todo el main

@interface  Tablero : NSObject
{
  //  NSMutableArray *NSCeldas;
  Celda *celdas[CAJAS][LADO][LADO];
  Celda **ptrtab[2][9][9];
  //  Celda *testCel;
/*
Obiamente, el tablero contine las celdas, pero nos 
referiremos a ellas a través de dos vectores de 
punteros.
*/
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
- (int) numeroEnCaja:(int) caja Fila:(int) fila Columna:(int) columna; 
- (id) celdaCaja:(int) caja Fila:(int) fil Columna:(int) col;
-(void) setNumeroDeCeldaCaja:(int) caja Fila:(int) fila Columna:(int) col Numero:(int) numero;
-(void) llenarCajaNumero:(int) caja;
-(int) compararCeldasEnCaja:(int) caja  conNumero:(int) num;
-(int) compararPointers:(int) orientacion DeFoC:(int) foc conNumero:(int) num;
-(int) compararFilPointersCaja:(int) caja Fila:(int) fila conNumero:(int) num;
-(int) compararColPointersCaja:(int) caja Col:(int) col conNumero:(int) num;
@end

@implementation Tablero

- (id) init
{
  [super init];
  if(self) 
    {
      int i, j, k;
      // ahora allocamos...
      for(i = 0; i < CAJAS; ++i)
	{
	  for(j = 0; j < LADO; ++j)
	    {
	      for(k = 0; k < LADO; ++k)
		{
		  celdas[i][j][k] = [[Celda alloc] init];
		}
	    }
	}
    }
  [self setPointers];
  int c;
  for(c=0; c<9;++c)
    {
      [self llenarCajaNumero:c];
    }
  return self;
}

-(void) dibujarCaja:(int) caja
{
  /*
Dibuja una caja indentada, por ej.:
  123
  456
  789
   */
  int j, k;
  for(j = 0; j < LADO; ++j)
    {
      printf("  \n");
      for(k = 0; k < LADO; ++k)
	{
	  printf("%d", [celdas[caja][j][k] numero]);
	}
    }
}

-(void) dibujar3CajasDesde:(int) desde Hasta:(int) hasta 
{
/* 
Acá 'desde' sólo pueden se 0, 3 o 7, y 'hasta' sólo pueden
ser 2, 6 y 8, para dibujar bien.

*/
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
  /*
Acá se dibuja el tablero usando la función
dibujar3CajasDesde:Hasta:
Se dibuja el tablero completo
  */
{
  [self dibujar3CajasDesde:0 Hasta:2];
  printf("\n");
  [self dibujar3CajasDesde:3 Hasta:5];
  printf("\n");
  [self dibujar3CajasDesde:6 Hasta:8];
  printf("\n");
}

-(int) numeroEnCaja:(int) caja Fila:(int) fila Columna:(int) columna
{
	return [celdas[caja][fila][columna] numero];
}

-(void) mostrar3CajasDesde:(int) desde Hasta:(int) hasta
{	
  /*
Esta es como 'dibujas3CadasDesde:Hasta:', pero sólo muestra
las cajas con estado == 1
   */
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
  /*
Este método lo que hace es mostrar solamente los número que
el jugador necesita ver para jugar.
  */
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

- (id) celdaCaja:(int) caja Fila:(int) fil Columna:(int) col
  {
    return celdas[caja][fil][col];
  }

-(void) setNumeroDeCeldaCaja:(int) caja Fila:(int) fila Columna:(int) col
		      Numero:(int) numero
{
  [celdas[caja][fila][col]  setNumero:numero];
}

-(void) llenarCajaNumero:(int) caja
{
  int i, j, randomNumber;
  long int contador = 0; //, testNumber = 0;
  //  int salir = 0;

  for(i = 0; i < LADO; ++i)
    {
      for(j = 0; j < LADO; ++j)
	{
	  randomNumber = rand() % 9 + 1;
	  while(([self compararCeldasEnCaja:caja conNumero:randomNumber] ||
		 [self compararFilPointersCaja:caja Fila:i conNumero:randomNumber] ||
		 [self compararColPointersCaja:caja Col:j conNumero:randomNumber]) &&
		contador < COUNTER)
	    {
	      contador++;
	      randomNumber = rand() % 9 + 1;
	    }
	  // Acá está es SETTER!!
	  [celdas[caja][i][j] setNumero: randomNumber];
	  /*
	  //	  printf("\nSe esribe %d en %d-%d.", randomNumber, i, j);
	  //	  printf("\nDiferente de:");
	  int o, p;
	  for(o = 0; o <= i; ++o){
	    for(p = 0; p <= j; ++p){
	      printf("%d", [celdas[caja][o][p] numero]);
	    }
	  }
	  */
	}
    }
}


-(int) compararCeldasEnCaja:(int) caja  conNumero:(int) num
  /*
Se fija si alguna de las celdas tiene el mismo número que el randomNumber.
Si es así devuelve 1
  */
{
  int i, j;
  int retVal = 0;
  for(i = 0; i < LADO; ++i)
    {
      for(j = 0; j < LADO; ++j)
	{
	  if([celdas[caja][i][j] numero] == num)
	    {
	      retVal++;
	    }
	}
    }
  return retVal;
}

-(int) compararPointers:(int) orientacion DeFoC:(int) foc conNumero:(int) num
{
  int i, retVal = 0;
  for(i = 0; i < 9; ++i)
    {
      if([self getPointerNum:orientacion Nro:foc Cel: i] == num) retVal++;
    }
  return retVal;
}

-(int) compararFilPointersCaja:(int) caja Fila:(int) fila conNumero:(int) num
{
  int i;
  int retVal = 0;
  int c = 0;
  if(!(caja < 3)) 
    {
      if(caja < 6) c = 3 ;
      else if(caja > 5) c = 6 ;
    }
  for(i = 0; i < 9; ++i)
    {
      if([self getPointerNum:0 Nro:(fila + c) Cel:i] == num)
	{
	  retVal++;
	  //	  printf("\n SUMA RETVAL EN FILAS: ");
	  //printf("tengo %d = %d", [self getPointerNum:0 Nro:(fila + c) Cel:i], num);
	}
    }
  return retVal;
}

-(int) compararColPointersCaja:(int) caja Col:(int) col conNumero:(int) num
{
  int i;
  int retVal = 0;
  int c = 0;
  if(!(caja % 3 == 0))
    {
      if((caja-1) % 3 == 0) c = 3;
      else  if((caja+1) % 3 == 0) c = 6;
    }
  for(i = 0; i < 9; ++i)
    {
      if([self getPointerNum:1 Nro:(col + c) Cel:i] == num)
	{
	  retVal++;
	  //	  printf("\nsumo retVal en columnas");

	}
    }
  return retVal;
}
@end


int main(void)
{
  Tablero *elTablero = [[Tablero alloc] init];
  printf("\nAcá: [elTablero dibujarTablero];");
  [elTablero dibujarTablero];
  [elTablero set_estadosT];
  printf("\nAcá [elTablero mostrarTablero];");
  [elTablero mostrarTablero];
  [elTablero  mostrar_pointers];


  return 0;
}

