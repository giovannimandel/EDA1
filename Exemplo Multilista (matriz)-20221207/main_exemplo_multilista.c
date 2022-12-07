#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Lista matriz;
	inicializa_lista( &matriz, sizeof( Lista ) );
	
	int lin, col, i, j;
	printf("Quantas linhas? ");
	scanf("%d", &lin);
	printf("Quantas colunas? ");
	scanf("%d", &col);
	
	Lista sub;
	int valor;
	
	for( i = 0 ; i < lin ; i++ ){
		inicializa_lista( &sub, sizeof( int ) );
		for( j = 0 ; j < col ; j++ ){
			//printf("[%d,%d]: ", i, j);
			//scanf("%d", &valor );
			valor = rand() % 10000;
			insere_fim( &sub, &valor );
		}
		insere_fim( &matriz, &sub );
	}
	
	for( i = 0 ; i < lin ; i++ ){
		le_valor( matriz, &sub, i );
		for( j = 0 ; j < col ; j++ ){
			le_valor( sub, &valor, j );
			printf("%4d ", valor);
		}
		printf("\n");
	}
	
	for( i = 0 ; i < lin ; i++ ){
		le_valor( matriz, &sub, i );
		limpa_lista( &sub );
	}
	limpa_lista( &matriz );
	
	return 0;
}

