#include <stdio.h>
#include <stdlib.h>
#include "Produto.h"

int main(int argc, char *argv[]) {
	
	Produto k = { 111, "Caneta", 10 };
	mostra_produto( k );
	/*
	le_produto( &k );
	mostra_produto( k );*/
	
	int n, i;
	printf("Quantos produtos? ");
	scanf("%d", &n);
	
	Produto *p = malloc( sizeof(Produto) * n);
	
	for( i = 0 ; i < n ; i++ ){
		printf("Dados do %do produto:\n", i+1);
		le_produto( p + i ); // &p[i]
	}
	
	for( i = 0 ; i < n ; i++ ){
		printf("Produto %d: ", i);
		mostra_produto( p[i] );
	}
	
	int idx;
	printf("Digite um indice: ");
	scanf("%d", &idx);
	
	k = retorna_produto( p, idx );
	mostra_produto( k );
	
	free( p );
	
	return 0;
}

