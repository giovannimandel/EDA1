#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int codigo;
	char descricao[20];
	float preco;
} Produto;

void mostra_produto( Produto x );
void le_produto( Produto *p );
Produto retorna_produto( Produto *v, int i );

int main(int argc, char *argv[]) {
	
	Produto k = { 111, "Caneta", 10 };
	mostra_produto( k );
	/*
	le_produto( &k );
	mostra_produto( k );*/
	
	int n, i;
	printf("Quantos produtos? ");
	scanf("%d", &n);
	
	Produto *p = malloc( sizeof(Produto) * n);
	
	for( i = 0 ; i < n ; i++ ){
		printf("Dados do %do produto:\n", i+1);
		le_produto( p + i ); // &p[i]
	}
	
	for( i = 0 ; i < n ; i++ ){
		printf("Produto %d: ", i);
		mostra_produto( p[i] );
	}
	
	int idx;
	printf("Digite um indice: ");
	scanf("%d", &idx);
	
	k = retorna_produto( p, idx );
	mostra_produto( k );
	
	free( p );
	
	return 0;
}

void mostra_produto( Produto x ){
	printf("(%d, %s, R$%.2f)\n",
			x.codigo, x.descricao, x.preco);
}

void le_produto( Produto *p ){
	printf("Digite o codigo: ");
	scanf("%d", &p->codigo);
	printf("Digite a descricao: ");
	scanf("%s", p->descricao);
	printf("Digite o preco: ");
	scanf("%f", &p->preco);
}

Produto retorna_produto( Produto *v, int i ){
	return v[i];
}

