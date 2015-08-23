//#include "StdAfx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define SIMPC 'o'
#define SIMUSR 'x'
#define PC 0
#define USR 1

int jug[2][3][2] = {0}; // Array de jugadas: [jugador][jugada](fila,col).
char c, a[3][3]; // a es el tablero
int i, j, k, nj;
char *diag[8][3]; // diag son las ocho 3-tuplas de celdas relevantes.
char simbolos[] = { SIMPC, SIMUSR };
int nro_jugada0 = 0;
int nro_jugada1 = 0;

void jugar_tateti();
void vaciar_tab();
void mostrar_tab();
void pedir_jugada();
void hacer_jugada(int fila, int col);
void definir_diagonales();
void imprimir_diag(int numero_de_diag);
int chequear_diag(int nro_diag, char simbolo);
// devuelve el nro de ocurreencias de 'simbolo' en la diagonal nro 'nro_diagonal'.
int es_esquina(int jugador, int jugada);
int es_centro(int jugador, int jugada);
int es_medio(int jugador, int jugada);
int es_opuesto(int jugador, int jugada_previa, int jugada_actual);
int chequear_fin(int jugador);
int chequear_jaque(char jugador);
int buscar_vacia(int nro_diagonal);
int ubicar_diag(char simbolo, int cantidad); 
//devuelve la primer diagonal con 'cantidad' numero de 'simbolo'. Si ninguna cumple
//devuelve 8.
int chequear_ganador(); //devuelve el numero de ganador. Si no hay devuelve 2.
void mirar_tab();

int main(void)
{
  definir_diagonales();
  jugar_tateti();
  
  return 0;
}

void jugar_tateti(){
  vaciar_tab();
  mostrar_tab();
  pedir_jugada(); 
  mostrar_tab();
  if(es_esquina(1,0)){
    	  mirar_tab();
	  hacer_jugada(1,1);
	  mostrar_tab();
	  pedir_jugada();
	  if(es_esquina(1,1) & es_opuesto(1,0,1)){
		mirar_tab();
		hacer_jugada(0,1);
	    mostrar_tab();
		pedir_jugada();
	  }
  };

  if(es_centro(1,0)){
	  hacer_jugada(0,0);
	  mostrar_tab();
	  pedir_jugada();
	  mostrar_tab();
  }
  if(es_medio(1,0)){
	  hacer_jugada(1,1);
	  mostrar_tab();
	  pedir_jugada();
	  mostrar_tab();
  }
}

void mostrar_tab(){
  printf("\n%s", " _____");
  printf("\n%s%c%s%c%s%c%s", "|", a[0][0],"|", a[0][1], "|", a[0][2], "|");
  printf("\n%s%c%s%c%s%c%s", "|", a[1][0],"|", a[1][1], "|", a[1][2], "|");
  printf("\n%s%c%s%c%s%c%s", "|", a[2][0],"|", a[2][1], "|", a[2][2], "|");
  printf("\n%s", "-------");
  printf("\n");
}
void vaciar_tab(){
  int l, m;
  for(l = 0; l < 3; ++l) {
    for(m = 0; m < 3; ++m) {
      a[l][m] = ' ';
    }
  }
}
void pedir_jugada(){
 
  printf("Ingrese, separando con espacios:\n\n\n  Fila  Columna ");
  scanf("%d %d", &i, &j);
  a[i-1][j-1] = 'x';
  jug[1][nro_jugada1][0] = i-1;
  jug[1][nro_jugada1][1] = j-1;
}
void hacer_jugada(int fila, int col){
	
	a[fila][col] = 'o';
	jug[0][nro_jugada0][0] = fila;
	jug[0][nro_jugada0][1] = col;
}
void hacer_jugada_p(int diago, int celda){
	*diag[diago][celda] = SIMPC;
	nro_jugada0++;
	if(diago<3){jug[0][nro_jugada0][0] = diago; jug[0][nro_jugada0][1] = celda;}
	if(2<diago&diago<6){jug[0][nro_jugada0][0] = celda; jug[0][nro_jugada0][1] = diago-3;}
	if(diago=6){jug[0][nro_jugada0][0] = jug[0][nro_jugada0][1] = celda;}
	if(diago=7){jug[0][nro_jugada0][0] = celda; jug[0][nro_jugada0][1] = 2-celda;}
}
int contar_blancos(){
  int l, m;
  k = 0;
  for(l = 0; l < 3; ++l) {
    for(m = 0; m < 3; ++m) {
      if(a[l][m] == ' ')
	++k;
    }
  }
 return k;
}
void definir_diagonales(){
  int l, m;
for(l=0; l<3; ++l){
  for(m=0; m<3;++m)
    diag[l][m] = &a[l][m];
 }
for(l=0;l<3;++l){
  for(m=0; m<3; ++m)
    diag[l+3][m] = &a[m][l];
 }
for(m=0; m<3; ++m)
  diag[6][m] = &a[m][m];
for(m=0; m<3; ++m)
  diag[7][m] = &a[m][2-m];
}
void imprimir_diag(int numero_de_diag){
  int l;
	printf("\nDiagonal %d: |", numero_de_diag);
	for(l=0; l<3; ++l)
		printf("%c", *diag[numero_de_diag-1][l]);
	printf("|");
}
int chequear_diag(int nro_diag, char simbolo){
  /* Esta funcion es para ver cuantos simbolos de 
     un mismo tipo hay en una diagonal. */
  int l, m;
  for( l=m=0 ; l<3; ++l )
    if(*diag[nro_diag][l] == simbolo)
		++m;
  return m;
}
int es_esquina(int jugador, int jugada){
	return ((jug[jugador][jugada][0] != 1) & (jug[jugador][jugada][1] != 1));
}
int es_centro(int jugador, int jugada){
	return ((jug[jugador][jugada][0] == 1) & (jug[jugador][jugada][1] == 1));
}
int es_medio(int jugador, int jugada){
	return (((jug[jugador][jugada][0] == 1) | (jug[jugador][jugada][1] == 1)) & !es_centro(jugador, jugada));
}
int es_opuesto(int jugador, int jugada_previa, int jugada_actual){
	return ((jug[jugador][jugada_previa][0] == 2-jug[jugador][jugada_actual][0]) 
		& (jug[jugador][jugada_previa][1] == 2-jug[jugador][jugada_actual][1]));
}
int chequear_jaque(char simbolo_j){
	/*Devuelve si hay o no jaque del jugador con simbolo 'simbolo_j'*/
	if(ubicar_diag(simbolo_j, 2)<8)
		return 1;
	else return 0;
}
int buscar_vacia(int nro_diagonal){
/* Devuelve el numero de celda vacia y 3 si ninguna los está*/
  int l, celda = 3;
	for(l=0; l<3; ++l){
		if(*diag[nro_diagonal][l] == ' ')
			celda = l;
	}
	return celda;
}
int ubicar_diag(char simbolo, int cantidad){
	int l=0;
	while(((chequear_diag(l, ' ') != 3-cantidad) | (chequear_diag(l, simbolo) != cantidad)) & l<9)
		++l;
	return l;
}
int chequear_ganador(){
  int l;
	for(l=0; l<2; ++l){
		if(ubicar_diag(simbolos[l], 3) != 8)
			return l;
	}
	return 2;
}
void mirar_tab(){
  int l, m, cel = 0;
  /*
	if(chequear_ganador()<2){
		printf("Ganó el jugador %d", chequear_ganador());
		exit(1);
	}
  */
	if(chequear_jaque(SIMPC)){
	  m = 0;
		for(l=0; l<3; ++l){
		  if(ubicar_diag(SIMPC, 2) < 8){
		    m = ubicar_diag(SIMPC, 2);
		    if(m<8){
		      if(*diag[m][l] == ' ') cel = l;}
		  }// q devuelve ubicar?
		  hacer_jugada_p(ubicar_diag(SIMPC, 2), cel);
		}
		}


	if(chequear_jaque(SIMUSR)){
	  m = 0;
		for(l=0; l<3; ++l){
		  if(ubicar_diag(SIMUSR, 2) < 8){
		    m = ubicar_diag(SIMUSR, 2);
		    if(m<8){	
		      if(*diag[m][l] == ' ') cel = l;}
		  }
		  hacer_jugada_p(ubicar_diag(SIMUSR, 2), cel);
		}
	}

}
