#include"TADLista.h"
#include<stdio.h>
#include<stdlib.h>

void criaLista( Lista *L)
{
   L->inicio=NULL;
   L->fim=NULL; 
}

void Inserir( Lista *L, int n)
{
   Celula *nova = (Celula*)malloc(sizeof(Celula));
   nova->valor=n;
   if(L->inicio==NULL&&L->fim==NULL)
   {
      L->inicio=nova;
      L->fim=nova;
   }
   else
   {
      nova->proximo=L->fim;
      L->fim=nova;
   }
}

void Remover (Lista *L, int n)
{
   Celula *temp1, *temp2;
   temp1= L->fim;
   temp2= L->fim;
   if(L->inicio==NULL&&L->fim==NULL)
   {
      printf("Lista Vazia!");
   }
   else
   {
      while(temp1!=NULL)
      {
         if(temp1->valor==n)
         {
            if(temp1==L->inicio&&temp1==L->fim)
            {
               free(temp1);
               free(temp2);
               L->inicio = NULL;
               L->fim = NULL;
               exit(1);
            }
            if(temp1==L->fim)
            {
               L->fim = temp1->proximo;
               free(temp1);
               free(temp2);
               exit(1);
            }
            if(temp1!=temp2&&temp1->proximo!=NULL)
            {
               temp2->proximo = temp1->proximo;
               free(temp1);
               exit(1);
            }
            if(temp1!=temp2&&temp1==L->inicio)
            {
               L->inicio = temp2;
               free(temp1);
               exit(1);
            }  
         }
         else
         {
            if(temp1==temp2)
            {
               temp1 = temp1->proximo;
            }
            else
            {
               temp1 = temp1->proximo;
               temp2 = temp2->proximo;
            }
         }
         
      }
   }
   if(temp1==NULL&&temp1->valor!=n)
   {
      printf("Este Elemento Não Existe Na Lista!");
   }
}

int Tamanho( Lista *L)
{
   Celula *temp = L->fim;
   int i=0;
      if(L->fim==NULL&&L->inicio==NULL)
      {
         return i;
      }
      else
      {
         while(temp!=NULL)
         {
            i++;
            temp=temp->proximo;
         }
      }
   return i;     
}

int Busca(Lista *L, int n)
{
   Celula *temp = L->fim;
   while(temp!=NULL)
   {
      if(temp->valor==n)
      {
         return 1;
      }
      else
      {
         return 2;
      }
   }    
}

void Imprime( Lista *L)
{
   if(L->inicio==NULL&&L->fim==NULL)
   {
      printf("Lista Vazia!");
   }
   else
   {
      Celula *temp = L->fim;
      printf("|");
      printf("%i->",temp->valor);
      while(temp!=NULL)
      {
         temp=temp->proximo;
         printf("%i",temp->valor);
         if(temp->proximo!=NULL)
         {
            printf("->");
         }
         else
         {
            printf("|");
         }
      }
   }
}

void Menu (Lista *L, int j)
{
   int i,a;
   while(j!=-1)
   {
      switch(j)
      {
         case 1:
            scanf("%i",&i);
            Inserir(L,i);

         case 2:
            scanf("%i",&i);
            Remover(L,i);
 
         case 3:
            scanf("%i",&i);
            a = Busca(L,i);
            if(a==1)
            {
               printf("Existe o valor");
            }
            if(a==2)
            {
               printf("Este Elemento Não Existe Na Lista!");
            } 

        case 4:
           i = Tamanho(L);
        
        case 5:
           Imprime(L);
        default:
           printf("Opcao invalida"); 
      }
      printf("\n-1 - Sair\n");
      printf("1 - Inserir\n");
      printf("2 - Remover\n");
      printf("3 - Buscar\n");
      printf("4 - Tamanho\n");
      printf("5 - Imprimir\n");
      scanf("%i",&j);
      Menu(L,j);
   }
}

void Saida(Lista *L)
{
   Celula *temp;
   Celula *temp2;
   if(L->inicio==NULL&&L->fim==NULL)
   {
      free(L);
   }
   else
   {
      temp = L->fim;
      if(temp->proximo==NULL)
      {
         free(temp);
         free(L);
      }
      else
      {
         while(L->inicio!=NULL&&L->fim!=NULL)
         {
            while(temp!=NULL)
            {
               temp=temp->proximo;
               temp2 = L->fim;
               free(temp2);
               L->fim = temp;
               if(temp==L->inicio)
               {
                  L->inicio = NULL;
                  L->fim = NULL;
                  free(temp);
               }
            }
         }
         free(L);
      }
    } 
}
