#include <stdio.h>
#include <stdlib.h>

void mostra_vetor( int *p, int n, char *nome );
void ordena( int *p, int n );

int main(int argc, char *argv[]) {
	int n, i, x;
	
	char nome[30];
	printf("Digite o nome do arquivo de entrada: ");
	scanf("%s", nome);
	
	FILE *f = fopen( nome , "rt" );
	if( f == NULL ){
		printf("Arquivo nao encontrado!\n");
		return -1;
	}
	
	fscanf( f , "%d", &n);
	
	int *p = malloc( sizeof(int) * n );
	
	for( i = 0 ; i < n ; i++ ){
		fscanf( f , "%d", &p[i]);
	}
	
	fclose( f );
	
	mostra_vetor( p, n, "Vetor original:" );
	
	ordena( p , n );
	
	mostra_vetor( p, n , "Vetor ordenado:" );
	
	printf("Digite o nome do arquivo de saida: ");
	scanf("%s", nome);
	
	f = fopen( nome , "wt" );
	
	fprintf( f, "%d\n", n );
	for( i = 0 ; i < n ; i++ ){
		fprintf( f, "%d\n", p[i]);
	}
	
	fclose( f );
	
	system( nome );
	
	free( p );
	
	return 0;
}

void mostra_vetor( int *p, int n, char *nome ){
	printf("%s\n", nome);
	int i;
	for( i = 0 ; i < n ; i++ ){
		printf("%d: %d\n", i+1, p[i]);
	}
	printf("\n");
}

void ordena( int *p, int n ){
	int i;
	for( i = 0 ; i < n-1 ; i++ ){
		int i_menor = i, j;
		for( j = i + 1 ; j < n ; j++ ){
			if( p[j] < p[i_menor] )
				i_menor = j;
		}
		int aux = p[i];
		p[i] = p[i_menor];
		p[i_menor] = aux;
	}
}

