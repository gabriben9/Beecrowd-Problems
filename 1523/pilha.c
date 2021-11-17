#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

Item* criaItem(int chegada, int saida){

	Item* c = (Item*) malloc(sizeof(Item));
	c->anterior = NULL;
	c->proximo = NULL;

	c->chegada = chegada;
	c->saida = saida;

	return c;
}

Pilha* criaPilhaVazia(){

	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	Item* cabeca = criaItem(-1, -1);
	p->primeiro = cabeca;
	p->ultimo = cabeca;

	p->primeiro->proximo = NULL;
	p->tamanho = 0;

	return p;

}

int pilhaVazia(Pilha* p){

	if(p->ultimo == p->primeiro){
		return 1;
	}
	return 0;

}

void empilha(Item* c, Pilha* p){

	p->ultimo->proximo = c;
	c->anterior = p->ultimo;
	c->proximo = NULL;
	p->ultimo = c;
	p->tamanho++;

}

void desempilha(Pilha* p){

	if(pilhaVazia(p)){
		printf("Pilha Vazia.\n");
		return;
	}

	Item* aux = p->ultimo;
	p->ultimo = aux->anterior;
	p->tamanho--;

	free(aux);

}


void deletaPilha(Pilha* p){

	while(p->ultimo!=p->primeiro){
		desempilha(p);
	}

	free(p);
}
