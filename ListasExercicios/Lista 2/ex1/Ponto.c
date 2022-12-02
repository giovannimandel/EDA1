#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

void inicializa_ponto(Ponto *p, float x, float y){
    p->x = x;
    p->y = y;
}

void mostra_ponto(Ponto p){
    printf("(%.1f, %.1f)\n", p.x, p.y);
}

float calcula_distancia(Ponto a, Ponto b){
    float dist = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

float get_x(Ponto p){
    return p.x;
}

float get_y(Ponto p){
    return p.y;
}