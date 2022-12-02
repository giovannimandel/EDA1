#include <stdio.h>
#include "Lista.h"  

void mostra_int(void* x){
    int *p = x;
    printf("%d\n", *p);
}
int main(){

    Lista l1, l2;
    int a = 2, b = 3, c = 4;
    int d = 5, e = 6, f = 7, g = 8; 
    inicializa_lista(&l1, sizeof(int));
    inicializa_lista(&l2, sizeof(int));

    // insere_inicio(&l1, &a); //2
    // insere_inicio(&l1, &b); //3
    // insere_inicio(&l1, &c); //4

    insere_inicio(&l2, &d); //5
    insere_inicio(&l2, &e); //6 
    insere_inicio(&l2, &f); //7
    insere_inicio(&l2, &g); //8


    mostra_lista(l1, mostra_int);
    mostra_lista(l2, mostra_int);

    concatena(&l1, &l2);

    mostra_lista(l1, mostra_int);
    mostra_lista(l2, mostra_int);

    return 0;
}