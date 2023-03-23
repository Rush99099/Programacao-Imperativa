#include <stdio.h>

//1.
float multInt1 (int n, float m){
    int r = 0;
    for (int i = 0; i < n; i++){
        r += m;
    }
    return r;
}

//2.
float multInt2 (int n, float m){
    int r = 0;
    while (n > 0){
        if (n % 2 == 1){
            r += m;
        }
        n /= 2;
        m *= 2;
    }
    return r;
}

//3.
int mdc1 (int a, int b){
    int r = 0;
    for (int i = 1; i <= a && i <= b; i++){
        if (a % i == 0 && b % i == 0){
            r = i;
        }
    }
    return r;
}

//4.
int mdc2 (int a, int b){
    int r = 0;
    while (a != b){
        if (a > b){
            a -= b;
        }
        else{
            b -= a;
        }
    }
    r = a;
    return r;
}

//5.
int mdc3 (int a, int b){
    int r = 0;
    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//6.
int fib1 (int n){
    int r = 0;
    if (n == 0){
        r = 0;
    }
    else if (n == 1){
        r = 1;
    }
    else{
        r = fib1(n-1) + fib1(n-2);
    }
    return r;
}

int fib2 (int n){
    int r = 0;
    int a = 0;
    int b = 1;
    if (n == 0){
        r = 0;
    }
    else if (n == 1){
        r = 1;
    }
    else{
        for (int i = 2; i <= n; i++){
            r = a + b;
            a = b;
            b = r;
        }
    }
    return r;
}

int main(){
    int n = 0;
    int m = 0;
    printf("Insira dois numeros inteiros: ");
    scanf("%d %d", &n, &m);
    printf("Resultado da multiplicacao1: %f\n", multInt1(n, m));
    printf("Resultado da multiplicacao2: %f\n", multInt2(n, m));
    printf("Resultado do mdc1: %d\n", mdc1(n, m));
    printf("Resultado do mdc2: %d\n", mdc2(n, m));
    printf("Resultado do mdc3: %d\n", mdc3(n, m));
    printf("Resultado da sequencia de fibonacci1: %d\n", fib1(n));
    printf("Resultado da sequencia de fibonacci2: %d\n", fib2(n));
    return 0;
}