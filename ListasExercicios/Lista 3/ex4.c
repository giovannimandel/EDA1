#include <stdio.h>
#include <string.h>
#include "Pilha.h"

int eh_palindrome(char palavra[]){
    Pilha p;
    int tam = strlen(palavra), x, i;
    char palavra2[tam];
    char *point = palavra2;

    inicializa_pilha(&p);
    for(i = 0; i < tam; i++){
        empilha(&p, palavra[i]);
    }
    for(i = 0; i < tam; i++){
        desempilha(&p, &x);
        palavra2[i] = x;
    }

    for(i = 0; i < tam; i++){
        if(palavra[i] == palavra2[i]){
            continue;
        } else { 
            return 0;
        }
    }

    return 1;
    
}

int main(){
    char palavra[13] = "subinoonibus"; // Quando coloca tamanho 12, nao é palindrome, porque? (12 é a quantidade exata de letras na palavra)
    

    if(eh_palindrome(palavra)){
        printf("a palavra eh palindrome\n");
    } else{
        printf("a palavra nao eh palindrome");
    }

}