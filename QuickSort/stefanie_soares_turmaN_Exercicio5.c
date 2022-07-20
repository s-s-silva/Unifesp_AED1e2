#include <stdio.h>
#include <stdlib.h>


int partition(int vet[], int inicio, int fim){
	int i, j,x, aux;


	x = vet[fim];
	i = inicio-1;

	if (fim>inicio){
		for (j=inicio;j<fim;j++){
			if (vet[j] <= x ){
				i++;
				if ( i != j){
                   aux =vet[i];
                    vet[i]=vet[j];
                    vet[j]=aux;
				}
			}
		}

	}

	aux=vet[i+1];
	vet[i+1]=vet[j];
	vet[j]=aux;

	return i + 1;
}

void quicksort (int vet[], int inicio, int fim, int N, int k){
    int q, i;

    if (inicio < fim){
        q = partition(vet, inicio, fim);
        if (q == k){
            printf("%do menor elemento eh o %d \n", k, vet[k]);
            for (int i=1; i <= N; i++){
                printf("%d ",vet[i]);
            }
        }
        quicksort(vet, inicio, q -1,N, k);
        quicksort(vet, q +1, fim, N, k);
    }
}


int main (){

    int *vet, k, N, num, i;
    vet = (int *) malloc (N* sizeof(int));

    scanf("%d", &k);
    if (k < 0)
        exit(1);

    scanf("%d", &N);
    if (N < 1)
        exit(1);

    for (i=1; i<=N; i++){
        scanf("%d", &num);
        vet[i] = num;
    }

    quicksort (vet, 1, N, N, k);

    free(vet);
    return 0;

}
