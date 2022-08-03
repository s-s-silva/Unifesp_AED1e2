#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define false 0
#define true  1
#define M 2 // grau
#define MM (2*M) // maximo

typedef struct Item Item;
typedef struct Pagina Pagina;

struct Item {
    int Chave;
};

struct Pagina {
    int n;
    Item r[MM];
    Pagina *p[MM + 1]; //Permite um filho a mais
};


Pagina* Inicia();

void Insere(Pagina **p, Item r);
void InsereNaPagina(Pagina *p, Pagina *pdir, Item r);
void InsertManutencao(Pagina **p, Pagina **po, Item r, Item *desalocado, int *Overflow);
void BuscaBin(Pagina *p, Item *r);
void Saida(Pagina **p, int procurado);
void SaidaNaoRaiz(Pagina **p, int nivel, int procurado, int *resul);

Pagina* Inicia(){
  return NULL;
} // Inicializa nula


void BuscaBin(Pagina *p, Item *r){
    int i = 1;

    if(p == NULL){
        return;
    }

    while (i < p->n && r->Chave > p->r[i-1].Chave) i++;

    if (r->Chave == p->r[i-1].Chave){
        *r = p->r[i-1];
        return;
    }

    if (r->Chave < p->r[i-1].Chave)
        BuscaBin(p->p[i-1], r);
    else
        BuscaBin(p->p[i], r);
}


void InsereNaPagina(Pagina *p, Pagina *pdir, Item r){
    int aux; // auxiliar para marcar que não é a posição
    int k;

    k = p->n;
    aux = (k > 0);

    while (aux){

        if (r.Chave >= p->r[k-1].Chave){
        aux = false;
        break;
    }

        p->r[k]   = p->r[k-1];
        p->p[k+1] = p->p[k];
        k--;

        if (k < 1)
        aux = false;
    }

    p->r[k] = r;
    p->p[k+1] = pdir;
    p->n++;

}

void InsertManutencao(Pagina **p, Pagina **po, Item r, Item *desalocado, int *Overflow){
    int i=1, j;
    Pagina *paux;

    if (*p == NULL){
        *Overflow = true;
        *desalocado = r;
        *po = NULL;
        return;
    }

    while (i < (*p)->n && r.Chave > (*p)->r[i-1].Chave)  i++;

    if (r.Chave == (*p)->r[i-1].Chave){
        *Overflow = false;
        return;
    }

    if (r.Chave < (*p)->r[i-1].Chave) i--;

    InsertManutencao(&(*p)->p[i], po, r, desalocado, Overflow);


    if (!*Overflow) return;

    if ((*p)->n < MM){
        InsereNaPagina(*p, *po, *desalocado);
        *Overflow = false;
        return;
    }

   // divide
    paux = (Pagina*)malloc(sizeof(Pagina));
    paux->n = 0;
    paux->p[0] = NULL;

    if (i < M + 1){
        InsereNaPagina(paux, (*p)->p[MM], (*p)->r[MM-1]);
        (*p)->n--;
        InsereNaPagina(*p, *po, *desalocado);
    }else
        InsereNaPagina(paux, *po, *desalocado);

    for (j=M+2; j<=MM; j++)
        InsereNaPagina(paux, (*p)->p[j], (*p)->r[j-1]);

    (*p)->n = M;
    paux->p[0] = (*p)->p[M+1];
    *desalocado = (*p)->r[M];
    *po = paux;
}


void Insere(Pagina **p, Item r){
    int Overflow;
    Item desalocado;
    Pagina *po, *paux;


    InsertManutencao(p, &po, r, &desalocado, &Overflow);

    if (Overflow){
        paux = (Pagina *)malloc(sizeof(Pagina));
        paux->n = 1;
        paux->r[0] = desalocado;
        paux->p[0] = *p;
        paux->p[1] = po;
        *p = paux;
    } //altura ++
}

void Saida(Pagina **p, int procurado){
    int i;

    if (*p == NULL) return;

    printf("\n%d", (*p)->n);
}

void SaidaNaoRaiz(Pagina **p, int nivel, int procurado, int *resul){
    int i, cont=0;

    if (*p == NULL) return;

    for (i = 0; i < (*p)->n; i++){
        if ((*p)->r[i].Chave == procurado){
            *resul = (*p)->n;
            printf("\n%d", *resul);
            return;
        }
    }
    nivel++;

    for (i = 0; i <= (*p)->n; i++)
        SaidaNaoRaiz(&(*p)->p[i], nivel, procurado, resul);

}


int main(){

    int  Entrada, Busca, i, resul = 0;

    Item r;
  	Pagina *btree = Inicia();

	while (Entrada != -1){
        scanf("%d",&Entrada);
        if (Entrada != -1){
            r.Chave = Entrada;
            Insere(&btree, r);
        }
	}
	scanf("%d", &Busca);
    Saida(&btree, Busca);
    SaidaNaoRaiz(&btree,0, Busca, &resul);
    if(resul == 0){
     printf("\nValor nao encontrado");
   }

	return 0;
}

