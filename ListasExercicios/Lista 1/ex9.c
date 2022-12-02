#include <stdio.h>
#include <stdlib.h>

int main(){

    int tam = 0, *v = NULL, *vp = NULL, *vn = NULL, tamP = 0, tamN = 0;
    printf("tamanho:\n");
    scanf("%d", &tam);
    v = malloc(sizeof(int) * tam);
    printf("insira os %d valores\n", tam);
    for(int i = 0; i < tam; i++){
        scanf("%d", v+i);
    }

    for(int i = 0; i < tam; i++){
        if(*(v+i) < 0){
            tamN++;
            vn = realloc(vn, sizeof(int) * tamN);
            vn[tamN-1] = *(v+i);
        } else if(*(v+i) > 0){
            tamP++;
            vp = realloc(vp, sizeof(int) * tamP);
            vp[tamP-1] = *(v+i);
        }
    }

    printf("\n\n");
    printf("vetor v:\n");
    for(int i = 0; i < tam; i++){
        printf("%d\n", *(v+i));
    }
    printf("\nvetor vn:\n");
    for(int i = 0; i < tamN; i++){
        printf("%d\n", *(vn+i));
    }
    printf("\nvetor vp:\n");
    for(int i = 0; i < tamP; i++){
        printf("%d\n", *(vp+i));
    }
    printf("\nfim!\n");
    free(v);
    free(vn);
    free(vp);
    return 0;
}