#include <stdio.h>
#include "Pilha.h"
#include <string.h>

void inverte_palavras_frase(char string[]){
    
    int tam = strlen(string), palavras = 1, l = 0, k = 0, x, j = 0;
    char string2[50] = {}, string3[50] = {};
    Pilha p;
    
    inicializa_pilha(&p);

    for(int i = 0; i < tam; i++){
        if(string[i] == ' '){
            palavras++;
        }
    }

    while(l < palavras){
        for(int i = k; (string[i] != ' ') && (string[i] != '\0'); i++){
            empilha(&p, string[i]);
            //printf("empilhou %c\n", string[i]);
            k++;
            j++;
        }
        for(int i = 0; i < j; i++){
            desempilha(&p, &x);
            //printf("desempilhou %c\n", x);
            string2[i] = x;
            //printf("string2 = %s\n", string2);
        }
        strcat(string3, string2);
        strcat(string3, " ");
        memset(string2,0,strlen(string2)); // zera a string2
        j = 0;
        k++;
        l++;
    }
    strcpy(string, string3);

}

int main(){

    char string[50] = "AMU MEGASNEM ATERCES";
    int tam = strlen(string);
    
    printf("Frase antes: %s\n", string);
    inverte_palavras_frase(string);

    printf("Frase depois: %s\n", string);

    return 0;
}