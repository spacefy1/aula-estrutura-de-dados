
#include <stdio.h>

void imprimirVetor(int *v, int n) {
	int i;
	printf("\nVETOR: ");
	for (i = 0; i<n; i++) {
		printf("%d | ", v[i]);
	}
}

void merge(int *V, int inicio, int meio, int fim){
    int i, aux;

    
    temp = (int *) malloc(fim*sizeof(int));
    for(i = 0; i < tamanho; i++){
        if(temp[i+1] > temp[i]){
            aux = temp[i+1];
            temp[i+1] = temp[i];
            merge(V, inicio, meio, fim);
        }
    }
    
}

void mergeSort(int *V, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio+1, fim);
        merge(V, inicio, meio, fim);
    }
    
}
int main()
{
    printf("Hello World");

    return 0;
}
