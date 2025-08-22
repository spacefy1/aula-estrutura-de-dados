
#include <stdio.h>

int buscaLinear(int *V, int n, int procurar) {

	int i;

	//tirei a condicao de parada arbritaria
	for(i = 0; i <= n; i++) {
		if (procurar == V[i])
		{
			return("Indice: %d", i);
		}
	}

	return -1;//elemento nao foi encontrado
}

int buscaSequencial(int *ar1, int n, int procurar){
   int i;
    
    for(i = 0; i<n; i++){
        if (procurar == ar1[i]){
            return i;
        } else if (procurar < ar1[i]){
            return -1;
        }
    }

    return -1;
    
}

int buscaBinaria(int *ar, int size, int procurar){
    int i;
    int half = size / 2;
    
    if(ar[half] >= procurar)
    {
        for (i = 0; i < size; i++){
            if(procurar == ar[i]){
                return i;
            }
        }
    }
    else if(ar[half] <= procurar){
        for (i = 0; i < size; i++){
            if(procurar == ar[i]){
                return -1;
            }
    }
}

}


int main()
{
	int v[7] = {23, 4, 67, -8, 54, 90, 21};
	
	int arr2[7] = {-8, 4, 21, 23, 54, 67, 90};
	
	int procurar;
	
	printf("Digite algum elemento do array ");
	
	scanf("%d", &procurar);

	//procura(*v, 7, procurar);
	
	//buscaSequencial(*arr2, 8, procurar);
	
	buscaBinaria(arr2, 8, procurar);

}
