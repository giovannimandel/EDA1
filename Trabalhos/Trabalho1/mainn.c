#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include "Pilha.h"

int main(){
    Matriz m;
    int n, ini, *vs, x, *v = NULL;;
    

    printf("Digite o numero de vertices do grafo:\n");
    scanf("%d", &n);

    inicializa_matriz(&m, n+1, n+1);
    vs = calloc(n+1, sizeof(int));

    carrega_arquivo("matriz.txt", &m);// A matriz deve ter tamanho n+1 (9 vertices, tamanho é 10)  
                                      // A primeira linha e primeira coluna devem ser preenchidas com 0 (m[0][x] = 0, m[x][0] = 0)
    Pilha p;
    printf("Digite o vertice inicial:\n");
    inicializa_pilha(&p);
    scanf("%d", &ini);
    printf("\n");
    
    empilha(&p, ini);

    while(!pilha_vazia(p)){
        desempilha(&p, &x);

        if(vs[x] == 0){
            printf("%d\n", x);
            vs[x] = 1;

            for(int i = 1; i <= n; i++){
                int k;

                get_valor(m, x, i, &k);

                if(vs[i] == 0 && k == 1){
                    empilha(&p, i);
                }
            }
        }
    }
    
    return 0;
}


