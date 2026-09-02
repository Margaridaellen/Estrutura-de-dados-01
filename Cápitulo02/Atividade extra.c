#include<stdio.h>
#include<stdlib.h> 

int main(void){ 
    int n,i;
    printf("Digite um valor:");
    scanf("%d",&n); 
    int * quantidade = (int*) malloc(n*sizeof(*quantidade));

    if(quantidade==NULL){
        printf("Erro");
        exit(1);
    }
    for(int p=0;p<n;p++){
     quantidade[p]=(p+1);
   } 
  
    printf("Digite os valores para o vetor:");
    for (int p=0; p<n;p++){
        scanf("%d", &quantidade[p]);
    }

    for (int p=0; p<n;p++){
    printf("%d ",quantidade[p]);
    }
    free(quantidade);
    quantidade = NULL;

   return 0;



}