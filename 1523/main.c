#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	int motoristas, tam_estacionamento;
	int c, s, nao=0;
	Pilha *carros;


	do{

		carros = criaPilhaVazia();

		scanf("%d %d", &motoristas, &tam_estacionamento);
		if(!motoristas && !tam_estacionamento){
			break;
		}

		while(motoristas){

			motoristas--;

			scanf("%d %d", &c, &s);

			while(!pilhaVazia(carros) && carros->ultimo->saida <= c){
				desempilha(carros);
			}

			if(!nao && !pilhaVazia(carros)){
				if(carros->primeiro->proximo->saida <= s){
					nao = !nao;
					continue;
				}
				if(carros->ultimo->chegada >= c){
					nao = !nao;
				}
				if(carros->tamanho > tam_estacionamento){
					nao = !nao;
				}
			}

			empilha(criaItem(c, s), carros);

		}

		
		if(nao){
			printf("Nao\n");
			nao = !nao;
		}
		else{
			printf("Sim\n");
		}

		deletaPilha(carros);

	}while(motoristas || tam_estacionamento);

	return 0;

}
