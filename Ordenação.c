// ---Quick Sort---
//O Quick Sort é um dos algoritmos de ordenação mais eficientes e utilizados na computação. Ele utiliza a estratégia de Divisão e Conquista
//Escolha do Pivô: Seleciona-se um elemento do array para ser o "pivô" (Noramlmente o último elemento).
//Todos os elementos menores que o pivô fiquem à sua esquerda.
//Todos os elementos maiores que o pivô fiquem à sua direita.

#include <stdio.h>
int particao(int v[], int left, int right){
    int pivo= v[right];
    int j=0,i;
    for(i=left;i<right-1;i++){
        if (v[i]<pivo){
            int temp=v[j];
            v[j]=v[i];
            v[i]=temp;
            j++;
        }
    }
    int temp =v[j];
    v[i]=temp;

}

int quicksort( int v[],int left, int right){
    if(left<right){
        int index = particao (v,left,right);
        quicksort(v,left, index-1);
        quicksort(v, index+1, right);
        

    }
}

int main(){
    int v[6]={5,3,9,4,10,67};
    particao(v,0,5);

    return 0;
}