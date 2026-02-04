#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

#define MAX 10

// Static queues 

void SinitQueue (SQueue q){
	q->front = 0;
    q->length = 0;
}

int  SisEmptyQ (SQueue q){
    if (q->length == 0){
        return 1;
    }
	return 0;
}

int  Senqueue (SQueue q, int x){
	int r = 0;
    if (q->length == MAX){
        r = 1;
    }
    else{
        q->values[(q->length + q->front) % MAX] = x;
        q->length++;
    }
	return r;
}

int  Sdequeue (SQueue q, int *x) {
	int r = 0;
	if (q->length == 0){
        r = 1;
    }
    else{
        *x = q->values[q->front % MAX];
        q->front = (q->front + 1) % MAX;
        q->length--;
    }
    return r;
}

int  Sfront (SQueue q, int *x) {
	int r = 0;
	if (q->length == 0){
        r = 1;
    }
    else{
        *x = q->values[q->front];
    }
	return r;
}

void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%Max;
    }
    putchar ('\n');
}

// Queues with dynamic arrays

int dupQueue (DQueue q) {
	int *t = malloc(2 * q->size * sizeof(int));
    for (int i = 0; i < q->size; i++){
        t[i] = q->values[i];
    }
    free(q->values);
    q->values = t;
    q->size = q->size * 2;
	return *t;
}

void DinitQueue (DQueue q) {
	q->length = 0;
	q->size = 1;
	q->front = 0;
	q->values = malloc(q->size * sizeof(int));
}

int  DisEmptyQ (DQueue q) {
	int r = 0;
    if (q->length == 0){
        r = 1;
    }
    return r;
}

int  Denqueue (DQueue q, int x){
	int r = 0;
    if (q->length == q->size){
        r = 1;
    }
    else{
        q->values[(q->front + q->length) % q->size] = x;
        q->length++;
    }
	return r;
}

int  Ddequeue (DQueue q, int *x){
	int r = 0;
	if (q->length == 0){
        r = 1;
    }
    else{
        *x = q->values[q->front];
        q->front = (q->front + 1) % q->size;
        q->length--;
    }
    return r;
}

int  Dfront (DQueue q, int *x){
	int r = 0;
	if (q->length == 0){
        r = 1;
    }
    else{
        *x = q->values[q->front];
    }
    return r;
}

void ShowDQueue (DQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%q->size;
    }
    putchar ('\n');
}
