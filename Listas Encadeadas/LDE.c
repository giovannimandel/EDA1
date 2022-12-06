#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LDE.h"

//Privado------------------------

EleDuplo *aloca_elemento( void *info, int tam ) {
	EleDuplo *p = malloc( sizeof(EleDuplo) );
	if( p == NULL )
		return NULL; // Erro, falta de memória!
	p->info = malloc( tam );
	if( p->info == NULL ){
		free(p);
		return NULL; // Erro, falta de memória!
	}
	memcpy(p->info, info, tam);
	return p; // Sucesso!
}

//-------------------------------


void inicializa_LDE( LDE *p, int t ){
	p->tamInfo = t;
	p->cabeca = NULL;
	p->qtd = 0;
}

int LDE_vazia ( LDE l ){
	return l.cabeca == NULL;
}

int insere_inicio( LDE *p, void *info ){
	EleDuplo *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
		return 0; // Erro, falta de memória!

	novo->suc = p->cabeca;
	p->cabeca = novo;
	p->qtd++;
	novo->ant = NULL;
	if(novo->suc != NULL)
		novo->suc->ant = novo;
	return 1; // Sucesso!
}

int remove_inicio( LDE *p, void *info ){
	if( LDE_vazia( *p ) )
		return ERRO_LDE_VAZIA;

	EleDuplo *aux = p->cabeca;
	memcpy( info, aux->info, p->tamInfo );
	p->cabeca = aux->suc;
	free( aux->info );
	free( aux );
	p->qtd--;
	if(p->cabeca != NULL)
		p->cabeca->ant = NULL;
	return 1; // Sucesso!
}

int insere_fim( LDE *p, void *info ){
	if( LDE_vazia( *p ) )
		return insere_inicio( p, info );

	EleDuplo *aux = p->cabeca;
	while( aux->suc != NULL )
		aux = aux->suc;

	EleDuplo *novo = aloca_EleDuplo( info, p->tamInfo );
	if( novo == NULL )
    	return 0; // Erro, falta de memória!

	aux->suc = novo;
	novo->suc = NULL;
	p->qtd++;
	return 1; // Sucesso!
}

int remove_fim( LDE *p, void *info ){
   if( LDE_vazia( *p ) )
      return ERRO_LDE_VAZIA;
   if( p->qtd == 1 )
      return remove_inicio( p, info );
   EleDuplo *aux = p->cabeca;
   while( aux->suc->suc != NULL )
      aux = aux->suc;
   EleDuplo *ultimo = aux->suc;
   memcpy( info, ultimo->info, p->tamInfo );
   free( ultimo->info );
   free( ultimo );
   aux->suc = NULL;
   p->qtd--;
   return 1; // Sucesso!
}

int insere_pos( LDE *p, void *info , int pos ){
	if( pos < 0 || pos > p->qtd )
		return ERRO_POS_INVALIDA;
		
	if( pos == 0 )
		return insere_inicio( p, info );
	
	EleDuplo *aux = p->cabeca;
	int cont;
	for( cont = 0 ; cont < pos-1 ; cont++ )
		aux = aux->suc; // Vai até EleDuplo em pos-1
	
	EleDuplo *novo = aloca_EleDuplo( info, p->tamInfo );
	if( novo == NULL )
		return 0; // Erro, falta de memória!
	
	novo->suc = aux->suc;
	aux->suc = novo;
	p->qtd++;
	return 1; // Sucesso!
}

int remove_pos( LDE *p, void *info , int pos ){
	if( LDE_vazia( *p ) )
		return ERRO_LDE_VAZIA;

	if( pos < 0 || pos >= p->qtd )
		return ERRO_POS_INVALIDA;
	
	if( pos == 0 )
		return remove_inicio( p, info );

	EleDuplo *aux = p->cabeca;
	int cont;
	for( cont = 0 ; cont < pos-1 ; cont++ )
		aux = aux->suc; // Vai até pos-1
	
	EleDuplo *x = aux->suc;
	aux->suc = x->suc;
	memcpy( info, x->info, p->tamInfo );
	free( x->info );
	free( x );
	p->qtd--;
	return 1; // Sucesso!
}

int le_valor( LDE l, void *info , int pos ){
	if( LDE_vazia( l ) )
		return ERRO_LDE_VAZIA;

	if( pos < 0 || pos >= l.qtd )
		return ERRO_POS_INVALIDA;
		
	EleDuplo *aux = l.cabeca;
	int cont;
	for( cont = 0 ; cont < pos ; cont++ )
		aux = aux->suc; // Vai até EleDuplo em pos
	
	memcpy( info, aux->info, l.tamInfo );
	return 1; // Sucesso!
}

int modifica_valor( LDE l, void *info , int pos ){
	if( LDE_vazia( l ) )
		return ERRO_LDE_VAZIA;

	if( pos < 0 || pos >= l.qtd )
		return ERRO_POS_INVALIDA;
		
	EleDuplo *aux = l.cabeca;
	int cont;
	for( cont = 0 ; cont < pos ; cont++ )
		aux = aux->suc; // Vai até EleDuplo em pos
	
	memcpy( aux->info, info, l.tamInfo );
	return 1; // Sucesso!
}

void mostra_LDE( LDE l, void (*mostra)(void *) ){
	if( LDE_vazia( l ) )
		printf("LDE vazia!\n");
	else{
		printf("Dados da Lista (%d Elementos):\n", l.qtd );
		EleDuplo *p = l.cabeca;
		int cont = 0; // cont é o índice do EleDuplo dentro da LDE.
		while( p != NULL ){
			printf("[%d] ", cont);
			mostra( p->info ); // Invocação por callback
			p = p->suc;
			cont++;
		}
	}
	printf("--------------------------------\n");
}

int conta_EleDuplos( LDE l ){
	int cont = 0;
	EleDuplo *p = l.cabeca;
	while( p != NULL ){
		cont++;
		p = p->suc;
	}
	return cont;
}

void limpa_LDE( LDE *l ){
	EleDuplo *p = l->cabeca;
	while( p != NULL ){
		EleDuplo *prox = p->suc;
		free( p->info );
		free( p );
		p = prox;
	}
	l->cabeca = NULL;
	l->qtd = 0;
}

int insere_ordem( LDE *p, void *info, int (*compara)(void*, void*) ){
	EleDuplo *aux = p->cabeca;
	int cont = 0;
	while( aux != NULL && compara( info, aux->info ) > 0 ){
		aux = aux->suc;
		cont++;
	}
	return insere_pos( p, info, cont );
}


