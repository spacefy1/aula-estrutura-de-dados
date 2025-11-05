#include <stdio.h>

typedef struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
}

typedef struct NO *ArvBin;

ArvBin* cria_ArvBin(){
    ArvBin *raiz = (ArvBin*)malloc(sizeof(ArvBin));
        
    if(raiz!=NULL){
        *raiz = NULL;
    }
    return raiz;
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz==NULL){
        return;
    }
    if(*raiz!=NULL){
        printf("&d", (*raiz)->info); //
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir)); // o endereço do lado direito da raiz
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz==NULL){
        return;
    }
    if(*raiz!=NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("&d", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}   
    
void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz==NULL){
        return;
    }
    if(*raiz!=NULL){
        emOrdem_ArvBin(&((*raiz)->esq)); // o endereço do lado esquerdo da raiz
        emOrdem_ArvBin(&((*raiz)->dir));
        printf("&d", (*raiz)->info);
    }
}

void contar_ArvBin(ArvBin *raiz){
    
}

int main()
{
    ArvBin *raiz = cria_ArvBin();
	NO a,b, c, d, e, f, g, h, i;
	NO *converte = &a;

	a.info = 15;
	a.esq = &b;
	a.dir = &c;
	b.info = 20;
	b.esq = &d;
	b.dir = &e;
	c.info = 7;
	c.esq = &f;
	c.dir = &g;
	d.info = 2;
	d.esq = NULL;
	d.dir = NULL;
	e.info = 32;
	e.esq = &h;
	e.dir = NULL;
	h.info = 5;
	h.esq = NULL;
	h.dir = NULL;
	f.info = 3;
	f.esq = NULL;
	f.dir = NULL;
	g.info = 10;
	g.esq = &i;
	g.dir = NULL;
	i.info = 1;
	i.esq = NULL;
	i.dir = NULL;

	raiz = &converte;

}
