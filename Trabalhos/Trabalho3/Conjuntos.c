#include <stdio.h>
#include "Conjuntos.h"


void inicializa_matriz( Matriz *p, int l, int c ){
	inicializa_lista( &p->dados, sizeof( Lista ) );
	int i, j;
	Lista sub;
	for( i = 0 ; i < l ; i ++ ){
		inicializa_lista( &sub, sizeof( int ) );
		for( j = 0 ; j < c ; j++ ){
			int valor = 0;
			insere_fim( &sub, &valor );
		}
		insere_fim( &p->dados, &sub );
	}	
}

void mostra_matriz( Matriz m ){
	int i, j, valor;
	Lista sub;
	for( i = 0 ; le_valor( m.dados, &sub, i ) != ERRO_POS_INVALIDA ; i ++ ){
		for( j = 0 ; le_valor( sub, &valor, j ) != ERRO_POS_INVALIDA ; j++ ){
			printf("%4d ", valor);
		}
		printf("\n");
	}
	printf("\n");	
}


int set_valor( Matriz *p, int i, int j, int v ){
	Lista sub;
	if( le_valor( p->dados, &sub, i ) == ERRO_POS_INVALIDA )
		return ERRO_COORD_INVALIDA;
	
	if( modifica_valor( sub, &v, j ) == ERRO_POS_INVALIDA )
		return ERRO_COORD_INVALIDA;
	
	return 1; // Sucesso!
}

void inicializa_conjuntos(Matriz *p){
	inicializa_lista(&p->dados, sizeof(Lista));
}

int busca_conjunto(Matriz u, int x){
	
	Lista l;
	int i;
	for(i=0; le_valor(u.dados, &l, i) != ERRO_POS_INVALIDA; i++){
		if(busca(&l, &u, compara) != -1)
			return i;
	}
	return -1;
}

int cria_conjunto(Matriz *p, int v){
	if(busca_conjunto(*p, v) != -1)
		return 0;
	
	Lista l;
	inicializa_lista(&l, sizeof(int));
	insere_inicio(&l, &v);
	insere_fim(&p->dados, &l);

	return 1;
}

int compara(void *x, void *y){
	int *a = x, *b = y;
	return *a - *b;
}

int carrega_arquivo( char *nome, Matriz *p ){
	Lista sub;

	FILE *f = fopen( nome, "rt" );
	if( f == NULL )
		return 0;
	
	int l, c, i, j;
	fscanf( f, "%d%d", &l, &c);
	inicializa_matriz( p, l, c );
	for( i = 0 ; i < l ; i++ )
		for( j = 0 ; j < c ; j++ )
			fscanf( f , "%d", &p->dados );
	
	fclose( f );
	return 1;
}