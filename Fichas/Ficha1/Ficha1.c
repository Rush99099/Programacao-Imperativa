#include <stdio.h>
#include <stdlib.h>

int ex1(int x){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < x; j++){
            printf("#");
        }
        if (i != x-1){
            printf("\n");
        }
    }
    printf("\n");
}

int ex2(int x){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < x; j++){
            if ((j+i) % 2 == 0){
                printf("#");
            } else {
                printf("_");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int ex3_1(int altura){
    for (int i = 1; i <= altura; i++){
        for (int j = 0; j < i; j++){
            printf("#");
        }
        printf("\n");
    }
    for (int i = 0; i < altura-1; i++){
        for (int j = altura-1; i < j; j--){
            printf("#");
        }
        printf("\n");
    }
}

int ex3_2(int altura){
    int largura = altura * 2 - 1;
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < altura - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("#");
        }
        printf("\n");
    }
}

int ex4(int raio){
    for (int i = -raio; i <= raio; i++){
        for (int j = -raio; j <= raio; j++){
            if (i*i + j*j <= raio*raio){
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
}

int main(){
//    ex1(5);
//    ex2(8);
//    ex3_1(5);
//    ex3_2(5);
    ex4(4);
}
