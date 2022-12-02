#include <stdio.h>
#include "Matriz.h"
#include "Pilha.h"
#include <stdlib.h>

int main(){

    Matriz * matriz_adj = malloc(sizeof(Matriz));

    int vertice, vertice_ini, x, *status; 

    printf("Informe o numero de vertices para o grafo: ");
    scanf("%d", &vertice);

    status = calloc(vertice +1, sizeof(int));

    inicializa_matriz(matriz_adj, vertice + 1, vertice + 1);

    printf("Inicialize a matriz adjacente do grafo:\n");
    for(int i=1; i <= vertice; i++){
        for(int j = 1; j <= vertice; j++){
            scanf("%d", &x);
            set_valor(matriz_adj, i, j, x);
        }
    }

    printf("Vertice inicial: ");
    scanf("%d", &vertice_ini);

    Pilha * pilha = malloc(sizeof(Pilha));

    inicializa_pilha(pilha);

    empilha(pilha, vertice_ini);

    while(!pilha_vazia(*pilha)){
        desempilha(pilha, &x);

        if(status[x] == 0){
            printf("Estou visitando: %d\n", x);
            status[x] = 1;

            for(int i = 1; i <= vertice; i++){
                int p;

                get_valor(*matriz_adj, x, i, &p);

                if(status[i] == 0 && p == 1){
                   empilha(pilha, i); 
                }
            }
        }
    }

    return 0;
}