
/* Stefanie Soares
AED1 - LAB03 */

#include<stdio.h>
#include<stdlib.h>

struct info{
    int id;
    int qp;
    float lucro;
    int numvenda;
    struct info *prox;
};
typedef struct info tipoinfo;

struct listaDE{
    int tamlista;
    tipoinfo *primeiro;
    tipoinfo *ultimo;
    tipoinfo *penultimo;
};
typedef struct listaDE tipolistaDE;

void inicia(tipolistaDE *listaAux){
    listaAux->tamlista = 0;
    listaAux->primeiro = NULL;
    listaAux->ultimo = NULL;
    listaAux->penultimo=NULL;
};

void insere(tipolistaDE *listaAux, int ident, int q, int l){

    int i =0;
    tipoinfo *novo = (tipoinfo*)malloc(sizeof(tipoinfo));
    tipoinfo *aux = listaAux->primeiro;
    tipoinfo *auxant;

    //------------insere o primeiro------------
    if (listaAux->tamlista == 0){
        novo->id = ident;
        novo->qp = q;
        novo->lucro = l;
        novo->numvenda = 0;
        novo->prox = NULL;
        listaAux->primeiro = novo;
        listaAux->ultimo = novo;
        listaAux->penultimo = NULL;
    }
    //------------insere no final------------
    else{
        novo->id = ident;
        novo->qp = q;
        novo->lucro = l;
        novo->numvenda = 0;
        for(i=0; i<listaAux->tamlista; i++){
            if(novo->lucro < aux->lucro){
                if (aux != NULL){
                    auxant = aux;
                    aux = aux->prox;
                }
            }
        }
        if (aux == listaAux->primeiro){
            novo->prox = aux;
            listaAux->primeiro = novo;
        }
        else{
            if(aux == NULL)
                listaAux->ultimo = novo;
            auxant->prox = novo;
            novo->prox = aux;
        }
    }
    listaAux->tamlista ++;
};

void imprime(tipolistaDE *listaAux){
    tipoinfo *aux = listaAux->primeiro;
    while (aux != NULL){
        printf("%d ",aux->id);
        printf("%d ",aux->qp);
        printf("%f ",aux->lucro);
        aux = aux->prox;
    }
    printf("\n");
};

int busca(tipolistaDE *listaAux, int id){
    tipoinfo *aux = listaAux->primeiro;
    int i;
    for (;aux != NULL; aux = aux -> prox){
        if (aux->id == id){
            return 1;
            break;
        }
    }
    return -1;
};

void retira(tipolistaDE *listaAux, int ident){
    tipoinfo *node = (tipoinfo*)malloc(sizeof(tipoinfo));
    int i =0;

    //--------Retirada do primeiro elemento----------
    if ( listaAux->primeiro->id == ident){
        node = listaAux ->primeiro;
        listaAux->primeiro = node->prox;
        listaAux->penultimo = NULL;
    }
    //--------Retirada do último elemento----------
    else if (listaAux->ultimo->id == ident){
        node = listaAux->ultimo;
        listaAux->ultimo = listaAux->penultimo;
        free(node);
        listaAux->ultimo->prox = NULL;
    }
    //--------Retirada intermediária----------
    else{
        tipoinfo *aux = listaAux->primeiro;
        tipoinfo *ant = NULL;
        while (aux->id != ident){
            ant = aux;
            aux = aux->prox;
        }
        aux = ant->prox;
        ant->prox = aux->prox;
        free(aux);
    }
    listaAux->tamlista --;
};

void aumentaestoque (tipolistaDE *listaAux, int id, int qi){
    int i;
    tipoinfo *aux = listaAux->primeiro;
    for (aux; aux!=NULL; aux=aux->prox){
        if (aux->id == id){
            aux->qp = aux->qp + qi;
        }
    };
};

void compra (tipolistaDE *listaAux, int id){
    tipoinfo *aux = listaAux->primeiro;
    int i;
    for (aux; aux!=NULL; aux=aux->prox){
        if (aux->id == id){
            if (aux->qp != 0){
                aux->qp = aux->qp -1;
                aux->numvenda = aux->numvenda +1;
                break;
            }
            else
                printf("nao existe\n");
                break;
        }
    }
};
int lucrofinal (tipolistaDE *listaAux){
    tipoinfo *aux = listaAux->primeiro;
    float lucrofinal = 0;
    int i;
    for (aux; aux!=NULL; aux=aux-> prox){
        lucrofinal = 0;
        lucrofinal = aux->lucro * aux->numvenda;
        printf("%d %f\n", aux->id, lucrofinal);
    }
};

int main(){
    tipolistaDE minhalista;
    inicia(&minhalista);

    int L, P, id, qp, qi, i=0;
    float lucro;
    scanf("%d", &L);
    if (L < 1 || L>100) exit(1);
    for (i=0;i<L;i++){
        scanf("%d", &P);
        switch (P){
            //-------------Insere produto-------------//
            case 1:
                scanf("%d %d", &id ,&qp);
                scanf("%f", &lucro);
                if (busca(&minhalista, id) == 1)
                    printf("ja existe\n");
                else{
                    insere(&minhalista, id, qp, lucro);
                }
                break;
            //-------------Aumenta qntd-------------//
            case 2:
                scanf("%d %d", &id, &qi);
                if (busca(&minhalista, id) == 1){
                    aumentaestoque(&minhalista, id, qi);
                }
                else
                    printf("nao existe\n");
                break;
            //-------------Compra-------------//
            case 3:
                scanf("%d", &id);
                if (busca(&minhalista, id) == 1){
                    compra(&minhalista, id);
                }
                else
                    printf("nao existe\n");
                break;
            //-------------Exclusão-------------//
            case 4:
                scanf("%d", &id);
                if (busca(&minhalista, id) == 1){
                    retira(&minhalista, id);
                }
                else
                    printf("nao existe\n");
                break;
            default:
                exit(1);
        }
    }
    lucrofinal(&minhalista);
}
