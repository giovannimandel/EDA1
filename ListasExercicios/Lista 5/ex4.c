#include <stdio.h>
#include "Lista.h"

int compara(void *x, void *y){
    int *a = x, *b = y;
    return *a - *b;
}

void mostra_int( void *x ){ // mostra um int...
    printf("%d\n", *(int *)x ); // a partir de um void*
}

int main(){

    Lista l;
    int a = 1, b = 2, c = 3, d = 4;
    int k = 1;
    int f = 69;
    inicializa_lista(&l, sizeof(int));

    insere_inicio(&l, &a);
    insere_inicio(&l, &b);
    insere_inicio(&l, &c);
    insere_inicio(&l, &d);

    mostra_lista(l, mostra_int);

    inverte_com_pilha(&l);
    
    mostra_lista(l, mostra_int);

    return 0;
}