#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto{
	int codigo;
	char descricao[20];
	float preco;
};

int main(int argc, char *argv[]) {
	struct Produto x = { 666, "Nada", 1234};
	
	printf("(%d, %s, R$%.2f)\n", x.codigo, x.descricao, x.preco);
	
	x.codigo = 123;
	strcpy( x.descricao, "Caderno" );
	x.preco = 10;
	
	printf("(%d, %s, R$%.2f)\n", x.codigo, x.descricao, x.preco);
	
	scanf("%d", &x.codigo );
	scanf("%s", x.descricao );
	scanf("%f", &x.preco );
	
	printf("X(%d, %s, R$%.2f)\n", x.codigo, x.descricao, x.preco);
	
	struct Produto y;
	
	y = x;
	
	printf("Y(%d, %s, R$%.2f)\n", y.codigo, y.descricao, y.preco);

	
	return 0;
}
