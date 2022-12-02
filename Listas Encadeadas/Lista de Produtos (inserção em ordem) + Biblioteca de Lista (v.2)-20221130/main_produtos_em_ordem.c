#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Produto.h"


void mostra_p( void *x ){
	Produto *a = x;
	mostra_produto( *a );
}

int compara_produto_codigo( void *x, void *y ){
	Produto *a = x, *b = y;
	return a->codigo - b->codigo;
}

int compara_produto_descricao( void *x, void *y ){
	Produto *a = x, *b = y;
	return strcmp( a->descricao, b->descricao );
}

int main(int argc, char *argv[]) {
	Lista l1;
	inicializa_lista( &l1, sizeof(Produto) );
	
	int op, idx;
	int (*comp)(void*, void*);
	
	printf("Informe o criterio de ordenacao (1-por codigo ou 2-por descricao): ");
	scanf("%d", &op);
	if( op == 1 )
		comp = compara_produto_codigo;
	else
		comp = compara_produto_descricao;
	
	Produto x;
	
	do{
		system("cls");
		printf("1-Cadastrar (em ordem)\n2-Listar\n3-Sair\n");
		scanf("%d", &op);
		
		switch( op ){
			case 1:
				le_produto( &x );
				insere_ordem( &l1, &x, comp );
				break;
				
			case 2:
				mostra_lista( l1, mostra_p );
				system("pause");
				break;			
		}
	
	}while( op != 3 );
	
	limpa_lista( &l1 );
	
	return 0;
}

