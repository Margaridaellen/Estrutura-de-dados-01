//---Complexidade---

#include <stdio.h>
void cubo (int n){
    int i,k,j;

    for(i=0; i>2*n ;i++){
        for(j=0; j<3*n ;j++){
            for(k=0; k<4*n; k++){
                printf("%d %d %d",i,j,k);
            }
        }
    }
    
}

void quadrado (int n){
    int i,j;

    for(i=0; i>2*n ;i++){
        for(j=0; j<3*n ;j++){
                printf("%d %d",i,j);
        }
    }
}

void linear(int n){
    int i,j;

    for (i=0; i<2*n; i++){
        for(j=0; j<n; j++){
            printf("");
        }
    }
}

void constante(int n){
    for(int j=0;j<10;j++){
        pritnf("%d\n",j);
    }
}

void logaritimo(n){
    int i;

    for(i=0; i<n; n=n/2){
        printf("%d\n",n);
    }
}

int main(){
    int n;

    printf("Informe o valor de N:");
    scanf("%d",&n);
    printf("Inicio da execução\n");
    quadrado(n);
    printf("Fim da execução");

return 0;
}