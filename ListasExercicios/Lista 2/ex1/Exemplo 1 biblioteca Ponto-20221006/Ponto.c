#include "Ponto.h"
#include <stdio.h>
#include <math.h>

void inicializa_ponto( Ponto *p, float x, float y ){
	p->x = x;
	p->y = y;	
}

void mostra_ponto( Ponto p ){
	printf("( %.1f, %.1f )\n", p.x, p.y);
}

float calcula_distancia( Ponto p1, Ponto p2 ){
	return sqrt( pow( p1.x - p2.x , 2 ) + pow( p1.y - p2.y , 2 ) );
}

float get_x( Ponto p ){
	return p.x;
}

float get_y( Ponto p ){
	return p.y;
}

