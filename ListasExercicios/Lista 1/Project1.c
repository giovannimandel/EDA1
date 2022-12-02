/*9) Fa�a um programa que leia uma certa quantidade de inteiros que s�o armazenados num
vetor v. A quantidade deve ser definida pelo usu�rio, e o programa aloca espa�o para v. O
programa deve armazenar os valores positivos em um vetor vp e o valores negativos no
vetor vn. Como as quantidades de valores positivos e negativos s�o desconhecidas, o
espa�o para vp e vn deve ser alocado dinamicamente. Os vetores vp e vn n�o devem
conter zeros. Ao final, imprima os tr�s vetores. Pode ser feito com malloc() ou com
realloc(). */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int *atribui_vetor(int *v, int n, int **vp, int *np,int **vn,int *nn){
    int i;
    *vp = NULL;
    *vn = NULL;
    int neg = 0;
    int pos = 0;
    v = (int*)malloc(sizeof(int)*n);


    for (i = 0; i< n; i++){
        printf("Digite o %io termo do vetor: ", i+1);
        scanf("%i", &v[i]);

        if (v[i] > 0){
            pos++;
            *vp = realloc(*vp, sizeof(int)*(pos));
            (*vp)[pos-1]=v[i];
        }else{
            if (v[i]<0){
                neg++;
                *vn = realloc(*vn, sizeof(int)*(neg));
                (*vn)[neg-1]=v[i];
            }
            
        } 
    }
    *np = pos;
    *nn = neg;
    return v;
} 
void imprime_vetor (int *v, int tamanho){
    int i;

    for (i = 0;i < tamanho; i++){
        printf("%i ",v[i]);
    }
    printf("\n");
}
int main(){
    int *v, *vn,*vp, n, np, nn;

    printf("quantos termos deseja no vetor?");
    scanf("%i", &n);

    v = atribui_vetor(v,n,&vp,&np,&vn,&nn);
    
    printf("vetor original\n");
    imprime_vetor(v, n);
    printf("vetor positivo\n");
    imprime_vetor(vp, np);
    printf("vetor negativo\n");
    imprime_vetor(vn, nn);

    return 0;

}
