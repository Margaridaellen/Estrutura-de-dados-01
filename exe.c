#include <stdio.h>
int buscabinaria(int vetor[], int inicio, int fim, int busca){
    while(inicio<=fim){
        int total = (inicio+fim)/2;
        if(vetor[total]==busca){
            return total; 
        }
        else if(busca<vetor[total]){
            fim= total - 1;
        }
        else{
          
            inicio= total + 1;
        }
    } 
    return -1;
}

int main(){
    int vetor[5]={1,3,5,7,9};
    int r= buscabinaria(vetor,0,4,9);
    printf("Elemento encontrado no índice: %d\n", r);
    return 0;
}