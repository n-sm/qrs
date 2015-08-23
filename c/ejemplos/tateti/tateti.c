# include <stdio.h>

char c, a[3][3];
int i, j, k, nj;

void vaciar_tab();
void tablero();
void pedir_jugada();

int main(void)
{
  vaciar_tab();
  tablero();
  pedir_jugada(); 
  tablero();
  /* Falta esta parte...*/

  return 0;
}

void tablero(){
  printf("\n%s", " _____");
  printf("\n%s%c%s%c%s%c%s", "|", a[0][0],"|", a[0][1], "|", a[0][2], "|");
  printf("\n%s%c%s%c%s%c%s", "|", a[1][0],"|", a[1][1], "|", a[1][2], "|");
  printf("\n%s%c%s%c%s%c%s", "|", a[2][0],"|", a[2][1], "|", a[2][2], "|");
  printf("\n%s", "-------");
  printf("\n");
}

void vaciar_tab(){
  for(i = 0; i < 3; ++i) {
    for(j = 0; j < 3; ++j) {
      a[i][j] = ' ';
    }
  }
}


void pedir_jugada(){
  printf("Ingrese, separando con espacios:\n\n\n  Fila  Columna  Jugada (X o O)");
  scanf("%d %d %c", &i, &j, &c);
  a[i-1][j-1] = c;
}

int contar_blancos(){
  k = 0;
  for(i = 0; i < 3; ++i) {
    for(j = 0; j < 3; ++j) {
      if(a[i][j] == ' ')
	++k;
    }
  }
 return k;
}

/*
voy por aca. Esta funcion va a ser para corroborar que todavia
nadie haya ganado.

void chequear_fin(){
      
}  
*/
