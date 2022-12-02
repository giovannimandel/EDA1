#define ERRO_COORD_INVALIDA -1

typedef struct{
	int **dados;
	int lin, col;
} Matriz;

void inicializa_matriz( Matriz *p, int l, int c );
void mostra_matriz( Matriz m );
void libera_matriz( Matriz *p );
int set_valor( Matriz *p, int i, int j, int v );

