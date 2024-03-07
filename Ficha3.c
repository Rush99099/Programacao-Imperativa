#include <stdio.h>

/*1.a)
int main (){
    int x [15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int *y, *z, i;
    y = x;
    z = x+3;
    for (i=0; i<5; i++) {
        printf ("%d %d %d\n",x[i], *y, *z);
        y = y+1; z = z+2;
    }
}
*/

/*1.b)
int main (){
    int i, j, *a, *b;
    i=3; j=5;
    a = b = 42;
    a = &i; b = &j;
    i++;
    j = i + *b;
    b = a;
    j = j + *b;
    printf ("%d\n", j);
    return 0;
}
*/

/*2.
void swapM (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}*/

/*3.
void swap (int v[], int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
*/

/*4.
int soma (int v[], int N){
    int sum = 0;
    for (int i = 0; i < N; i++){
        sum += v[i];
    }
    return sum;
}
*/

/*5.
void inverteArray1 (int v[], int N){
    int temp;
    for (int i = 0; i < N/2; i++){
        swapM (&v[i], &v[N-1-i]);
    }
}

void inverteArray2 (int v[], int N){
    int temp;
    for (int i = 0; i < N/2; i++){
        swap (&v, i, N-1-i);
    }
}
*/

/*6.
int maximum (int v[], int N, int *m){
    if (N <= 0){
        return 1;
    }
    else{
        for (int i = 0; i < N; i++){
            if (v[i] > *m){
                *m = v[i];
            }
            else{
                continue;
            }
        }
    }
}
*/

//7.
void quadrados (int q[], int N){
    for (int i = 0; i < N; i++){
        q[i] = i*i;
    }
    
}

//8.
void pascal (int v[], int N){
    for (int i = 1; i <= N; i++){
        
    }
    
}

int main (){

}