#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main(int argc, char *argv[]) {
	Pilha p1;
	
	inicializa_pilha( &p1 );
	mostra_pilha( p1 );
	
	int i, x;
	
	for( i = 0 ; i < 5 ; i++ ){
		x = rand();
		empilha( &p1, x );
		mostra_pilha( p1 );
	}
	
	for( i = 0 ; i < 5 ; i++ ){
		desempilha( &p1, &x );
		printf("Valor desempilhado: %d\n", x);
		mostra_pilha( p1 );
	}
	
	return 0;
}
