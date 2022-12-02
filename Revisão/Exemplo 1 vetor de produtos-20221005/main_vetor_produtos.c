#include <stdio.h>
#include <stdlib.h>

#define MAX 3

/*
struct produto{
	int codigo;
	char descricao[20];
	float preco;
};

typedef struct produto Produto;
*/

typedef struct {
	int codigo;
	char descricao[20];
	float preco;
} Produto;

typedef int inteiro;

int main(int argc, char *argv[]) {
	
	Produto v[MAX] = { { 12, "Cafe", 10 },
							{ 34, "Bolo Cenoura", 5	},
							{ 45, "Capuccino", 10 } };
	
	inteiro i; // int
	for( i = 0 ; i < MAX ; i++ ){
		printf("Produto %d: (%d, %s, R$%.2f)\n",
				i+1, v[i].codigo, v[i].descricao, v[i].preco);
	}

	Produto x;

	
	return 0;
}
