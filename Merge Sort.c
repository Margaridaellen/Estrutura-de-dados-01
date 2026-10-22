//---Merge Sort---
//O Merge Sort é um algoritmo de ordenação altamente eficiente que funciona com base no princípio de "divisão e conquista" (divide and conquer).
// Ele divide um array em partes menores, ordena cada parte individualmente e depois as combina de volta para formar o array ordenado final.
//->Divisão: O array original é dividido pela metade repetidamente de forma recursiva, 
//até que cada sub-array contenha apenas um único elemento (um array de um elemento é considerado ordenado).
//->Conquista: O algoritmo começa a juntar (merge) os sub-arrays adjacentes.
//Combinação: Durante a junção, os elementos são comparados e colocados na ordem correta,
//criando sub-arrays ordenados cada vez maiores, até que o array inteiro seja reconstruído e ordenado.

#include <stdio.h>
void merge (int v1[], int v2[], int r[], int n1, int n2){
    int i=0,j=0,k=0;
    while (i<n1 && j<n2){
        if(v1[i]<v2[j]){
            r[k]=v1[i];
            i++;
        }
        else{
            r[k]=v2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        r[k]=v1[i];
        i++;
        k++;
    }

    while (j<n2){
        r[k]=v2[j];
        j++;
        k++;
    }
}

int main(){
    int v1[5]={1,5,7,11,15};
    int v2[4]={2,4,6,8};
    int r[9];

    merge(v1,v2,r,5,4);

    printf ("Vetores orginais ordenados: \n");

    printf("Vetor 01:");
    for(int k=0;k<5;k++){
        printf("[%d]",v1[k]);
    }

    printf("\nVetor 02:");
    for(int j=0;j<4;j++){
        printf("[%d]",v2[j]);
    }

    printf("\nJunção dos vetores ordenados - Merge Sort\n");
    for(int i=0;i<9;i++){
        printf("[%d]",r[i]);
    }
}