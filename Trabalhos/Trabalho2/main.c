#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"
#include "Pilha.h"
#include "Fila.h"

int main(){
    Matriz m;
    Fila f;
    int n, ini, *vs, x, fim, *va, achou;
    Pilha p;
    

    printf("Digite o numero de vertices do grafo:\n");
    scanf("%d", &n);

    inicializa_matriz(&m, n+1, n+1);
    vs = calloc(n+1, sizeof(int));
    va = calloc(n+1, sizeof(int));

    carrega_arquivo("matriz.txt", &m);// A matriz deve ter tamanho n+1 (9 vertices, tamanho é 10)  
                                      // A primeira linha e primeira coluna devem ser preenchidas com 0 (m[0][x] = 0, m[x][0] = 0)
                        
    
    printf("Digite o vertice inicial:\n");
    
    scanf("%d", &ini);
    printf("Digite o vertice final:\n");
    scanf("%d", &fim);
    printf("\n");

    inicializa_fila(&f, 10);
    
    vs[ini] = 1;
    inserir(&f, ini);
    achou = 0;

    while(!fila_vazia(f) && !achou){

        remover(&f, &x);
        if(x == fim){
            achou = 1;
        } else{
            for(int i = 1; i <= n; i++){
                int k;
                get_valor(m, x, i, &k);

                if(vs[i] == 0 && k == 1){
                    vs[i] = 1;
                    va[i] = x;
                    inserir(&f, i);
                }
            }
        }
    }

    if(achou){
        inicializa_pilha(&p);
        while(x != 0){
            empilha(&p, x);
            x = va[x];
        }
        while(!pilha_vazia(p)){
            desempilha(&p, &x);
            printf("%d\n", x);
        }
    } else{
        printf("Vertice final nao alcancavel a partir do vertice inicial\n");
    }

    return 0;
}
