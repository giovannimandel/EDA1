#include <stdio.h>
#include <stdlib.h>
#include "Matriz_Lista.h"

int main(int argc, char *argv[]) {
	Matriz m;
	
	inicializa_matriz( &m, 6, 6 );
	
	mostra_matriz( m );
	
	set_valor( &m, 1, 2, 16 );
	
	mostra_matriz( m );
	
	return 0;
}
