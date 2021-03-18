#include  <stdio.h>
#include <stdlib.h>

struct Celula {
    int valor;
    struct Celula* proximo;
};

typedef struct Celula Celula;

struct Lista {
    Celula* inicio;
    Celula* fim;
};

typedef struct Lista Lista;

// FUNCAO PARA INCIALIZAR INICIO E FIM COMO NULL
void criaLista( Lista *L); 

// FUNCAO PARA INSERIR UM ELEMENTO NA LISTA (INSERIR NO INCIO)
void Inserir( Lista *L, int n);

// FUNCAO PARA REMOVER UM ELEMENTO QUALQUER, PASSADO PELO USUARIO, DA LISTA
void Remover(Lista *L, int n);

// FUNCAO PARA MOSTRAR O TAMANHO DA LISTA
int Tamanho(Lista *L);

// FUNCAO DE BUSCA PARA MOSTRAR A POSICAO DO ELEMENTO DESEJADO, NA LISTA, SE EXISTIR
int Busca(Lista *L, int n);

//FUNCAO PARA IMPRIMIR TODOS OS ELEMENTOS DA LISTA
void Imprime(Lista *L);

// FUNCAO PARA MOSTRAR NA TELA O MENU COM AS OPERACOES PARA/COM A LISTA
void Menu(Lista *L, int j);

void Saida(Lista *L);
