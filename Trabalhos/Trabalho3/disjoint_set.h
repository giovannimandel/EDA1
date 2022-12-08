//Elemento da Lista
typedef struct ele{
    void *info;
    struct ele *proximo;
}Elemento;

//Lista (elemento da multilista)
typedef struct{
    Elemento *cabeca;
    int tamInfo, qtd;
}Lista;

//Multilista simulando a estrutura uniao-busca
typedef struct{
    Lista *cabeca;
    int tamInfo, qtd;
}Multilista;





