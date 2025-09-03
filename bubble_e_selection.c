#include <stdio.h>

void imprimirVetor(int *v, int n) {
	int i;
	printf("\nVETOR: ");
	for (i = 0; i<n; i++) {
		printf("%d | ", v[i]);
	}
}

void selectionSort(int *v, int n) {
	int i, j, menor, aux;
	for(i=0; i<n-1; i++) { //percorre o vetor inteiro.
		menor = i;
		for(j=i+1; j<n; j++) { //percorre do i  atC) o final
			if(v[j]<v[menor]) { //verifica se achou um menor que o atual
				menor=j;//atualiza o menor
			}
		}
		if(i!=menor) { //se achou um menor que o lugar que estou, eu troco.
			aux = v[i];
			v[i] = v[menor];
			v[menor] = aux;
		}
	}
}

void bubbleSort(int *v, int n) {
	int i, aux, troca;
	//mudei o bubble com uma logica melhor, pensando assim no tmepo de execuçao
	do{
	   troca = 0;
	   for (i = 0; i < n-1; i++) {
    		if(v[i] > v[i+ 1]) {
    			aux = v[i];
    			v[i] = v[i + 1];
    			v[i + 1] = aux;
    			troca = 1;
    		}
    	} 
	}while(troca);
    	
}





int main()
{
	int vetor[10] = {6, 75, 1, 14, 24, 18, 3, 7, 50, 10};

	imprimirVetor(vetor, 10);
	selectionSort(vetor, 10);
	imprimirVetor(vetor, 10);
	bubbleSort(vetor, 10);
	imprimirVetor(vetor, 10);


}
