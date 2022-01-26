#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main(){


  Arvore* A = cria_arvore_vazia();
  char entrada[10];
  int elemento;

  while(1){

    fgets(entrada, 10, stdin);
    for(int i = 0; i < strlen(entrada); i++){
      if(entrada[i] == '\n'){
        entrada[i] = '\0';
        break;
      }
    }

    if(strstr(entrada, "INFIXA") == &entrada[0]){

      ordem_central(A, A->raiz);
      printf("\n");

    } else if(strstr(entrada, "I") == &entrada[0]){

      sscanf(entrada, "I %d", &elemento);
      A->raiz = insere(A->raiz, elemento);

    } else if(strstr(entrada, "PREFIXA") == &entrada[0]){

      pre_ordem(A, A->raiz);
      printf("\n");

    } else if(strstr(entrada, "POSFIXA") == &entrada[0]){

      pos_ordem(A, A->raiz);
      printf("\n");

    } else if(strstr(entrada, "P") == &entrada[0]){

      sscanf(entrada, "P %d", &elemento);
      existe(A->raiz, elemento);

    } else{

      sscanf(entrada, "R %d", &elemento);
      A->raiz = remover(A->raiz, elemento);
      
    }

    if(feof(stdin)){
      break;
    }

    memset(entrada, 0, sizeof(entrada));

  }
    
    return 0;

}
