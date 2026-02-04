#include "abin.h"


ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}

int altura (ABin a){
    return (-1);
}

int nFolhas (ABin a){
    return (-1);
}

ABin maisEsquerda (ABin a){
    return NULL;
}

void imprimeNivel (ABin a, int l){
    
}

int procuraE (ABin a, int x){
    return (-1);
}

struct nodo *procura (ABin a, int x){
    return NULL;
}

int nivel (ABin a, int x){
    return (-1);
}

void imprimeAte (ABin a, int x){
    
}
