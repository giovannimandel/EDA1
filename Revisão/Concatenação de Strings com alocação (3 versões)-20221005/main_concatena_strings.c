#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatena( char *str1, char *str2 );

int main(int argc, char *argv[]) {
	char s1[30] = "Alo ... ";
	char s2[30] = "Mundo  !";
	
	printf("Antes:\n");
	printf("S1 = '%s' e S2 = '%s'\n", s1, s2);
	
	char *s3 = concatena( s1, s2 );
	
	printf("Depois:\n");
	printf("S1 = '%s' e S2 = '%s'\n", s1, s2);
	printf("S3 = '%s'\n", s3);
	
	free( s3 );
			
	return 0;
}

char *concatena( char *str1, char *str2 ){
	int n1 = strlen( str1 );
	int n2 = strlen( str2 );
	
	char *p = malloc( n1 + n2 + 1 );
	
	// v1:
	int i, j = 0;
	for( i = 0 ; str1[i] != '\0' ; i++ ){
		p[j] = str1[i];
		j++;
	}
	for( i = 0 ; str2[i] != '\0' ; i++ ){
		p[j] = str2[i];
		j++;
	}	
	p[j] = '\0';
	
	
	
	// v2:
	// strcpy( p , str1 );
	// strcpy( p + n1 , str2 ); // Aritm�tica de ponteiros!

	
	// v3:
	// p[0] = '\0'; // Deixa string p 'vazia'.
	// strcat( p, str1 );
	// strcat( p, str2 );
	
	return p;
}


