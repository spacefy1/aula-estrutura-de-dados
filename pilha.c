/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int conteudo;
    struct elemento *prox;
} Elem;

typedef struct elemento* Pilha;

Pilha* cria_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi!=NULL){
        *pi = NULL;
    }
    return pi;
}

int push(Pilha* pi, int x){
    if(pi == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    
    if (no ==NULL){
        return 0;
    }
    no->conteudo = x;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int consulta_topo(Pilha* pi){
    if(pi == NULL || (*pi)==NULL){
        return -1;
    }
    
    return(*pi)->conteudo;
}

int pop(Pilha* pi){
    if(pi == NULL || (*pi)==NULL){
        return -1;
    }
    Elem *no = *pi;
    *pi = no->prox;
    int valor_retorno = no->conteudo;
    free(no);
    return valor_retorno;
}

void libera_pilha((Pilha* pi)){
    if(pi!=NULL){
        Elem *no;
        while((*pi)!=NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

void imprimir(Pilha* pi){
    if(pi!=NULL){
        Elem* no = *pi;
        printf("TOPOPILHA");
        while(no!=NULL){
            printf("\nConteudo: %d", no->conteudo);
            no = no->prox;
        }
        printf("\nBASEPILHA");
    }
    
}

int main()
{
    printf("INICIO PROGRAMA");
    Pilha *pi = cria_pilha();
    push(pi, 0);
    push(pi, 1);
    push(pi, 2);
    push(pi, 3);
    push(pi,4);
    imprimir(pi);
    pop(pi);
    imprimir(pi);
    return 0;
}
