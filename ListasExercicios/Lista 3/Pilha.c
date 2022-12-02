#include <stdio.h>
#include "Pilha.h"

void inicializa_pilha(Pilha *p){
    p->topo = -1;
}

int pilha_vazia(Pilha p){
    return p.topo == -1;
}

int pilha_cheia(Pilha p){
    return p.topo == MAX_PILHA - 1;
}

int empilha(Pilha *p, int info){
    if(pilha_cheia(*p)) return ERRO_PILHA_CHEIA;

    p->topo++;
    p->dados[p->topo] = info;
    return 1; // sucesso    
}

int desempilha(Pilha *p, int *info){
    if(pilha_vazia(*p)) return ERRO_PILHA_VAZIA;

    *info = p->dados[p->topo]; //coloca em *info o valor desempilhado
    p->topo--;
    return 1; // sucesso
}
int le_topo(Pilha p, int *info){
    if(pilha_vazia(p)) return ERRO_PILHA_VAZIA;

    *info = p.dados[p.topo];
    return 1; // sucesso
}

void mostra_pilha(Pilha p){
    if(pilha_vazia(p))
        printf("Pilha vazia\n");
    else{
        int i;
        printf("Dados da pilha:\n");
        for(i = 0; i <=p.topo; i++)
            printf("%d\n", p.dados[i]);
    }
    printf("---------------\n");    
}

int empilha_char(Pilha_char *p, char info){
    if(pilha_cheia_char(*p)) return ERRO_PILHA_CHEIA;

    p->topo++;
    p->dados[p->topo] = info;
    return 1; // sucesso    
}

int desempilha_char(Pilha_char *p, char *info){
    if(pilha_vazia_char(*p)) return ERRO_PILHA_VAZIA;

    *info = p->dados[p->topo]; //coloca em *info o valor desempilhado
    p->topo--;
    return 1; // sucesso
}

void mostra_pilha_char(Pilha_char p){
    if(pilha_vazia_char(p))
        printf("Pilha vazia\n");
    else{
        int i;
        printf("Dados da pilha:\n");
        for(i = 0; i <=p.topo; i++)
            printf("%c\n", p.dados[i]);
    }
    printf("---------------\n");    
}

int pilha_vazia_char(Pilha_char p){
    return p.topo == -1;
}

int pilha_cheia_char(Pilha_char p){
    return p.topo == MAX_PILHA - 1;
}

int le_topo_char(Pilha_char p, char *info){
    if(pilha_vazia_char(p)) return ERRO_PILHA_VAZIA;

    *info = p.dados[p.topo];
    return 1; // sucesso
}

void inicializa_pilha_char(Pilha_char *p){
    p->topo = -1;
}