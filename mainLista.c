#include<stdio.h>
#include<stdlib.h>
#include"TADLista.h"
int main()
{
   Lista *k = (Lista*)malloc(sizeof(Lista));
   int i;
   printf("\n-1 - Sair\n");
   printf("1 - Inserir\n");
   printf("2 - Remover\n");
   printf("3 - Buscar\n");
   printf("4 - Tamanho\n");
   printf("5 - Imprimir\n");
   scanf("%i",&i);
   Menu(k,i);
   Saida(k);
   return 0;
}
