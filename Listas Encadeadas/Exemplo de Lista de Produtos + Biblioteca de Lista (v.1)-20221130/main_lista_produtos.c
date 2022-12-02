#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Produto.h"


void mostra_p( void *x ){
	Produto *a = x;
	mostra_produto( *a );
}

int main(int argc, char *argv[]) {
	Lista l1;
	inicializa_lista( &l1, sizeof(Produto) );
	
	int op;
	
	Produto x;
	
	do{
		printf("1-Cadastrar\n2-Listar\n3-Sair\n");
		scanf("%d", &op);
		
		switch( op ){
			case 1:
				le_produto( &x );
				insere_fim( &l1, &x );
				break;
				
			case 2:
				mostra_lista( l1, mostra_p );
				break;			
		}
	
	}while( op != 3 );
	
	limpa_lista( &l1 );
	
	return 0;
}
