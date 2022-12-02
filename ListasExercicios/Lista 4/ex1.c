#include <stdio.h>
#include "Fila.h"
#include "Pilha.h"

int main(){

    int a, b;
    Fila f;
    inicializa_fila(&f, 5);
    Pilha p;
    inicializa_pilha(&p);

    for(int i = 0; i < 5; i++){
        scanf("%d", &a);
        inserir(&f, a);
        empilha(&p, a);
    }

    mostra_fila(f);
    printf("\n");
    while(!fila_vazia(f)){
        remover(&f, &b);
    }

    while(!pilha_vazia(p)){
        desempilha(&p, &b);
        inserir(&f, b);
    }

    mostra_fila(f);

    return 0;
}