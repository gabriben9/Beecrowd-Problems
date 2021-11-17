#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


int main(){

	Lista* l = criaListaVazia();
	Lista* removidos = criaListaVazia();
	int n;

	do{

		scanf("%d", &n);
		if(n == 0)
			break;

		for(int i = n; i >= 1; i--){
			inserir(l, criaItem(i));
		}

		imprimeLista(l);

		while(l->tamanho >= 2){
			inserir(removidos, criaItem(l->ultimo->chave));
			removeElemento(l, l->ultimo->chave);
			if(l->tamanho == 1)
				break;
			moverInicio(l, l->ultimo->chave);

		}

		printf("Discarded cards: ");
		imprimeLista(removidos);
		printf("Remaining card: ");
		imprimeLista(l);

		l = criaListaVazia();
		removidos = criaListaVazia();

	}while(n!=0);

}
