#include <stdio.h>
#include "Pilha.h"

void concatena(Pilha *p1, Pilha *p2){
    int x;
    while(!(p2->topo == -1 )){
        desempilha(p2, &x);
        empilha(p1, x);
    }
}

int main(){

    Pilha p1, p2;

    inicializa_pilha(&p1);
    inicializa_pilha(&p2);

    empilha(&p1, 25);
    empilha(&p1, 36);
    empilha(&p2, 65);
    empilha(&p2, 87);
    empilha(&p1, 12);   

    mostra_pilha(p1);
    mostra_pilha(p2);

    concatena(&p1, &p2);

    mostra_pilha(p1);
    mostra_pilha(p2);

    return 0;
}