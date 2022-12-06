#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

//Privado------------------------

Elemento *aloca_elemento( void *info, int tam ) {
	Elemento *p = malloc( sizeof(Elemento) );
	if( p == NULL )
		return NULL; // Erro, falta de mem�ria!
	p->info = malloc( tam );
	if( p->info == NULL ){
		free(p);
		return NULL; // Erro, falta de mem�ria!
	}
	memcpy(p->info, info, tam);
	return p; // Sucesso!
}

//-------------------------------


void inicializa_lista( Lista *p, int t ){
	p->tamInfo = t;
	p->cabeca = NULL;
	p->qtd = 0;
}

int lista_vazia ( Lista l ){
	return l.cabeca == NULL;
}

int insere_inicio( Lista *p, void *info ){
	Elemento *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
		return 0; // Erro, falta de mem�ria!

	novo->proximo = p->cabeca;
	p->cabeca = novo;
	p->qtd++;
	return 1; // Sucesso!
}

int remove_inicio( Lista *p, void *info ){
	if( lista_vazia( *p ) )
		return ERRO_LISTA_VAZIA;

	Elemento *aux = p->cabeca;
	memcpy( info, aux->info, p->tamInfo );
	p->cabeca = aux->proximo;
	free( aux->info );
	free( aux );
	p->qtd--;
	return 1; // Sucesso!
}

int insere_fim( Lista *p, void *info ){
	if( lista_vazia( *p ) )
		return insere_inicio( p, info );

	Elemento *aux = p->cabeca;
	while( aux->proximo != NULL )
		aux = aux->proximo;

	Elemento *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
    	return 0; // Erro, falta de mem�ria!

	aux->proximo = novo;
	novo->proximo = NULL;
	p->qtd++;
	return 1; // Sucesso!
}

int remove_fim( Lista *p, void *info ){
   if( lista_vazia( *p ) )
      return ERRO_LISTA_VAZIA;
   if( p->qtd == 1 )
      return remove_inicio( p, info );
   Elemento *aux = p->cabeca;
   while( aux->proximo->proximo != NULL )
      aux = aux->proximo;
   Elemento *ultimo = aux->proximo;
   memcpy( info, ultimo->info, p->tamInfo );
   free( ultimo->info );
   free( ultimo );
   aux->proximo = NULL;
   p->qtd--;
   return 1; // Sucesso!
}

int insere_pos( Lista *p, void *info , int pos ){
	if( pos < 0 || pos > p->qtd )
		return ERRO_POS_INVALIDA;
		
	if( pos == 0 )
		return insere_inicio( p, info );
	
	Elemento *aux = p->cabeca;
	int cont;
	for( cont = 0 ; cont < pos-1 ; cont++ )
		aux = aux->proximo; // Vai at� elemento em pos-1
	
	Elemento *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
		return 0; // Erro, falta de mem�ria!
	
	novo->proximo = aux->proximo;
	aux->proximo = novo;
	p->qtd++;
	return 1; // Sucesso!
}

int remove_pos( Lista *p, void *info , int pos ){
	if( lista_vazia( *p ) )
		return ERRO_LISTA_VAZIA;

	if( pos < 0 || pos >= p->qtd )
		return ERRO_POS_INVALIDA;
	
	if( pos == 0 )
		return remove_inicio( p, info );

	Elemento *aux = p->cabeca;
	int cont;
	for( cont = 0 ; cont < pos-1 ; cont++ )
		aux = aux->proximo; // Vai at� pos-1
	
	Elemento *x = aux->proximo;
	aux->proximo = x->proximo;
	memcpy( info, x->info, p->tamInfo );
	free( x->info );
	free( x );
	p->qtd--;
	return 1; // Sucesso!
}

int le_valor( Lista l, void *info , int pos ){
	if( lista_vazia( l ) )
		return ERRO_LISTA_VAZIA;

	if( pos < 0 || pos >= l.qtd )
		return ERRO_POS_INVALIDA;
		
	Elemento *aux = l.cabeca;
	int cont;
	for( cont = 0 ; cont < pos ; cont++ )
		aux = aux->proximo; // Vai at� elemento em pos
	
	memcpy( info, aux->info, l.tamInfo );
	return 1; // Sucesso!
}

int modifica_valor( Lista l, void *info , int pos ){
	if( lista_vazia( l ) )
		return ERRO_LISTA_VAZIA;

	if( pos < 0 || pos >= l.qtd )
		return ERRO_POS_INVALIDA;
		
	Elemento *aux = l.cabeca;
	int cont;
	for( cont = 0 ; cont < pos ; cont++ )
		aux = aux->proximo; // Vai at� elemento em pos
	
	memcpy( aux->info, info, l.tamInfo );
	return 1; // Sucesso!
}

void mostra_lista( Lista l, void (*mostra)(void *) ){
	if( lista_vazia( l ) )
		printf("Lista vazia!\n");
	else{
		printf("Dados da lista (%d elementos):\n", l.qtd );
		Elemento *p = l.cabeca;
		int cont = 0; // cont � o indice do elemento dentro da lista.
		while( p != NULL ){
			printf("[%d] ", cont);
			mostra( p->info ); // Invocacao por callback
			p = p->proximo;
			cont++;
		}
	}
	printf("--------------------------------\n");

	// void mostra_float( void *x ){ // mostra um float...
	// 	printf("%.2f\n", *(float *)x ); // a partir de um void*
	// }

}

int conta_elementos( Lista l ){
	int cont = 0;
	Elemento *p = l.cabeca;
	while( p != NULL ){
		cont++;
		p = p->proximo;
	}
	return cont;
}

void limpa_lista( Lista *l ){
	Elemento *p = l->cabeca;
	while( p != NULL ){
		Elemento *prox = p->proximo;
		free( p->info );
		free( p );
		p = prox;
	}
	l->cabeca = NULL;
	l->qtd = 0;
}

int insere_ordem( Lista *p, void *info, int (*compara)(void*, void*) ){
	Elemento *aux = p->cabeca;
	int cont = 0;
	while( aux != NULL && compara( info, aux->info ) > 0 ){
		aux = aux->proximo;
		cont++;
	}
	return insere_pos( p, info, cont );
}

void concatena(Lista *l1, Lista *l2){
	Elemento *aux = l1->cabeca;

	if(aux != NULL){
		while( aux->proximo != NULL)
			aux = aux->proximo;
		aux->proximo = l2->cabeca;
	} else{	
		l1->cabeca = l2->cabeca;
	}
	l1->qtd = l1->qtd + l2->qtd;
	l2->cabeca = NULL;
	l2->qtd = 0;
	 
}

int busca( Lista *l, void *info, int (*compara)(void *, void *) ){
	Elemento *aux = l->cabeca;

	for(int i = 0; i < l->qtd; i++){
		if(compara(aux->info, info) == 0){
			printf("Encontrado em %d\n", i);
			return 1;
		} else{
			aux = aux->proximo;
		}
	}
	return -1;

	// 	int compara(void *x, void *y){
	// 	int *a = x, *b = y;
	// 	return *a - *b;
	// }
}

Lista busca_todos( Lista l, void *info, int (*compara)(void*,void*) ){
	Elemento *aux = l.cabeca;
	Lista l2;

	inicializa_lista(&l2, sizeof(int));

	for(int i = 0; i < l.qtd; i++, aux = aux->proximo){
		if(compara(aux->info, info) == 0){
			printf("Encontrado em %d\n", i);
			insere_fim(&l2, &i);
		}
	}

	return l2;

	// 	int compara(void *x, void *y){
	// 	int *a = x, *b = y;
	// 	return *a - *b;
	// }
}