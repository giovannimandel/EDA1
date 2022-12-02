#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

void mostra_float(void *x){ //mostra um float a partir de um void*
    printf("%.2f\n", *(float *)x);
}

int main(){

    Lista l;
    float x = 1.5, y = 3.5, z = 4.7, a = 59.4;

    inicializa_lista(&l, sizeof(float));
    
    insere_inicio(&l, &x);
    insere_inicio(&l, &y);
    insere_inicio(&l, &z);
    insere_inicio(&l, &a);

    //remove_inicio(&l, &x);
    mostra_lista(l, mostra_float);
    conta_elementos(l);
    return 0;
}