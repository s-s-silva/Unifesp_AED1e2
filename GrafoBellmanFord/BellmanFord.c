#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999


struct Edge
{
    int u;
    int v;
    int w;
};

struct Graph
{
    int V;
    int E;
    struct Edge *edge;
};

void bellmanford(struct Graph *g, int source, int noInicial, int R);

int main()
{
    int i,j,k,w, noInicial, R;

    struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
    scanf("%d",&noInicial);
    scanf("%d",&R);
    scanf("%d",&(g->V));
    scanf("%d",&(g->E));

    g->edge=(struct Edge*)malloc(g->E*sizeof(struct Edge));

    for(k=0;k<(g->E);k++)
    {
        scanf("%d %d %d",&i,&j,&w);
        g->edge[k].u=i;
        g->edge[k].v=j;
        g->edge[k].w=w;
    }

    bellmanford(g,0, noInicial, R);

    return 0;
}


void bellmanford(struct Graph *g, int source, int noInicial, int R){

    int i,j,u,v,w;
    int tV=g->V, tE=g->E, d[tV], p[tV], aux[tV];

    /*Inicializa*/

    for (i=0;i<tV;i++)
    {
        d[i]=INFINITY;
        //p[i]= -1;
    }
    d[noInicial]=0;

    /* Relaxa arestas */

    for(i=1;i<=tV-1;i++)
    {
        for(j=0;j<tE;j++)
        {
            u=g->edge[j].u;
            v=g->edge[j].v;
            w=g->edge[j].w;

            if(d[u]!=INFINITY && d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                p[v]=u;
            }
        }
    }

    /* Verifica ciclo negativo */


    for(i=0;i<tE;i++)
    {
        u=g->edge[i].u;
        v=g->edge[i].v;
        w=g->edge[i].w;
        if(d[u]!=INFINITY && d[v]>d[u]+w)
        {
            return;
        }
    }

    /* Saída */

    for(i=0;i<tV;i++)
    {
        printf("%d ", d[i]);
    }

}






