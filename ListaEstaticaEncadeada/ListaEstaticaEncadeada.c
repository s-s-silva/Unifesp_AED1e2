#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct info{
    int proximo;
    int conteudo;
};
typedef struct info tipoinfo;

struct listaEE {
    int ultimo;
    int penultimo;
    int primeiro;
    int tamlista;
    int poslivre[MAX];
    tipoinfo elemento[MAX];
};
typedef struct listaEE tipolistaEE;

int inicia(tipolistaEE *listaAux){
    int i=0;
    listaAux->tamlista=0;
    listaAux->primeiro=-1;
    listaAux->ultimo=-1;
    listaAux->penultimo=-1;
    for (i=0;i<MAX;i++){
        listaAux->elemento[i].conteudo=0;
        listaAux->elemento[i].proximo=-1;
        listaAux->poslivre[i]=1;
    }
};

int livre(tipolistaEE *listaAux){
    int i=0;
    for (i=0;i<MAX;i++){
        if(listaAux->poslivre[i]==1)
            return i;
    }
   return -1;
};

int insere(tipolistaEE *listaAux, int posicao, int RA){
    if (listaAux->tamlista > MAX-1){
       return 0;
    }
    else{
        if(posicao!=-1){
            listaAux->elemento[posicao].conteudo = RA;
            if(listaAux->tamlista==0)
                listaAux->primeiro=posicao;
            else
                listaAux->elemento[listaAux->ultimo].proximo=posicao;
            listaAux->tamlista++;
            listaAux->ultimo=posicao;
            listaAux->poslivre[posicao]=0;
            listaAux->elemento[posicao].proximo=-1;
            return 1;

        }
    }

};

int ordena(tipolistaEE *listaAux){
    int i=0, j=0, aux=0, k=0;
    for(i=0;i<listaAux->tamlista-1;i++){
        if (listaAux->elemento[i].conteudo !=0)
        {
            if (listaAux->elemento[i].proximo == listaAux->ultimo ){ // Declaração Penultimo
                listaAux->penultimo = i;
            }
            //--------------ordenação---------------//
            k=i;
            for (j=(i+1);j<listaAux->tamlista;j++){
                if (listaAux->elemento[j].conteudo < listaAux->elemento[k].conteudo)
                    k=j;
            }

            if (i != k){
                aux = listaAux->elemento[i].conteudo;
                listaAux->elemento[i].conteudo = listaAux->elemento[k].conteudo;
                listaAux->elemento[k].conteudo = aux;
            }
        }
    }

};

void imprimelista (tipolistaEE *listaAux){
    int i=0;
    for (i = 0; i < listaAux->tamlista ;i++){
        if (listaAux->elemento[i].conteudo != 0){
            printf("%d ", listaAux->elemento[i].conteudo);
        }
    }
    printf("\n");
};


void retira (tipolistaEE *listaAux, int RRA){
    int i=0,cont=0, x, penultimo=-1;
    listaAux->tamlista --;

    //-------------Remoção----------------
    for (i=0; i < MAX ;i++){
        if (listaAux->elemento[i].conteudo == RRA){
            x = i;
            listaAux->elemento[i].conteudo = listaAux->elemento[i+1].conteudo;
            if (listaAux->elemento[i].conteudo != listaAux->elemento[listaAux->ultimo].conteudo){
                listaAux->elemento[i+1].conteudo = RRA;
            }
        }
        else{
            cont = cont +1 ;
        }
    }
    //-----------Retirada do único elemento da lista (reseta)-----------------
    if(listaAux->tamlista==0){
        listaAux->primeiro=-1;
        listaAux->ultimo=-1;
        listaAux->elemento[x].proximo=-1;
    }
        //-----------Retirada do ultimo elemento da lista-----------------
        else if (x == listaAux->ultimo){
            listaAux->ultimo = listaAux->penultimo;
            listaAux->elemento[x].proximo=-1;
        }

            //-----------Retirada do primeiro elemento da lista-----------------
            else if(x == listaAux->primeiro){
                listaAux->primeiro = listaAux->elemento[x].proximo;
            }

    //--------------Condição livro não existe------------------
    if (cont == MAX){
        printf("nao existe\n");
        listaAux->tamlista ++;
    }
    //-------------Atualizações----------------
    else{
        listaAux->poslivre[x]=1;
    }
};

void ano (tipolistaEE *listaAux, int YRA, int *cont66,int *cont76,int *cont86,int *cont96,int *cont106,int *cont116,int *cont126,int *cont136){
    YRA = YRA / 1000;
        switch (YRA){
            case 66:
                *cont66 = *cont66 + 1;
                break;
            case 76:
                *cont76 = *cont76 + 1;
                break;
            case 86:
                *cont86 = *cont86 + 1;
                break;
            case 96:
                *cont96 = *cont96 + 1;
                break;
            case 106:
                *cont106 = *cont106 + 1;
                break;
            case 116:
                *cont116 = *cont116 + 1;
                break;
            case 126:
                *cont126 = *cont126 + 1;
                break;
            case 136:
                *cont136 = *cont136 + 1;
                break;
            default:
                break;
        }
};

int main(){

    tipolistaEE minhalista;
    inicia(&minhalista);

    int L, RA, i, op;
    int cont66 = 0, cont76 = 0, cont86 = 0, cont96 = 0, cont106 = 0, cont116 = 0, cont126 = 0, cont136 = 0;
    scanf("%d", &L);
    if (L < 1 || L>100){
        exit(1);
    }
    for (i=0; i<L; i++){
        scanf("%d %d", &op, &RA);
        if (RA < 60000 || RA>140000)
            exit(1);
        else
            switch(op){
                case 1:
                    if ((insere(&minhalista,livre(&minhalista), RA)) == 1 )
                        ano(&minhalista, RA, &cont66, &cont76, &cont86, &cont96, &cont106, &cont116, &cont126, &cont136);
                    else
                      printf("lista cheia\n");
                    ordena(&minhalista);
                    imprimelista(&minhalista);
                    break;
                case 2:
                    retira(&minhalista, RA);
                    ordena(&minhalista);
                    imprimelista(&minhalista);
                    break;
                default:
                    exit(1);
            }
    }

    printf("2011: %d\n2012: %d\n2013: %d\n2014: %d\n2015: %d\n2016: %d\n2017: %d\n2018: %d\n", cont66, cont76, cont86, cont96, cont106, cont116, cont126, cont136);
    return 0;
}
