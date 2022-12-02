#include <stdio.h>
#include "Pilha.h"

int main(){

    int ndec = 0, rest = 0, quoc = 0, x;
    Pilha p;

    printf("Valor em decimal:\n");
    scanf("%d", &ndec);

    inicializa_pilha(&p);
    do{
        quoc = ndec / 2;
        rest = ndec % 2;
        empilha(&p, rest);
        ndec = quoc;
    }while(quoc != 0);
    printf("em binario:\n");
    while(!pilha_vazia(p)){
        desempilha(&p, &x);
        printf(" %d ", x);
    }


    return 0;
}