#include <stdio.h>

void max_min(int vet[], int tam, int *pMin, int *pMax);

int main(){

    int tam = 10, pMin=0, pMax=0;
    int vet[10] = {0, 1, 29, -93, 4, 5, 6, 7, 8, 9};
    
    max_min(vet, tam, &pMin, &pMax);

    printf("Maior valor: %d    Menor valor: %d", pMax, pMin);

    return 0;
}

void max_min(int vet[], int tam, int *pMin, int *pMax){

    *pMin = vet[0];
    *pMax = vet[0];

    for(int i = 0; i < tam; i++){
        if(vet[i] < *pMin){
            *pMin = vet[i];
        }
        if(vet[i] > *pMax){
            *pMax = vet[i];
        }
    }
    

}