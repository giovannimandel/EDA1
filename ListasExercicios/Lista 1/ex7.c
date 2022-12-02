#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repetidor( char *s, int n );

int main(){

    char s[3] = "Abc";
    
    printf("%s\n", repetidor(s, 3));

    return 0;
}

char *repetidor( char *s, int n ){
    char *s2;
    s2 = (char*)malloc(sizeof(char) * n);
    int alocar = 0;
    for(int i = 0; i < n; i++){
        //strncat(s2, s, 4);
        for(int i2 = 0; i2 < strlen(s); i2++)
        {
            s2[alocar] = s[i2];
            alocar++;
        }
    }
    return s2;
}