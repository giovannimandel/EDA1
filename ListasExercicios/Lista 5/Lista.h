#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERRO_LISTA_VAZIA -1
#define ERRO_POS_INVALIDA -2

typedef struct ele{
    void *info;
    struct ele *proximo;
} Elemento;

typedef struct {
    Elemento *cabeca;
    int tamInfo, qtd;
} Lista;


void inicializa_lista(Lista *p, int t);
int lista_vazia (Lista l);
int insere_inicio(Lista *p, void *info);
int remove_inicio(Lista *p, void *info);
void mostra_lista(Lista l,void (*mostra) (void *) );
int conta_elementos(Lista l);