#include <stdio.h>

void imprimir(unsigned long size, char *s);

int main()
{

    imprimir(sizeof(signed char), "signed char");
    imprimir(sizeof(unsigned char), "unsigned char");
    imprimir(sizeof(char), "char");
    imprimir(sizeof(short int), "short int");
    imprimir(sizeof(unsigned short int), "unsigned short int");
    imprimir(sizeof(int), "int");
    imprimir(sizeof(long int), "long int");
    imprimir(sizeof(unsigned long int), "unsigned long int");
    imprimir(sizeof(long long int), "long long int");
    imprimir(sizeof(unsigned long long int), "unsigned long long int");
    imprimir(sizeof(float), "float");
    imprimir(sizeof(double), "double");
    imprimir(sizeof(long double), "long double");
    imprimir(sizeof(float), "float");
  
    unsigned short int tmp = 0;
    printf("\n un sh int: %d\n", --tmp);

    return 0;
}

void imprimir(unsigned long size, char *s)
{
    printf("sizeof(%s) es: %lu\n", s, size);
}
