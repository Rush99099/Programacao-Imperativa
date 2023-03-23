
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
3.3.
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

*/
 
int main(){
    int a;
    int x = 0;
    printf("Insira a altura do triangulo: ");
    scanf("%d", &a);
    int cont = a-1;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < cont; j++){
            putchar(' ');
        }
        for (int l = 0; l < (a-cont); l++){
            putchar('#');
        }
        for (int k = 0; k < (a-cont); k++){
            putchar('#');
        }
        for (int m = 0; m < cont; m++){
            putchar(' ');
        }
        cont--;
        putchar('\n');
    }
    

    return 0;
}