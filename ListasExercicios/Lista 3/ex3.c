#include <stdio.h>
#include <string.h>
#include "Pilha.h"

int inverte_string(char string[]){

    Pilha p;
    int i, tam = strlen(string), y, v[5];
    char x, string2[tam];

    inicializa_pilha(&p);

    for(i = 0; *(string+i) != '\0'; i++){
        empilha(&p, string[i]);
    }
    
    for(i = 0; i < tam; i++){
        desempilha(&p, &y);
        string[i] = y; 
    }

    return 1;
}

int main(){
    char string[20] = "giovanni";
    int tam = strlen(string);

    printf("String original:\n");
    for(int i = 0; i < tam; i++){
        printf("%c", *(string+i));
    }
    
    inverte_string(string);
    
    printf("\nString invertida:\n");
    for(int i = 0; i < tam; i++){
        printf("%c", *(string+i));
    }    

    return 0;
}