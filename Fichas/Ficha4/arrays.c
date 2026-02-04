#include <stdio.h>

void dumpV (int v[], int N){
    int i;
    putchar ('{');
    for (i=0; i<N; i++) printf ("%2d ", v[i]);
    putchar ('}');
}
void simNao (int x){
    if (!x) printf (" nao ");
}

int ordenado (int a[], int N){
    for (int i = 0; i < N-1; i++){
        if (a[i] > a[i+1]){
            return 0;
        }
    }
    return 1;
}

void merge (int a[], int na, int b[], int nb, int r[]){
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < na && j < nb){
        if (a[i] <= b[j]){
            r[k++] = a[i++];
        }
        else{
            r[k++] = b[j++];
        }
    }
    while (i < na){
        r[k++] = a[i++];
    }
    while (j < nb){
        r[k++] = b[j++];
    }
}

int partition (int v[], int N, int x){
    int cont = 0;
    int aux[15];
    int greater = N-1;
    int lesser = 0;
    for (int i = 0; i < N; i++){
        if (v[i] <= x){
            aux[lesser++] = v[i];
            cont++;
        }
        else{
            aux[greater--] = v[i];
        }
    }

    for (int j = 0; j < N; j++){
        v[j] = aux[j];
    }
    
    return cont;
}

int partitionSemAux (int v[], int N, int x){
    int cont = 0;
    int a = 0;
    int b = 0;
    int temp;
    for (b; b < N; b++){
        if (v[b] <= x){
            temp = v[b];
            v[b] = v[a];
            v[a] = temp;
            a++;
            cont++;
        }
        
    }    
    return cont;
}

int main() {  
    int a [15] = {10, 3,45,56, 8,23,13,42,77,31,18,88,24,45, 1},
        b [10] = { 4,12,34,45,48,52,61,73,84,87}, 
        c [10] = { 1, 3, 8,22,33,35,38,41,44,49}, 
        d [50];
    int x;
    
    printf ("Testes\n\n");

//    printf ("O array"); dumpV(a,15);
//    simNao (ordenado (a,15)); printf (" esta ordenado\n");
//    printf ("O array "); dumpV(b,10);
//    simNao (ordenado (b,10)); printf (" esta ordenado\n");
//
//    printf ("\n\nMerge dos arrays "); dumpV (b,10);
//    printf ("\ne                "); dumpV (c,10); 
//    merge (b, 10, c, 10, d);
//    printf ("\nresulta em       "); dumpV (d,20);
//
    printf ("\n\n\nA particao do array  "); dumpV (a,15);
    printf ("\nusando 30 resulta em "); 
    x = partitionSemAux (a,15,30); 
    dumpV (a,15); printf (" e retorna %d \n", x);

    printf ("\nFim dos testes\n");
    return 0;
}