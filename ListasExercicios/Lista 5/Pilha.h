#define MAX_PILHA 50
#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2

typedef struct{
    int dados[MAX_PILHA];
    int topo;
} Pilha;

typedef struct{
    char dados[MAX_PILHA];
    int topo;
} Pilha_char;

void inicializa_pilha(Pilha *p);
int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);
int empilha(Pilha *p, int info);
int desempilha(Pilha*p, int *info);
int le_topo(Pilha p, int *info);
void mostra_pilha(Pilha p);

int empilha_char(Pilha_char *p, char info);
int desempilha_char(Pilha_char *p, char *info);
void mostra_pilha_char(Pilha_char p);
int pilha_cheia_char(Pilha_char p);
int pilha_vazia_char(Pilha_char p);
int le_topo_char(Pilha_char p, char *info);
void inicializa_pilha_char(Pilha_char *p);