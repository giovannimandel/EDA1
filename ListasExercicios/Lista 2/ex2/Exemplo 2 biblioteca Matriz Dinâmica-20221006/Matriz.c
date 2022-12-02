#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

void inicializa_matriz( Matriz *p, int l, int c ){
	p->lin = l;
	p->col = c;
	p->dados = malloc( sizeof( int* ) * l );
	int i, j;
	for( i = 0 ; i < l ; i++ ){
		p->dados[i] = malloc( sizeof( int ) * c );
		for( j = 0 ; j < c ; j++ )
			p->dados[i][j] = 0;
	}
}

void mostra_matriz( Matriz m ){
	int i, j;
	printf("Dados da matriz (%dx%d):\n", m.lin, m.col);
	for( i = 0 ; i < m.lin ; i++ ){
		for( j = 0 ; j < m.col ; j++ ){
			printf("%d ", m.dados[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void libera_matriz( Matriz *p ){
	int i;
	for( i = 0 ; i < p->lin ; i++ )
		free( p->dados[i] );
	free( p->dados );
}

int set_valor( Matriz *p, int i, int j, int v ){
	if( i >= p->lin || j >= p->col )
		return ERRO_COORD_INVALIDA;
	
	p->dados[i][j] = v;
	return 1; // Sucesso;
}

