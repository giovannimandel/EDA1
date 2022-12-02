
typedef struct{
	float x, y;
} Ponto;

void inicializa_ponto( Ponto *p, float x, float y );
void mostra_ponto( Ponto p );
float calcula_distancia( Ponto p1, Ponto p2 );
float get_x( Ponto p );
float get_y( Ponto p );

