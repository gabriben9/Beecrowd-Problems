#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"


int main(){


  Arvore* A;
  int testes, tamanho, j = 0;
  int chave;


  scanf("%d", &testes);


  while(j < testes){


    A = cria_arvore_vazia();

    scanf("%d ", &tamanho);

    for(int i = 0; i < tamanho; i++){
      
      scanf("%d", &chave);
      A->raiz = insere(A->raiz, chave);

    } 


    printf("Case %d:\n", j+1);

    printf("Pre.: ");
    pre_ordem(A, A->raiz);
    printf("\n");

    printf("In..: ");
    ordem_central(A, A->raiz);
    printf("\n");

    printf("Post: ");
    pos_ordem(A, A->raiz);
    printf("\n");


    printf("\n");


    destroi(A->raiz);

    j++;
  }


}
