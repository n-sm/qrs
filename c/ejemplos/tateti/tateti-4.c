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
void hacer_jugada_p(int diago, int celda);
void definir_diagonales();
void imprimir_diag(int numero_de_diag);
void mirar_tab();
void responder_jaque();
void ganar_jaq();
void ver_si_jaq1(char sim_vsj);

int chequear_diag(int nro_diag, char simbolo);
// devuelve el nro de ocurreencias de 'simbolo' en la diagonal nro 'nro_diagonal'.
int es_esquina(int jugador, int jugada);
int es_centro(int jugador, int jugada);
int es_medio(int jugador, int jugada);
int es_opuesto(int jugador, int jugada_previa, int jugada_actual);
int chequear_fin(int jugador);
int chequear_jaque(char jugador);
int buscar_vacia(int nro_diagonal);
int ubicar_diag_i(char simbolo, int cantidad); 
//devuelve la primer diagonal+1 con 'cantidad' numero de 'simbolo'. Si ninguna cumple
//devuelve 0.
int chequear_ganador(); //devuelve el numero de ganador. Si no hay devuelve 2.
int ubicar_celda(int diag_uc, char sim_uc);
int hay_par(char sim_hp);
int hay_jaq_de(char sim_hjd); //devuelve el numero de jaques de'sim_hjq', si
// no hay jaque de 'sim_hjq', devuelve cero.

int main(void)
{
  definir_diagonales();
  jugar_tateti();
  
  return 0;
}

void jugar_tateti(){
  int l, m;
  vaciar_tab();
  mostrar_tab();
  pedir_jugada(); 
  //primer jugada
  mostrar_tab();

  if(es_esquina(1,0)){
	  hacer_jugada(1,1);
	  mostrar_tab();
	  pedir_jugada();
	  //segunda jugada
	  mostrar_tab();
	  if(es_esquina(1,1)){
	    if(es_opuesto(1,0,1)){
		hacer_jugada(0,1);
		mostrar_tab();
		pedir_jugada();
		//tercer jugada
		mostrar_tab();
		exit(1);
	    }
	    if(!es_opuesto(1,0,1)){
	      ver_si_jaq1(SIMUSR);
	    }
	  }
	  if(es_medio(1,1)){
	    ver_si_jaq1(SIMUSR);
  };
  }

  if(es_centro(1,0)){
    hacer_jugada(0,0);
    mostrar_tab();
    pedir_jugada();
    mostrar_tab();
    ver_si_jaq1(SIMUSR);

  }
  if(es_medio(1,0)){
	  hacer_jugada(1,1);
	  mostrar_tab();
	  pedir_jugada();
	  mostrar_tab();
	  while(hay_jaq_de(SIMUSR)){
	      responder_jaque();
	      mostrar_tab();
	      pedir_jugada();
	      mostrar_tab();
    }
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
  char c;
  printf("Ingrese, separando con espacios:\n\n\n  Fila  Columna ");
  scanf("%d %d", &i, &j);
  /*  
while(a[i][j] != ' '){
    printf("\nEl casillero debe estar vacio...\n");
    printf("Elija otra opcion: \n");
    scanf("%d %d", &i, &j);
  }
  */
  a[i-1][j-1] = SIMUSR;
  jug[1][nro_jugada1][0] = i-1;
  jug[1][nro_jugada1][1] = j-1;
  ++nro_jugada1;
}
void hacer_jugada(int fila, int col){
	
	a[fila][col] = 'o';
	jug[0][nro_jugada0][0] = fila;
	jug[0][nro_jugada0][1] = col;
	++nro_jugada0;
}
void hacer_jugada_p(int diago, int celda){
	*diag[diago][celda] = SIMPC;
	if(diago<3){jug[0][nro_jugada0][0] = diago; jug[0][nro_jugada0][1] = celda;}
	if(2<diago&diago<6){jug[0][nro_jugada0][0] = celda; jug[0][nro_jugada0][1] = diago-3;}
	if(diago=6){jug[0][nro_jugada0][0] = jug[0][nro_jugada0][1] = celda;}
	if(diago=7){jug[0][nro_jugada0][0] = celda; jug[0][nro_jugada0][1] = 2-celda;}
	nro_jugada0++;

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
int es_esquina(int jugador, int jugada){
	return ((jug[jugador][jugada][0] != 1) & (jug[jugador][jugada][1] != 1));
}
int es_centro(int jugador, int jugada){
  if((jug[jugador][jugada][0] == 1) & (jug[jugador][jugada][1] == 1))
    return 1;
  else return 0;
}
int es_medio(int jugador, int jugada){
  if(((jug[jugador][jugada][0] == 1) | (jug[jugador][jugada][1] == 1)) & !es_centro(jugador, jugada))
    return 1;
  else return 0;
}
int es_opuesto(int jugador, int jugada_previa, int jugada_actual){
	return ((jug[jugador][jugada_previa][0] == 2-jug[jugador][jugada_actual][0]) 
		& (jug[jugador][jugada_previa][1] == 2-jug[jugador][jugada_actual][1]));
}
int chequear_jaque(char simbolo_j){
	/*Devuelve si hay o no jaque del jugador con simbolo 'simbolo_j'*/
	if(ubicar_diag_i(simbolo_j, 2) > 0)
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
int chequear_diag(int nro_diag, char simbolo_chd){
  /* Esta funcion es para ver cuantos simbolos de 
     un mismo tipo hay en una diagonal. */
  int l, m;
  for( l=m=0 ; l<3; ++l )
    if(*diag[nro_diag][l] == simbolo_chd)
		++m;
  return m;
}
int ubicar_diag_i(char simbolo_ud, int cantidad){
  int l=0, m=0;
  for(l=0;l<8;++l){
    if((chequear_diag(l, ' ') == 3-cantidad) & (chequear_diag(l, simbolo_ud) == cantidad))
      m = l + 1;
  }
  return m;
}
int chequear_ganador(){
  int l, m, gan;

	for(l=0; l<2; ++l){
	  for(m=0 ;m<8 ;++m){
	    if(chequear_diag(m, simbolos[l]) == 3){
	      gan = l;
	      return l;
	    }
	  }
	}
	return 2;
  }
void mirar_tab(){
  int l, m, cel = 0;

	if(chequear_ganador()<2){
		printf("Ganó el jugador %d", chequear_ganador());
		exit(1);
	}

	if(chequear_jaque(SIMPC)){
	  m = 0;
		for(l=0; l<3; ++l){
		  if(ubicar_diag_i(SIMPC, 2)){
		    m = ubicar_diag_i(SIMPC, 2)-1;
		    if(m>-1){
		      if(*diag[m][l] == ' ') cel = l;}
		  }// q devuelve ubicar?
		  hacer_jugada_p(ubicar_diag_i(SIMPC, 2)-1, cel);
		}
		}


	if(chequear_jaque(SIMUSR)){
	  m = 0;
		for(l=0; l<3; ++l){
		  if(ubicar_diag_i(SIMUSR, 2)){
		    m = ubicar_diag_i(SIMUSR, 2)-1;
		    if(m>-1){	
		      if(*diag[m][l] == ' ') cel = l;}
		  }
		  hacer_jugada_p(ubicar_diag_i(SIMUSR, 2)-1, cel);
		}
	}

}
 int ubicar_celda(int diag_uc, char sim_uc){
   int l, cel = 0;
   for(l=0;l<3;++l){
     if(*diag[diag_uc][l] == sim_uc) cel = l;
   }
   return cel;
 }
int hay_par(char sim_hp){
  int l, m, n=0;
  for(l=0; l<8; ++l){
    if(chequear_diag(l,sim_hp) == 2){
      ++n;
    }
  }
  return n;
}
int hay_jaq_de(char sim_hjd){
  int l, ret = 0 ;
    for(l=0; l<8; ++l){
      if((chequear_diag(l, sim_hjd)==2) & (chequear_diag(l, ' ' ) == 1))
	ret = 1;
    }
      return ret;
}
void responder_jaque(){
  int dia, cel;
  dia = ubicar_diag_i(SIMUSR, 2)-1;
  cel = ubicar_celda(dia, ' ');
  hacer_jugada_p( dia , cel );
}  
void ganar_jaq(){
  int dia, cel;
  dia = ubicar_diag_i(SIMPC, 2)-1;
  cel = ubicar_celda(dia, ' ');
  hacer_jugada_p( dia , cel );
}


void ver_si_jaq1(char sim_vsj){
  if(hay_jaq_de(SIMPC)) {
    ganar_jaq();
    mostrar_tab();
    printf("perdiste");
    exit(1);
  }

  while(hay_jaq_de(sim_vsj)){
    if(hay_jaq_de(SIMPC)) {
      ganar_jaq();
      mostrar_tab();
      printf("perdiste");
      exit(1);
    }

      responder_jaque();
      mostrar_tab();
      pedir_jugada();
      mostrar_tab();
    }
}
