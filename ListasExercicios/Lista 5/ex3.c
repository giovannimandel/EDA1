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
    int a = 12, b = 6, c = 3;
    inicializa_lista(&l, sizeof(int));

    insere_fim(&l, &a);
    insere_fim(&l, &b);
    insere_fim(&l, &c);
    insere_fim(&l, &a);
    insere_fim(&l, &a);

    mostra_lista(l, mostra_int);
    mostra_lista(busca_todos(l, &a, compara), mostra_int);
    return 0;
}