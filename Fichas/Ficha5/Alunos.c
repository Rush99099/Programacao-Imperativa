#include <stdio.h>
#include "Alunos.h"

void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
}
void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}

int nota (Aluno a){
    float r = 0;
    int mt = 0;
    for (int i = 0; i < 6; i++){
        mt += a.miniT[i];
    }
    mt = mt / 6;
    r = a.teste;
    if ((mt*0.2) + (r*0.8) >= 10){
        return (int)r;
    }
    return 0;
}

int procuraNum (int num, Aluno t[], int N){
    for (int i = 0; i < N; i++){
        if (num == t[i].numero){
            return i;
        }
    }
    return -1;
}

void ordenaPorNum (Aluno t [], int N){
    Aluno temp;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (t[j].numero > t[j+1].numero){
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
    }
}

int procuraNumInd (int num, int ind[], Aluno t[], int N){
    
    return -1;
}

void criaIndPorNum (Aluno t [], int N, int ind[]){
    int temp;
    for (int i = 0; i < N; i++){
        ind[i] = i;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-1; j++){
            if (t[ind[j]].numero > t[ind[j+1]].numero){
                temp = ind[j];
                ind[j] = ind[j+1];
                ind[j+1] = temp;
            }
        }
    }
}

void criaIndPorNome (Aluno t [], int N, int ind[]){
    int temp;
    for (int i = 0; i < N; i++){
        ind[i] = i;
    }
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-1; j++){
            if (strcmp(t[ind[j]].nome, t[ind[j+1]].nome) > 0){
                temp = ind[j];
                ind[j] = ind[j+1];
                ind[j+1] = temp;
            }
        }
    }
}

void imprimeTurmaInd (int ind[], Aluno t[], int N){
    imprimeTurmaInd(ind,t,N);
}
