#include <stdio.h>

void imprimeVetor(int *v, int n){
  printf("\nVetor: |");
  for(int i=0; i<n; i++){
    printf(" %d |", v[i]);
  }
}

void bubbleSort(int *v, int n){
    int troca, aux;
    do{
        troca = 0;
        for(int i = 0; i< n-1; i++){
            if(v[i]>v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                troca = 1;
            }
        }
    }while(troca);
    
}

int main()
{
    int v[] = {6,75,1,14,24,18,3,7,50,10};
    imprimeVetor(v, 10);
    return 0;
}