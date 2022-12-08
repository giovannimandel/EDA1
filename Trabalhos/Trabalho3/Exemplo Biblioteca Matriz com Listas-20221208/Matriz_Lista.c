#include "Matriz_Lista.h"
#include <stdio.h>

void inicializa_matriz( Matriz *p, int l, int c ){
	inicializa_lista( &p->dados, sizeof( Lista ) );
	int i, j;
	Lista sub;
	for( i = 0 ; i < l ; i ++ ){
		inicializa_lista( &sub, sizeof( int ) );
		for( j = 0 ; j < c ; j++ ){
			int valor = 0;
			insere_fim( &sub, &valor );
		}
		insere_fim( &p->dados, &sub );
	}	
}

void mostra_matriz( Matriz m ){
	int i, j, valor;
	Lista sub;
	for( i = 0 ; le_valor( m.dados, &sub, i ) != ERRO_POS_INVALIDA ; i ++ ){
		for( j = 0 ; le_valor( sub, &valor, j ) != ERRO_POS_INVALIDA ; j++ ){
			printf("%4d ", valor);
		}
		printf("\n");
	}
	printf("\n");	
}


int set_valor( Matriz *p, int i, int j, int v ){
	Lista sub;
	if( le_valor( p->dados, &sub, i ) == ERRO_POS_INVALIDA )
		return ERRO_COORD_INVALIDA;
	
	if( modifica_valor( sub, &v, j ) == ERRO_POS_INVALIDA )
		return ERRO_COORD_INVALIDA;
	
	return 1; // Sucesso!
}


