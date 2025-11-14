#include <stdio.h>
#include <stdlib.h>
typedef struct NO {
	int info;
	struct NO *esq;
	struct NO *dir;
} NO;

typedef struct NO *ArvBin;

ArvBin* cria_ArvBin() {
	ArvBin *raiz = (ArvBin*)malloc(sizeof(ArvBin));
	if(raiz!=NULL) {
		*raiz = NULL;
	}
	return raiz;
}

void preOrdem_ArvBin(ArvBin *raiz) {
	if(raiz == NULL ) {
		return;
	}
	if(*raiz!=NULL) {
		printf("%d ", (*raiz)->info);
		preOrdem_ArvBin(&((*raiz)->esq));
		preOrdem_ArvBin(&((*raiz)->dir));
	}
}

void emOrdem_ArvBin(ArvBin *raiz) {
	if(raiz == NULL ) {
		return;
	}
	if(*raiz!=NULL) {
		preOrdem_ArvBin(&((*raiz)->esq));
		printf("%d ", (*raiz)->info);
		preOrdem_ArvBin(&((*raiz)->dir));
	}
}

void posOrdem_ArvBin(ArvBin *raiz) {
	if(raiz == NULL ) {
		return;
	}
	if(*raiz!=NULL) {
		preOrdem_ArvBin(&((*raiz)->esq));
		preOrdem_ArvBin(&((*raiz)->dir));
		printf("%d ", (*raiz)->info);
	}
}

int totalNosArvBin(ArvBin *raiz) {
	if(raiz == NULL) {
		return 0;
	}
	if(*raiz == NULL) {
		return 0;
	}

	int total_esq = totalNosArvBin(&((*raiz)->esq));
	int total_dir = totalNosArvBin(&((*raiz)->dir));

	return total_esq + total_dir +1;

}


int altura_arvBin(ArvBin *raiz) {
	int alt_esq = 0, alt_dir = 0;
	if(raiz == NULL || *raiz == NULL) {
		return -1;
	}

  	alt_esq = altura_arvBin(&((*raiz)->esq));
    alt_dir = altura_arvBin(&((*raiz)->dir));
	if(alt_esq>alt_dir) {
		return alt_esq +1;
	} else {
		return alt_dir +1;
	}

}

void libera_NO(NO *no){
    if(no == NULL){
        return;
    }
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}

int insere_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){//validando a existencia da arvore
        return 0;
    }
    //criando o no que vai ser inserido
    NO *novo  = (NO*) malloc (sizeof(NO));
    if(novo == NULL){
        return 0;
    }
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    
    //primeira possibilidade, a arvore é vazia.
    if(*raiz == NULL){
        *raiz = novo;
    }
    else{//se nao for primeiro elemento
        NO *atual = *raiz;
        NO *ant = NULL;
        while(atual!=NULL){//percorre a arvore para achar o lugar de inserção.
            ant = atual;
            if(valor == atual->info){//verifica repetidos
                free(novo);
                return 0;
            }
            if(valor > atual->info){//escolhe o lado de caminhar.
                atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if(valor>ant->info){
            ant->dir = novo;
        }else{
            ant->esq = novo;
        }
    }
    
    return 1;
}


int main()
{
	printf("Inicio\n");
	ArvBin *raiz = cria_ArvBin();
	
	insere_ArvBin(raiz, 10);
	insere_ArvBin(raiz, 50);
	insere_ArvBin(raiz, 80);
	insere_ArvBin(raiz, 5);
	insere_ArvBin(raiz, 20);


	printf("Pre-Ordem:\n");
	preOrdem_ArvBin(raiz);

	printf("\nEm-Ordem:\n");
	emOrdem_ArvBin(raiz);

	printf("\nPos-Ordem:\n");
	posOrdem_ArvBin(raiz);

	printf("\nTOTAL DE NOS:\n");
	printf("%d", totalNosArvBin(raiz));
	printf("\nALTURA:\n");
	printf("%d", altura_arvBin(raiz));

	remove_ArvBin(raiz, 5);
	printf("\nTOTAL DE NOS:\n");
	printf("%d", totalNosArvBin(raiz));
	return 0;
}
