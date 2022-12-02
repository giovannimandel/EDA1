#include <stdio.h>
#include <stdlib.h>

int main(){

    float v[10] = {1.2, 5, 6, 9, 8, 2, 5, 6, 5, 4};
    float soma = 0;
    int n=0;
    for(int i = 0; i < 10; i++){
        soma += *v+i;
    }
    float media = soma / 10;
    printf("media %.2f\n", media);

    float *maiores = malloc(sizeof(float));
    for(int i = 0; i < 10; i++){
        if(*v+i > media){
            n++;
            realloc(maiores, sizeof(float)*n);
            maiores[n-1] = *v+i;
        }
    }

    printf("maiores: ");
    for(int i = 0; i < n; i++){
        printf("%.2f ", *maiores+i);
    }

    return 0;
}