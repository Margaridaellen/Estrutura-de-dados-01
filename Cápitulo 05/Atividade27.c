#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int acesso;
    int comparacao;
}c;


//Q27
int pares(int vetor[],int n, int alvo){
    int comparacao=0;

    for (int i=0; i<n-1; i++){
        for (int j=i+1;j<n; j++){
            comparacao++;

            if (vetor[i]+vetor[j]==alvo){

            }
        }
    }
    return comparacao;
}

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
    int alvo = 50;

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

     //Q27
        printf("|Dados|\n");
        printf("Fórmulas utilizadas: Comparações= n*(n-1)/2| Razão c/n^2\n");

        for (int k=0;k<testes; k++){

            int n = tamanhos[k];
            int *vetor = (int*)malloc(n*sizeof(int));

            for (int l=0; l<n; l++){
                vetor[l]=l+1;       
            }

            int comp = pares(vetor, n, alvo);
            int teorico = (int)n * (n - 1) / 2;
            double razao = (double)comp / ((double)n * n);
            printf("Tamanho: %d| Comparações: %d| Teórico: %d| Razão: %.2f\n", n, comp, teorico, razao);
            free(vetor);
        }

    return 0;
}