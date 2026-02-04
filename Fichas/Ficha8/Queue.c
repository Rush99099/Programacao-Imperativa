#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void initQueue (Queue *q){
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty (Queue q){
    if (q.inicio == NULL){
        return 1;
    }
    return 0;
}

int enqueue (Queue *q, int x){
    LInt nova = malloc(sizeof(struct slist));
    if (nova == NULL){
        return 1;
    }
    nova->valor = x;
    nova->prox = NULL;
    if (q->fim == NULL){
        q->inicio = q->fim = nova;
    }
    else{
        q->fim->prox = nova;
        q->fim = nova;
    }
    return 0;
}

int dequeue (Queue *q, int *x){
    if (q == NULL){
        return 1;
    }
    LInt temp;
    temp = q->inicio;
    *x = temp->valor;
    q->inicio = temp->prox;
    free(temp);    
    return 0;
}

int frontQ (Queue q, int *x){
    if (q.inicio == NULL){
        return 1;
    }
    else{
        *x = q.inicio->valor;
    }
    return 0;
}

typedef LInt QueueC;

void initQueueC (QueueC *q){
    *q = NULL;
}

int QisEmptyC (QueueC q){
    if (q == NULL){
        return 1;
    }
    q = NULL;
    return 0;
}

int enqueueC (QueueC *q, int x){
    LInt nova = malloc(sizeof(struct slist));
    if (nova == NULL){
        return 1;
    }
    nova->valor = x;
    if (*q == NULL){
        nova->prox = nova;
        *q = nova;
    }
    else{
        nova->prox = (*q)->prox;
        (*q)->prox = nova;
        *q = nova;
    }
    
    return 0;
}

int dequeueC (QueueC *q, int *x){
    LInt temp = (*q)->prox;
    if (*q == NULL){
        return 1;
    }
    else{
        *x = temp->valor;
        (*q)->prox = temp->prox;
        free(temp);
    }
    return 0;
}

int frontC (QueueC q, int *x){
    if (q == NULL){
        return 1;
    }
    else{
        *x = q->prox->valor;
    }
    return 0;
}
