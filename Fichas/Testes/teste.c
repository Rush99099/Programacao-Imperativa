#include <stdlib.h>

typedef struct {
    int inf,sup;
} Intervalo;

typedef struct no{
    int valor;
    struct no *prox;
} *LInt;

typedef struct nodo{
    int valor;
    struct nodo *esq, *dir;
} *ABin;

//Exercício 1
void ordena(Intervalo c[], int N){
    //O que queres é uma função que ordena os intervalos pelo inf
    Intervalo temp;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-1; j++){
            if (c[j].inf > c[j+1].inf){
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }
}

//Exercício 2
int cardinalidade(Intervalo c[], int N){
    int cont = 0;
    int inicial_inf = c[0].inf;
    int inicial_sup = c[0].sup;

    for (int i = 1; i < N; i++){
        if (c[i].inf > inicial_sup){
            cont += (inicial_sup - inicial_inf + 1);
            inicial_inf = c[i].inf;
            inicial_sup = c[i].sup;
        }
        else{
            if (c[i].sup > inicial_sup){
                inicial_sup = c[i].sup;
            }
        }
    }
    cont += (inicial_sup - inicial_inf + 1);
    return cont;
}

//Exercício 3
void camel2snake(char *id) {
    int i = 0, j = 0;
    char temp[256]; // buffer temporário, assume que id tem menos de 256 chars

    while (id[i] != '\0') {
        if (id[i] >= 'A' && id[i] <= 'Z') {
            temp[j++] = '_';
            temp[j++] = id[i] + 32; // converte para minúscula
        } else {
            temp[j++] = id[i];
        }
        i++;
    }
    temp[j] = '\0';

    // copia de volta para id
    i = 0;
    while (temp[i] != '\0') {
        id[i] = temp[i];
        i++;
    }
    id[i] = '\0';
}

void snake2camel(char *id){
    int i = 0, j = 0;
    char temp[256]; // buffer temporário, assume que id tem menos de 256 chars

    while (id[i] != '\0'){
        if (id[i] == '_' && id[i+1] >= 'a' && id[i+1] <= 'z'){
            temp[j++] = id[i + 1] - 32;
            i+=2;
        }
        else if(id[i] == '_'){
            i++;
        }
        else{
            temp[j++] = id[i++];
        }
    }
    temp[j] = '\0';
    i = 0;
    while (temp[i] != '\0'){
        id[i] = temp[i];
        i++;
    }
    id[i] = '\0';
}

//Exercício 4
LInt arrayToList(int v[], int N){
    if (N == 0){
        return NULL;
    }

    LInt l = malloc(sizeof(struct no));
    l->valor = v[0];
    l->prox = NULL;
    
    LInt temp = l;

    for (int i = 1; i < N; i++){
        temp->prox = malloc(sizeof(struct no));
        temp = temp->prox;
        temp->valor = v[i];
        temp->prox = NULL;
    }
    return l;
}

//Exercício 5
int apagaUltimo(LInt *l, int x){
    LInt atual = *l;
    LInt prev = NULL;
    LInt ult = NULL;
    LInt ult_prev = NULL;
    
    while (atual != NULL){
        if (atual->valor == x){
            ult = atual;
            ult_prev = prev;
        }
        prev = atual;
        atual = atual->prox;
    }
    if (ult == NULL){
        return -1;
    }
    if (ult_prev == NULL){
        *l = ult->prox;
    }
    else{
        ult_prev->prox = ult->prox;
    }
    free(ult);
    return 0;
}

//Exercício 6
int parentesco(ABin a, int x, int y) {
    // 1. Encontrar o menor ancestral comum (LCA)
    ABin atual = a;
    while (atual != NULL) {
        if (x < atual->valor && y < atual->valor)
            atual = atual->esq;
        else if (x > atual->valor && y > atual->valor)
            atual = atual->dir;
        else
            break; // Encontrou o LCA
    }
    // 2. Contar passos do LCA até x
    int dist_x = 0;
    ABin temp = atual;
    while (temp->valor != x) {
        dist_x++;
        if (x < temp->valor) temp = temp->esq;
        else temp = temp->dir;
    }
    // 3. Contar passos do LCA até y
    int dist_y = 0;
    temp = atual;
    while (temp->valor != y) {
        dist_y++;
        if (y < temp->valor) temp = temp->esq;
        else temp = temp->dir;
    }
    // 4. Soma das distâncias
    return dist_x + dist_y;
}