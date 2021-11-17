
typedef struct item{

	struct item *anterior;
	struct item *proximo;
	int chegada, saida;

} Item;

typedef struct pilha{

	Item *primeiro;
	Item *ultimo;
	int tamanho;

} Pilha;

Item* criaItem(int, int);
Pilha* criaPilhaVazia();
int pilhaVazia(Pilha*);
void empilha(Item*, Pilha*);
void desempilha(Pilha*);
void deletaPilha(Pilha*);

