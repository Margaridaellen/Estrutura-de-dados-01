#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int acesso;
    int comparacao;
}c;

//Q29
int buscalinear(int vetor[],int tamanho,int alvo, int *comparacoes){
    *comparacoes = 0;

    for (int i = 0; i < tamanho; i++) {
        (*comparacoes)++; 
        if (vetor[i] == alvo) {
            return i;
        }
    }
    return-1;
}

//Q28
bool ordenado(int vetor[],int n){
    for(int i=0; i<n-1;i++){
        if(vetor[i]>vetor[i+1]){
            return false;
        }
    }
    return true;
}

int buscabinaria(int vetor[],int n, int alvo, int *comparar){
    int inicio = 0;
    int fim = n-1;
    *comparar =0;

    if(!ordenado(vetor,n)){
        printf("O vetor não está ordenado,erro!\n");
        return -1;
    }

    printf("Realiazando busca [%d]\n",alvo);
    printf("\n%-10s | %-10s | %-10s | %-15s | %-15s|\n", "Inicio", "Meio", "Fim", "vetor[meio]", "Comparacao");

    while(inicio<=fim){
        
        int meio = inicio+(fim-inicio)/2;
        (*comparar)++;

        printf("%-10d | %-10d | %-10d | %-15d | ", inicio, meio, fim, vetor[meio]);

        if (vetor[meio] == alvo) {
            printf("Encontrado!\n");
            return meio; 
        }

        if (vetor[meio] > alvo) {
            printf("%d > %d (Esquerda)\n", vetor[meio], alvo);
            fim = meio - 1;  
        } else { 
            printf("%d < %d (Direita)\n", vetor[meio], alvo);
            inicio = meio + 1;
        }
    }
    printf("Nãocontrado");
    return -1; 
}

void teste(int vetor[],int tamanho,int alvo,const char *c){
    int l=0,b=0;

    //utilizando outras funções do código
    int il=buscalinear(vetor,tamanho,alvo,&l);
    int ib=buscabinaria(vetor,tamanho,alvo,&b);

    printf("| %-15s | %-5d | %-12d | %-12d | %-13d | %-13d |\n",c, alvo,il,l, ib, b);

}


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

    int vetor[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    int comparacoes = 0;
    int resultado;

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
        printf("Fórmulas utilizadas: Comparações= n*(n-1)/2| Razão c/n^2\n\n");

        for (int k=0;k<testes; k++){

            int n = tamanhos[k];
            int *vetor = (int*)malloc(n*sizeof(int));

            for (int l=0; l<n; l++){
                vetor[l]=l+1;       
            }

            int comp = pares(vetor, n, alvo);
            int teorico = (int)n * (n - 1) / 2;
            double razao = (double)comp / ((double)n * n);
            printf("Tamanho: %d| Comparações: %d| Teórico: %d| Razão: %.2f\n\n", n, comp, teorico, razao);
            free(vetor);
        }

        //Q28
        resultado = buscabinaria(vetor, n, 23, &comparacoes);

        if (resultado != -1) {
            printf("Resultado: Valor 23 encontrado na posicao %d com %d comparações.\n", resultado, comparacoes);
        } 
        else {
            printf("Resultado: Valor 23 não encontrado.\n");
        }

        resultado = buscabinaria(vetor, n, 50, &comparacoes);
        
        if (resultado != -1) {
             printf("Resultado: Valor 50 encontrado na posicao %d com %d comparações.\n", resultado, comparacoes);
        } 
        else {
             printf("Resultado: Valor 50 não encontrado no vetor. Total de comparações: %d.\n", comparacoes);
    }

    //Q29
    printf("\nVetor ordenado\n");
    printf( "Cenario ", " Alvo ", " Pos. Linear ", " Comp. Linear ", " Pos. Binaria ", " Comp. Binaria ");

    teste(vetor, n, 2, "\nInicio");
    teste(vetor, n, 16, "\nMeio");
    teste(vetor, n, 91, "\nFim");
    teste(vetor, n, 92, "\nAusente");

    printf("\nVetor deesordenado\n");

    int desordenado[] = {40, 10, 90, 20, 50, 80, 30};
    int td = sizeof(desordenado) / sizeof(desordenado[0]);
    int ad= 20; 

    int complin = 0, compbin = 0;
    int lin = buscalinear(desordenado, td, ad, &complin);
    int bin = buscabinaria(desordenado, td, ad, &compbin);

    printf("Vetor desordenado: {40, 10, 90, 20, 50, 80, 30}\n");
    printf("Buscando o elemento %d (presente no indice 3):\n\n", ad);
    printf("Busca Linear  : Indice retornado = %d | Comparacoes = %d\n", lin, complin);
    printf("Busca Binaria : Indice retornado = %d | Comparacoes = %d \n", bin, compbin);

    return 0;
}