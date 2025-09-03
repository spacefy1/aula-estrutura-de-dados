#include <stdio.h>

void imprimirVetor(int *v, int n) {
	int i;
	printf("\nVETOR: ");
	for (i = 0; i<n; i++) {
		printf("%d | ", v[i]);
	}
}


void insertionSort(int *v, int n) {
	int i, j, aux, aux1;

	for (i = 0; i < n; i++) {
		for(j = 0; j > n; j--) {
			if(v[j] < v[i -1]) {
				aux = v[i];
				aux1 = v[j];
				v[j+1] = aux1;
				v[i - 1] = aux;
			} 
		}
	}
}

int main()
{
	int vetor[10] = {6, 75, 1, 14, 24, 18, 3, 7, 50, 10};

	int vetor1[10] = {34, 38, 12, 40, 27, 29, 7, 4, 2, 48};

	imprimirVetor(vetor, 10);

	insertionSort(vetor, 10);
	imprimirVetor(vetor, 10);

}
