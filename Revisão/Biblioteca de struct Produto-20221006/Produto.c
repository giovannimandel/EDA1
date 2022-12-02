#include <stdio.h>
#include "Produto.h"

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

