# include <stdio.h>
# include <stdlib.h>
# include <string.h>

unsigned int ui = 1;
unsigned short int ushorti = 1;
unsigned long int ulongi = 1;

int main(void) 
{
  short int shi, shco;
  for(shi = 1, shco = 0; shi > shco ; ++shi, ++shco)
    ;
  printf("\nShort int max: %d \n", shco);  
  for(shco = 0, shi = 1; shco < shi;--shi, --shco)
    ;
  printf("\nInt min: %d \n", shi);  

  int i, co;
  for(i = 1, co = 0; i > co ; ++i, ++co)
    ;
  printf("\nInt max: %d \n", co);  
  for(co = 0, i = 1; co < i;--i, --co)
    ;
  printf("\nInt min: %d \n", i);  

 long int loi, loco;
  for(loi = 1, loco = 0; loi > loco ; ++loi, ++loco)
    ;
  printf("\nLoort int max: %ld \n", loco);  
  for(loco = 0, loi = 1; loco < loi;--loi, --loco)
    ;
  printf("\nInt min: %ld \n", loi);  


  /*long int lco = 0;
  while(i > lco)
    ++i, ++lco;
  printf("\nLong Int max: %ld \n", lco);  
  return 0;

  lco = 0;
  while(lco < i)
    --i, --lco;
  printf("\nLong Int min: %ld \n", lco);  
  */


  return 0;

}
