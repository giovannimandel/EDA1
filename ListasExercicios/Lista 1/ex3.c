#include <stdio.h>

void calcula_hora(int totalMinutos, int *ph, int *pm);

int main(){

    int totalMinutos, ph=0, pm=0;

    scanf("%d", &totalMinutos);
    calcula_hora(totalMinutos, &ph, &pm);
    printf("total de minutos: %d, em horas: %d:%d", totalMinutos,ph, pm);


    return 0;
}

void calcula_hora(int totalMinutos, int *ph, int *pm){

    int resto; 

    *ph = totalMinutos / 60;
    resto = totalMinutos % 60;
    *pm = resto;

}