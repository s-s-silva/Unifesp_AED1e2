//Stefanie Soares, 133808
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10

struct listaES {
    int ultimo;
    int tamlista;
    int lista[MAX];
};
typedef struct listaES tipolistaES;
void inicia (tipolistaES *listaAux){
    int i;
    listaAux -> tamlista = 0;
    for (i=0; i<MAX; i++)
        listaAux -> lista[i]=0;
    listaAux -> ultimo = 0;
}
void insere (tipolistaES *listaAux, int NLRES){
    if (listaAux->tamlista == MAX){
        printf("Lista de reserva cheia\n");
        exit(1);
    }
    listaAux -> tamlista ++;
    listaAux ->lista[listaAux -> tamlista - 1] = NLRES;
    listaAux -> ultimo = listaAux -> tamlista-1;
    printf("Sua reserva foi realizada \n");
}
void imprime (tipolistaES *listaAux){
    int i;
    for (i=0; i<MAX; i++)
        printf("%d", listaAux -> lista[i]);
        printf("\n");
}
void retira (tipolistaES *listaAux, int NLRET){
   int i, j;
    for (i=0; i<MAX; i++){
        if (listaAux->lista[i] == NLRET){
           listaAux->lista[i] = listaAux->lista[i + 1];
                if (listaAux->lista[i] != listaAux->lista[listaAux->ultimo])
                    listaAux->lista[i + 1] = NLRET;
        }
    }
    listaAux->lista[listaAux->ultimo] = 0;
    listaAux->tamlista --;
    printf("O livro foi retirado com sucesso\n");
}
int main(){
    tipolistaES minhalista;
    inicia (&minhalista);

    int L, op, N,i, contres=0, contret=0;
    scanf("%d", &L);
    if (L < 1 || L>100)
        exit(1);

    for (i=0; i<L; i++)
    {
        scanf("%d %d", &op, &N);
        if (N < 1 || N>100)
            exit(1);
        else
            switch (op)
            {
                case 1:
                    insere(&minhalista, N);
                    contres ++;
                    break;
                case 2:
                    retira(&minhalista, N);
                    contret++;
                    break;
                default:
                    exit(1);
            }
    }
    printf("Voce realizou %d reservas e %d retiradas", contres, contret);
    return 0;
}

