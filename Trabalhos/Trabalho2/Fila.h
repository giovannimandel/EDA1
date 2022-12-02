
#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2

typedef struct{
   int *dados;     // dados da fila 
   int inicio;     // indice do inicio da fila
   int n;          // quantidade de elementos da fila
   int capacidade; // capacidade do vetor de dados
} Fila;

void inicializa_fila ( Fila *p, int c );
int fila_vazia ( Fila f );
int fila_cheia ( Fila f );
int inserir ( Fila *p, int info );
int remover ( Fila *p, int *info );
void mostra_fila ( Fila f );
void desaloca_fila( Fila *p );

