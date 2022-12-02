#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

int main(int argc, char *argv[]) {
	 Matriz a, b, c, m;
	
	if( !carrega_arquivo( "m1.txt", &a ) ){
		printf("Arquivo nao encontrado!\n");
		return -1;
	}
	
	if( !carrega_arquivo( "m2.txt", &b ) ){
		printf("Arquivo nao encontrado!\n");
		return -1;
	}
	
	if( sao_iguais( a, b ) )
		printf("Matrizes iguais!\n");
	else
		printf("Matrizes diferentes!\n");
	
	if( soma_matrizes( a, b, &c ) == MATRIZES_INCOMPATIVEIS )
		printf("Matrizes incompativeis!\n");
	else{
		salva_arquivo( "m3.txt", c );
		system( "m3.txt" );
		libera_matriz( &c );
	}
	libera_matriz( &a );
	libera_matriz( &b );	
	
	
	// inicializa_matriz( &m , 4, 5 );
	// mostra_matriz( m );
	// set_valor( &m, 0, 2, 6 );
	// mostra_matriz( m );
	
	// int x;
	// get_valor( m, 0, 2, &x );
	
	// printf("Valor lido: %d\n\n", x);
	
	// int i, j, v;
	// printf("Digite a linha e a coluna:\n");
	// scanf("%d%d", &i, &j);
	// printf("Digite o valor: ");
	// scanf("%d", &v);
	
	// if( set_valor( &m, i, j, v ) == ERRO_COORD_INVALIDA )
	// 	printf("Coordenadas invalidas!\n");
	
	// mostra_matriz( m );	
	
	// libera_matriz( &m );
	
	return 0;
}
