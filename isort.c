//                                    --Insertion sort--
//É um dos algoritmos de ordenação mais simples e intuitivos. Ele funciona da mesma forma que a maioria das pessoas organiza 
//cartas em um jogo de baralho: você pega uma carta por vez e a insere na posição correta em uma mão já ordenada.
//O algoritmo divide o vetor virtualmente em duas partes: uma sublista já ordenada (à esquerda) e uma sublista não ordenada (à direita).
//Começa considerando que o primeiro elemento (índice 0) já está "ordenado".Pega o próximo elemento não ordenado (a "carta da vez").
//Compara esse elemento com os anteriores, movendo os elementos maiores uma posição para a direita.
//Insere o elemento na posição correta na parte ordenada.Repete esse processo até que todos os elementos estejam ordenados.

#include <stdio.h>

int main(){

int n=6;
int v[6] = {3,5,2,8,6,4};

int i,j;
for(i=1;i<1;i++){
    int pivo=v[i];
    for(j=i-1;j>=0 && pivo<v[j]; j--){
        v[j+1]=v[j];
    }
       v[j+1]=pivo;
       printf("%d",pivo);
}
return 0;
}
