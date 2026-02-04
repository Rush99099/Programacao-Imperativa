#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras l){
    Palavras temp;
    while (l != NULL){
        temp = l->prox;
        free(l->palavra);
        free(l);
        l = temp;
    }
}

int quantasP (Palavras l){
    int cont = 0;
    while (l != NULL){
        cont++;
        l = l->prox;
    }
    return cont;
}

void listaPal (Palavras l){
    while (l != NULL){
        printf("%s (%d)\n", l->palavra, l->ocorr);
        l = l->prox;
    }    
}

char * ultima (Palavras l){
    char *last = l->palavra;
    while (l->prox != NULL){
        l = l->prox;
    }
    last = l->palavra;
    return last;
}

Palavras acrescentaInicio (Palavras l, char *p){
    Palavras novo = malloc(sizeof(struct celula));
    novo->palavra = p;
    novo->ocorr = 1;
    novo->prox = l;
    return novo;
}

Palavras acrescentaFim (Palavras l, char *p){
    Palavras novo = malloc(sizeof(struct celula));
    while (l->prox != NULL){
        l = l->prox;
    }
    novo->palavra = p;
    novo->ocorr = 1;
    l->prox = novo;
    return l;
}

Palavras acrescenta(Palavras l, char *p) {
    while (l != NULL) {
        if (strcmp(l->palavra, p) == 0) {
            l->ocorr++;
            return l;
        }
        l = l->prox;
    }
    // Palavra não encontrada, insere no início
    return acrescentaInicio(l, p);
}

struct celula * maisFreq (Palavras l){
    Palavras aux = l;
    while (l != NULL){
        if (l->ocorr > aux->ocorr){
            aux = l;
        }
        l = l->prox;
    }
    return aux;
}

int main () {
    Palavras dic = NULL;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    printf ("\n_____________ Testes _____________\n\n");

    int i; struct celula *p;
    for (i=0;i<44;i++)
        dic = acrescentaInicio (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("ultima palavra inserida: %s\n", ultima (dic));

    libertaLista (dic);

    dic = NULL;

    srand(42);
    
    for (i=0; i<1000; i++)
        dic = acrescenta (dic, canto1 [rand() % 44]);
    
    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    listaPal (dic);
    printf ("ultima palavra inserida: %s\n", ultima (dic));
    
    p = maisFreq (dic);
    //printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);
    
    printf ("\n_________ Fim dos testes _________\n\n");

    return 0;
}

