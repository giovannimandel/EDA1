//Elemento da Lista
typedef struct ele{
    void *info;
    struct ele *proximo;
}Elemento;

//Lista (elemento da multilista)
typedef struct{
    Elemento *cabeca;

}Lista;

//Multilista simulando a estrutura uniao-busca
typedef struct{
    Lista *cabeca;
    int tamInfo, qtd;
}Multilista;





