#include <stdlib.h>
#include <stdio.h>

typedef struct TItem{
	int Chave;
	struct TItem *Prox;
} Item;

typedef struct {
	Item **Indice;
	int TamTabela, nItems;
} TabelaDeHash;

TabelaDeHash *Inicia(int TamTabela){
	int i;
	TabelaDeHash *Tabela = (TabelaDeHash*) malloc(sizeof(TabelaDeHash));

	Tabela->TamTabela = TamTabela;
	Tabela->nItems = 0;
	Tabela->Indice = (Item **) malloc(TamTabela*sizeof(Item *));

	for (i=0;i<TamTabela;i++){
		Tabela->Indice[i] = NULL;
	}

	return Tabela;
}

int Pos(TabelaDeHash *Tabela, int Chave){
	int i;

	i = Chave % Tabela->TamTabela;

	return i;
}

void Insere(TabelaDeHash *Tabela, int Chave){
	int i;
	Item **Node, *Aux;
	Aux = (Item *) calloc(1,sizeof(Item));
	Aux->Chave = Chave;

	i = Pos(Tabela, Chave);

	Node = &(Tabela->Indice[i]);

	if (*Node == NULL){
		*Node = Aux;
		Tabela->nItems++;
		return;
	}

	while ((*Node)->Prox!=NULL){
		Node = &((*Node)->Prox);
	}

	(*Node)->Prox=Aux;
	Tabela->nItems++;

	return;
}

void Imprime(TabelaDeHash *Tabela, int Linha){
	Item *Node;
	int i=0;

    printf("[%d] ",Linha);
    Node = Tabela->Indice[Linha];
    while (Node!=NULL){
        printf("%d ",Node->Chave);
        Node = Node->Prox;
    }

	return;
}

void Remove(TabelaDeHash *Tabela, int Chave){
	int i;
	Item **Node, **Aux;

	i = Pos(Tabela, Chave);
	Node = &(Tabela->Indice[i]);


    if ((*Node)->Chave == Chave){ // remove o primeiro elemento
        if ((*Node)->Prox != NULL){
            Tabela->Indice[i] = Tabela->Indice[i]->Prox;
            Tabela->nItems--;

        }
        return;
    }
    while ((*Node)->Prox->Chave!=Chave && (*Node)->Prox != NULL){ // remove os posteriores
		Node = &((*Node)->Prox);
	}
	Aux = &((*Node)->Prox);
	(*Node)->Prox=(*Aux)->Prox;
	Tabela->nItems--;
}



int Busca(TabelaDeHash *Tabela, int Chave){
	int ResulBusca = 0, i;
	Item *Node;

	i = Pos(Tabela, Chave);

	Node = Tabela->Indice[i];

    if (Node == NULL) return ResulBusca;

	if (Node->Chave == Chave){
		ResulBusca = 1;
		return ResulBusca;
	}

    while (Node->Chave!=Chave && Node->Prox!=NULL){
		Node = Node->Prox;
	}

	if (Node->Chave == Chave) ResulBusca = 1;

	return ResulBusca;
}



int main(){
	int TamTabela, Num, i, Linha;

	TabelaDeHash *Tabela;

	scanf("%d",&TamTabela);
	Tabela = Inicia(TamTabela);

	while (Num != -1){
        scanf("%d",&Num);
        if (Num != -1){
            Insere(Tabela,Num);
            printf("\n");
        }
	}



	scanf("%d",&Num);

	if (Busca(Tabela,Num)==0){
        printf("Valor nao encontrado\n");
	} else {
		Remove(Tabela,Num);
	}

	scanf("%d",&Linha);

	Imprime(Tabela, Linha);

	return 0;
}
