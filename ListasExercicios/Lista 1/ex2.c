#include <stdio.h>

void calcula_circulo(float raio, float *pPerimetro, float *pArea);


int main(){

    float raio, pPerimetro=0, pArea = 0;
    scanf("%f", &raio);

    calcula_circulo(raio, &pPerimetro, &pArea);
    printf("perimetro = %.3f   area = %.3f",pPerimetro, pArea);

    return 0;
}

void calcula_circulo(float raio, float *pPerimetro, float *pArea){

    *pPerimetro = 2 * 3.14 * raio;
    *pArea = 3.14 * raio * raio; 
    
}