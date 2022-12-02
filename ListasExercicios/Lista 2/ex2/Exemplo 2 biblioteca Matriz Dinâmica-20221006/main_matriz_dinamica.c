#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

int main(int argc, char *argv[]) {
	Matriz m;
	
	inicializa_matriz( &m , 4, 5 );
	mostra_matriz( m );
	set_valor( &m, 0, 2, 6 );
	mostra_matriz( m );
	
	int i, j, v;
	printf("Digite a linha e a coluna:\n");
	scanf("%d%d", &i, &j);
	printf("Digite o valor: ");
	scanf("%d", &v);
	
	if( set_valor( &m, i, j, v ) == ERRO_COORD_INVALIDA )
		printf("Coordenadas invalidas!\n");
	
	mostra_matriz( m );	
	
	libera_matriz( &m );
	
	return 0;
}
