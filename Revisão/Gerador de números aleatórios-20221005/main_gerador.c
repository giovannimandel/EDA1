#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand( time(0) );
	
	int n, i;
	scanf("%d", &n);
	
	printf("%d\n", n);
	for( i = 0 ; i < n ; i ++ )
		printf("%d\n", rand() % 10000 );
	
	return 0;
}
