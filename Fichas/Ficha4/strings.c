#include <stdio.h>
int contaVogais (char *s) {
    int cont = 0;
    int i = 0;
    while (s[i] != '\0'){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            cont++;
        }
        i++;
    }
    return cont;
}

int isVogal (char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return 1;
    }
    return 0;
}

int retiraVogaisRep(char *s) {
    char *aux = s;
    int i = 0, j = 0, removidas = 0;
    char prev = '\0';

    while (s[i] != '\0') {
        if (isVogal(s[i]) && s[i] == prev) {
            removidas++;
        } else {
            aux[j++] = s[i];
        }
        prev = isVogal(s[i]) ? s[i] : '\0';
        i++;
    }
    aux[j] = '\0';

    i = 0;
    while ((s[i] = aux[i]) != '\0') i++;

    return removidas;
}

int retiraVogaisRepSemAux(char *s) {
    int i = 0, j = 0, removidas = 0;
    char prev = '\0';

    while (s[i] != '\0') {
        if (isVogal(s[i]) && s[i] == prev) {
            removidas++;
        } else {
            s[j++] = s[i];
        }
        prev = isVogal(s[i]) ? s[i] : '\0';
        i++;
    }
    s[j] = '\0';
    return removidas;
}

int duplicaVogais (char *s){
    char aux[1000];
    int i = 0;
    int j = 0;
    int cont = 0;
    while (s[i] != '\0'){
        aux[j++] = s[i];
        if (isVogal(s[i])){
            aux[j++] = s[i];
            cont++;
        }
        i++;
    }
    aux[j] = '\0';
    while ((s[i] = aux[i]) != '\0') i++;
    return cont;
}

int duplicaVogaisSemAux(char *s){
    int len = 0, i, j, cont = 0;
    // 1º: calcular o comprimento da string
    while (s[len] != '\0') len++;

    // 2º: percorrer de trás para a frente, duplicando as vogais
    i = len - 1;
    j = len - 1;
    // Primeiro, calcular o novo tamanho
    while (i >= 0) {
        if (isVogal(s[i])) {
            j++; // espaço para duplicar
        }
        i--;
    }
    // Atualizar o fim da string
    s[j+1] = '\0';

    // Agora, duplicar de trás para a frente
    i = len - 1;
    while (i >= 0) {
        s[j] = s[i];
        if (isVogal(s[i])) {
            j--;
            s[j] = s[i];
            cont++;
        }
        i--;
        j--;
    }
    return cont;
}

int main(){
    char s1 [100] = "Estaa e umaa string coom duuuplicadoos";
    int x;
    
    printf ("Testes\n");
//    printf ("A string \"%s\" tem %d vogais\n", s1, contaVogais (s1));
//    
//    x = retiraVogaisRep (s1);
//    printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);
//    
    x = duplicaVogaisSemAux (s1);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s1);
    
    printf ("\nFim dos testes\n");

    return 0;
}