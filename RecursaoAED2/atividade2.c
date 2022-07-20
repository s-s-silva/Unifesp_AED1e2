#include <stdio.h>
#include <stdlib.h>
 
int compra(int ql, int qv, int v){
    float livros;
 
    livros = qv / v;
    qv = livros + (qv % v);
    ql = ql + livros;
 
    if (qv >= v){
        compra(ql,qv,v);
    }
    else
        return ql;
}
 
int main (){
    int N, d, p, v, i =0, ql, resul;
 
    scanf("%d", &N);
    if (N < 1 || N > 10)
        exit(1);
 
    for (i=0; i<N;i++){
        scanf("%d %d %d", &d, &p, &v);
        if (d < 0 || p < 1 || v <1)
            exit(1);
        ql = d/p; // Faz compra de livros com dinheiro
        printf("%d\n",compra(ql, ql, v));
 
    }
}