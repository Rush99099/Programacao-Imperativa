
#include <stdio.h>

/*
1.1.
    int x, y;
    x = 3;
    y = x+1;
    x = x*y;
    y = x + y;
    printf("%d %d\n", x, y);

    Resultado: 12 16

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1.2.
    int x, y;
    x = 0;
    printf ("%d %d\n", x, y);

    Resultado: 0 32726
               Ou não compila porque pede o 'y' mas não é atribuído nenhum valor

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1.3.
    char a, b, c;
    a = ’A’;
    b = ’ ’;
    c = ’0’;
    printf ("%c %d\n", a, a);
    a = a+1;
    c = c+2;
    printf ("%c %d %c %d\n", a, a, c, c);
    c = a + b;
    printf ("%c %d\n", c, c);

    Resultado: A 65
               B 66 2 50
               b 98

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1.4.
    int x, y;
    x = 200;
    y = 100;
    x = x+y;
    y = x-y;
    x = x-y;
    printf ("%d %d\n", x, y);

    Resultado: 100 200

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2.1.
    int x, y;
    x = 3;
    y = 5;
    if (x > y)
        y = 6;
    printf ("%d %d\n", x, y);

    Resultado: 3 5

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2.2.
    int x, y;
    x = y = 0;
    while (x != 11) {
        x = x+1;
        y += x;
    }
    printf ("%d %d\n", x, y);

    Resultado: 11 66

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2.3.
    int i;
    for (i=0; (i<20) ; i++){
        if (i%2 == 0){
            putchar (’_’);
        }
        else{
            putchar (’#’);
        }
    }

    Resultado: _#_#_#_#_#_#_#_#_#_#

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2.4.
void f (int n) {
    while (n>0) {
        if (n%2 == 0){
            putchar (’0’);
        }
        else{
            putchar (’1’);
        }
        n = n/2;
    }
    putchar (’\n’);
}

int main () {
    int i;
    for (i=0;(i<16);i++){
        f(i);
    }
    return 0;
}

    Resultado: 
               1
               01
               11
               001
               101
               011
               111
               0001
               1001
               0101
               1101
               0011
               1011
               0111
               1111

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
3.1.
int main(){
    int t;
    printf("Insira o tamanho do quadrado: ");
    scanf("%d", t);
    for(int i = 0; i < t; i++){
        for(int j = 0; j < t; j++){
            putchar('#');
        }
        putchar('\n');
    }
    return 0;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
3.2.
int main(){
    int t;
    printf("Insira o tamanho do tabuleiro: ");
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        for(int j = 0; j < t; j++){
            if(((i+j)%2)==0){
                putchar('#');
            }
            else{
                putchar('_');
            }
            
        }
        putchar('\n');
    }
    return 0;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
3.3.a)
int main(){
    int a;
    int x = 0;
    int cont = 1;
    printf("Insira a altura do triangulo: ");
    scanf("%d", &a);
    for(int i = 0; i < a; i++){
        while (x < cont){
            putchar('#');
            x++;
        }
        x = 0;
        cont++;
        putchar('\n');
    }
    x = a;
    for (int j = a; j > 0; j--){
        cont = 1;
        while (x > cont){
            putchar('#');
            cont++;
        }
        putchar('\n');
        x--;
    }
    
    return 0;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
3.3.b)
int main(){
    int a;
    int cont = 1;
    printf("Insira a altura do triangulo: ");
    scanf("%d", &a);

    for(int i = 0; i < a; i++){        
        for (int j = i; j < a-1; j++){
            printf(" ");
        }
        for (int h = 0; h < cont; h++){
            printf("#");
        }
        for (int l = 0; l < cont-1; l++){
            printf("#");
        }
        cont++;
        printf("\n");
    }
    
    return 0;
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
3.4.
int main(){
    int r;
    printf("Insira o raio do círculo: ");
    scanf("%d", &r);
    for(int i = 0; i <= 2*r; i++){
        for(int j = 0; j <= 2*r; j++){
            if((i-r)*(i-r) + (j-r)*(j-r) <= r*r){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

                    //////////////////////////////////
                    //                              //
                    //          MINI-TESTE 1        //
                    //                              //
                    //////////////////////////////////

Considere as seguintes funções:

int fizz(int n) {
    return ((n + 4) % 43) == 0;
}

int buzz(int n) {
    return ((n + 6) % 52) == 0;
}

void fizzbuzz(int n) {
    if (fizz(n) && buzz(n))
        printf("FizzBuzz\n");
    else if (fizz(n))
        printf("Fizz\n");
    else if (buzz(n))
        printf("Buzz\n");
    else
        printf("%d\n", n);
}

Considere ainda uma função void fizzbuzz_range(int from, int to) 
que replica a funcionalidade da função fizzbuzz para a sequência de 
valores entre from (inclusive) e to (exclusive).

Se esta função for invocada da seguinte forma:

fizzbuzz_range(467, 5467);

Perguntas:

1. Quantos "Fizz" são impressos na totalidade?

2. Quantos números são precisos para os ter os três tipos de impressões?

Resolução:

void fizzbuzz_fizz(int from, int to){
    int count = 0;
    for (int n = from; n < to; n++) {
        if (fizz(n) && buzz(n));
        else if (fizz(n))
            count++;
        else if (buzz(n));
        else;
    }
        printf("Number of Fizz: %d\n", count);
}

void fizzbuzz_all(int from, int to){
    int fizzFound = 0;
    int buzzFound = 0;
    int fizzBuzzFound = 0;
    int n = 467;
    int count = 0;
    
    while (!fizzFound || !buzzFound || !fizzBuzzFound) {
        if (fizz(n) && buzz(n)) {
            fizzBuzzFound = 1;
        } else if (fizz(n)) {
            fizzFound = 1;
        } else if (buzz(n)) {
            buzzFound = 1;
        }
        else count++;
        n++;
    }
    printf("Number of numbers printed: %d\n", count);
    printf("Number of positions passed: %d\n", n - 467);
}

int main(){
    fizzbuzz_fizz(467, 5467);
    fizzbuzz_all(467, 5467);
    return 0;
}

*/

int main(){
    int r;
    printf("Insira o raio do círculo: ");
    scanf("%d", &r);
    for(int i = 0; i <= 2*r; i++){
        for(int j = 0; j <= 2*r; j++){
            if((i-r)*(i-r) + (j-r)*(j-r) <= r*r){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
