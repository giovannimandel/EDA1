#include <stdio.h>
#include <stdlib.h>

float *clone( float *v, int n );

int main(){

    int tam = 10;
    float vet[10] = {0, 1, 29, -93, 4, 5, 6, 7, 8, 9};
    
    *clone(vet, tam);

    

    return 0;
}

float *clone( float *v, int n ){

    float *cloneVet = malloc(sizeof(float) * n);
    

    for(int i = 0; i < n; i++){
        *(cloneVet+i) = *(v+i);
    }
    
for(int i = 0; i < n; i++){
    printf("%.2f ",*(cloneVet+i));
}
}