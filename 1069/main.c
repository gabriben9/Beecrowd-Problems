int main(){

	Pilha* p;
	int testes, diamantes=0;
	char caso_teste[1000], b[5];

	scanf("%d", &testes);
	while(testes>0){

		p  = criaPilhaVazia();

		scanf("%s", caso_teste);

		for(int i = 0; i < strlen(caso_teste); i++){
			
			if(caso_teste[i] == '\0'){
				break;
			}

			if(caso_teste[i] == '<'){
				
				empilha(criaCelula(caso_teste[i], i), p);
				continue;
			
			}

			if(caso_teste[i] == '>'){
				
				if(p->ultimo->chave == '<'){
					diamantes++;
					desempilha(p);
					continue;
				}

				empilha(criaCelula(caso_teste[i], i), p);
			
			}
	
		}

		printf("%d\n", diamantes);
		testes--;
		diamantes=0;
		deletaPilha(p);

	}


	return 0;

}
