#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct fila{
	int primeiro;
	int ultimo;
	int tamlista;
	int elemento[MAX];
};
typedef struct fila tipofila;

void inicia(tipofila *filaAux){
	int i = 0;
	filaAux->primeiro = -1;
	filaAux->ultimo = -1;
	filaAux->tamlista = 0;
	for (i=0;i<MAX; i++)
		filaAux->elemento[i] = 0;
};

int filacheia(tipofila *filaAux){
	if (filaAux->tamlista == MAX)
		return 1;
	return 0;
};

int filavazia(tipofila *filaAux){
	if (filaAux->tamlista == 0)
		return 1;
	return 0;
};

void insereinicio(tipofila *filaAux, int num){
	int index, i=0;
	if(filacheia(filaAux) == 1)
		exit(1);
	if(filavazia(filaAux)== 1){
		filaAux->primeiro = 0;
		filaAux->ultimo = 0;
		filaAux->elemento[0]=num;
	}
	else{

        for(i = filaAux->tamlista-1; i>=0; i--){
            filaAux->elemento[i+1] = filaAux->elemento[i];
        }
        filaAux->elemento[0]= num;
	}
	filaAux->ultimo = filaAux->tamlista;
    filaAux->tamlista++;

};

void imprimefila(tipofila *filaAux){
	int i;
	for (i=0; i < filaAux->tamlista; i++){
		printf("%d ", filaAux->elemento[i]);
	}
};

int removefinal (tipofila *filaAux){

    int i=0, num, pos, ant;
	pos = filaAux->ultimo;
	num = filaAux->elemento[pos];

    for (i=0; i<=filaAux->tamlista; i++){
        if (i == pos){
             filaAux->elemento[i] = filaAux->elemento[i + 1];
             if (filaAux->elemento[i] != filaAux->elemento[filaAux->ultimo])
             {
                filaAux->elemento[i + 1] = num;
             }
        }

    }
    filaAux->tamlista --;
    return num;
};

int main(){

	tipofila minhafila;
	inicia(&minhafila);

	int L, op, i=0, V, aux;

	scanf("%d", &L);
	if (L < 1 || L>100)
        exit(1);

    for (i = 0; i<L; i++){
        scanf("%d", &op);
        switch(op)
        {
                //INSERE
                case 1:
                    scanf("%d", &V);
                    if (V < 1 || V>100)
                        exit(1);
                    insereinicio(&minhafila, V);
                    break;
                // REMOVE DO INICIO
                case 2:
                    if (filavazia(&minhafila)==1)
                        printf ("vazia\n");
                    else
                        removefinal(&minhafila);
                    break;
                //CONCLUI TAREFA
                case 3:
                    if (filavazia(&minhafila)==1)
                        printf ("vazia\n");
                    else
                        insereinicio(&minhafila, removefinal(&minhafila));
                    break;
                //ERRO
                default:
                    exit(1);
        }
    }

	imprimefila(&minhafila);

	return 0;
}
