#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void initStack (Stack *s){
    *s = NULL;
}

int SisEmpty (Stack s){
    int r = 0;
    if (s != NULL){
        r = 1;
    }
    return r;
}

int push (Stack *s, int x){
    Stack novo = malloc(sizeof(struct slist));

    if (novo == NULL){
        return 1;
    }
    novo->valor = x;
    novo->prox = *s;
    return 0;
}

int pop (Stack *s, int *x){
    if (s == NULL){
        return 1;
    }
    Stack temp = *s;
    *x = temp->valor;
    *s = temp->prox;
    free(temp);
    return 0;
}

int top (Stack s, int *x){
    if (s == NULL){
        return 1;
    }
    *x = s->valor;
    return 0;
}
