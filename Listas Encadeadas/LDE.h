// Constantes de erro
#define ERRO_LDE_VAZIA	-1
#define ERRO_POS_INVALIDA	-2

// Elemento de LDE
typedef struct eleDuplo {
	void *info;
	struct eleDuplo *ant, *suc;

} EleDuplo;

// Cabeçalho de LDE
typedef struct {
	eleDuplo *cabeca;
	int tamInfo, qtd;
} LDE;

void inicializa_LDE( LDE *p, int t );
int LDE_vazia ( LDE l );
int insere_inicio( LDE *p, void *info );
int remove_inicio( LDE *p, void *info );
int insere_fim( LDE *p, void *info );
int remove_fim( LDE *p, void *info );
int insere_pos( LDE *p, void *info , int pos );
int remove_pos( LDE *p, void *info , int pos );
int le_valor( LDE l, void *info , int pos );
int modifica_valor( LDE l, void *info , int pos );
void mostra_LDE( LDE l, void (*mostra)(void *) );
void limpa_LDE( LDE *l );
int insere_ordem( LDE *p, void *info, int (*compara)(void*, void*) );

int conta_elementos( LDE l ); // Função inútil na prática, pois temos o campo 'qtd'.

