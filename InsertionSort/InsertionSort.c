#include <stdio.h>
#include <stdlib.h>
 
int ordena(int vet[], int tam){
 
    int index, aux;
    if (tam <= 1) //critério de parada
      return 0;
 
   ordena( vet, tam-1 ); 
 
   aux = vet[tam-1]; //passa o valor que estamos checando para uma variável auxíliar
   index = tam-2;
   while (index >= 0 && vet[index] > aux){ // se o vet[index] for maior que aux, então o vet[index] pula uma casa
      vet[index+1] = vet[index];
      index--;
   }
   vet[index+1] = aux; //Por fim, o aux retorna uma casa, até encontrar seu lugar
 
};
 
void imprimevet(int vet[], int N){
 
    int i;
    for (int i=0; i < N; i++)
        printf("%d ",vet[i]);
};
 
int main(){
 
    int N, i, num, tam;
 
    scanf("%d", &N);
    if (N > 1000 || N < 1)
        exit(1);

    int *vet, nv = N; 
    vet = (int *) malloc(N * sizeof(int));
 
    for (i=0; i<N; i++){
        scanf("%d", &num);
        vet[i] = num;
        tam = i+1; 
        ordena(vet, tam); 
        if (i!= 0){
            printf("%d %d",nv,num);
            for (int j=0; j<N; j++){
                if (num == vet[j])
                    printf(" %d \n", j);
            }
        }
        nv --;
    }
    imprimevet(vet, N);

    free(vet);
    return 0;
}
