#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main(int argc, char *argv[]) {
	Fila f1;
	
	inicializa_fila(&f1, 4);
	mostra_fila(f1);
	
	inserir(&f1, 2);
	inserir(&f1, 4);
	inserir(&f1, 8);
	inserir(&f1, 16);
	inserir(&f1, 32);
	mostra_fila(f1);
	
	int x;
	
	remover(&f1, &x);
	remover(&f1, &x);
	mostra_fila(f1);
	
	inserir(&f1, 32);
	inserir(&f1, 64);
	mostra_fila(f1);
	
	desaloca_fila(&f1);
	
	return 0;
}
