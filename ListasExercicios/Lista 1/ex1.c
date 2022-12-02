#include <stdio.h>
void troca_valor(float *x, float *y);


int main(){

    float a, b;

    printf("Digite dois valores:\n");
    scanf("%f", &a);
    scanf("%f", &b);
    printf("valores atuais: a = %.2f   b = %.2f\n", a, b);
    troca_valor(&a, &b);
    printf("valores trocados: a = %.2f,   b = %.2f\n", a, b);

    return 0;
}

void troca_valor(float *x, float *y){
    float temp;

    temp = *x;
    *x = *y;
    *y = temp;

}