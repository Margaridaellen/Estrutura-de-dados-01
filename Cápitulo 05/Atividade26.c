#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int acesso;
    int comparacao;
}c;

int acesso(int vetor[], int tam, int indice, c *co){
   
    co->comparacao++;
    if(indice<0){
        printf("Erro, o indíce negativo (%d) não é valido",indice);
        return -1;
    }

    co->comparacao++;  
    if(indice>=tam){
        printf("Erro: Indice (%d) fora dos limites estabelecido para o vetor [%d]",indice,tam);
        return -1;
    }

    co->acesso++;
    return vetor[indice];
}

int maior(int vetor[],int tam,c *co){
    if(tam<=0) return -1;
    
    co->acesso++;
    int Maior=vetor[0];
    for(int i=0; i<tam;i++){
        co->acesso++;
        co->comparacao++;
        if(vetor[i]>Maior){
        Maior=vetor[i];
        }
    }
    return Maior;
}

int main() {
    int tamanhos[] = {10, 20, 30};
    int testes = 3;

    for (int t = 0; t < testes; t++) {
         int n = tamanhos[t];
         int *v = (int *)malloc(n * sizeof(int));
       
          for (int i = 0; i < n; i++) {
            v[i] = i; 
          }

        c cnt_direto = {0, 0};
        c cnt_maior = {0, 0};

        int iteste = n / 2;
        acesso(v, n, iteste, &cnt_direto);

        maior(v, n, &cnt_maior);

        printf("|Tamanho do vetor %d|\n", n);
        printf("Acesso Direto - O(1)  -> Acessos: %d \nComparações: %d \nTotal: %d\n", cnt_direto.acesso, cnt_direto.comparacao, cnt_direto.acesso + cnt_direto.comparacao);
        printf("Busca do Maior - O(n) -> Acessos: %d \nComparações: %d \nTotal: %d\n\n",cnt_maior.acesso, cnt_maior.comparacao, cnt_maior.acesso + cnt_maior.comparacao);

        free(v);
    }

    return 0;
}