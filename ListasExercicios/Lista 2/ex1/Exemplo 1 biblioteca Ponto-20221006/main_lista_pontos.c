#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Ponto.h"

int main(int argc, char *argv[]) {
	/*
	Ponto p1, p2;
	
	inicializa_ponto( &p1, 1, 1 );
	inicializa_ponto( &p2, 0, 0 );
	mostra_ponto( p1 );
	mostra_ponto( p2 );
	printf("Distancia: %f\n", calcula_distancia( p1, p2) );
	*/
	
	int n, i;
	printf("Quantos pontos? ");
	scanf("%d", &n);
	
	Ponto *lista = malloc( sizeof( Ponto ) * n );
	
	srand( time(0) );
	for( i = 0 ; i < n ; i++ ){
		inicializa_ponto( &lista[i], rand()%100, rand()%100 );
	}
	
	for( i = 0 ; i < n ; i++ ){
		printf("Ponto %d=", i+1);
		mostra_ponto( lista[i] );
		printf("--> Usando os getters: (%f, %f)\n", get_x( lista[i] ), get_y( lista[i] ));
	}
	
	for( i = 0 ; i < n-1 ; i++ ){
		printf("Distancia entre P%d e P%d: %.2f\n", i+1, i+2, calcula_distancia( lista[i], lista[i+1] ));
	}
	
	free( lista );

	return 0;
}
