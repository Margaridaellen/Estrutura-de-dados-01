#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int acesso;
    int comparacao;
}c;


//Q31
int contador_fib = 0;
int contador_busca = 0;

int fibonacci_ingenuo(int n) {
    contador_fib++;
    
    //Caso-base: Condição de parada usada para impedir a função recursiva de entrar em um loop infinito
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return fibonacci_ingenuo(n - 1) + fibonacci_ingenuo(n - 2);
}

//Busca binária recursiva: Implementada através de chamadas de função encadeadas passando os novos limites
int busca_binaria_recursiva(int vetor[], int inicio, int fim, int chave) {
    contador_busca++;
    
    if (inicio > fim) {
        return -1;  }
    
    int meio = inicio + (fim - inicio) / 2;
    
    if (vetor[meio] == chave) {
        return meio;  }
    
    if (chave < vetor[meio]) {
        return busca_binaria_recursiva(vetor, inicio, meio - 1, chave);
    } 
    else {
        return busca_binaria_recursiva(vetor, meio + 1, fim, chave);
    }
}

void executar_fibonacci() {
    int n;
    printf("\nFibonnaci Ingênuo\n");
    printf("Digite um valor para N (limite recomendado de 0 a 30): ");
    scanf("%d", &n);
    
    if (n < 0 || n > 35) {
        printf("Entrada inválida! O valor deve estar entre 0 e 35 para evitar estouro da pilha de execução.\n");
        return;
    }
    
    contador_fib = 0; 
    int resultado = fibonacci_ingenuo(n);
    
    printf("Fibonacci(%d) = %d\n", n, resultado);
    printf("Total de chamadas recursivas executadas: %d\n", contador_fib);
}

void executar_busca_binaria() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int chave;
    
    printf("\nBusca Binária Recursivan");
    printf("Vetor disponível: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d%s", arr[i], (i == tamanho - 1) ? "" : ", ");
    }
    printf("]\n");
    
    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &chave);
    
    contador_busca = 0; 
    int posicao = busca_binaria_recursiva(arr, 0, tamanho - 1, chave);
    
    if (posicao != -1) {
        printf("Elemento %d encontrado na posição (índice): %d\n", chave, posicao);
    } else {
        printf("Elemento %d NÃO foi encontrado no vetor (retorno: -1).\n", chave);
    }
    printf("Total de chamadas recursivas executadas: %d\n", contador_busca);
}

//Q30
int fatorial (int n, int*c){
    (*c)++;

    if (n<=1){
        return 1;
    }

    return n * fatorial (n-1,c);
}

int fatorialiterativo(int n, int*iteracoes){
    *iteracoes = 0;
    int resultado=1;

    for(int i=1;i<=n;i++){
        (*iteracoes)++;
        resultado *=i;
    }

    return resultado;
}

int somarecursiva(int vetor[],int tamanho,int indice,int *c){
    (*c)++;

    if(indice>=tamanho){
        return 0;
    }

    return vetor[indice]+somarecursiva(vetor,tamanho,indice+1,c);

}

int somaiterativa(int vetor[], int tamanho, int *iteracoes) {
    *iteracoes = 0;
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        (*iteracoes)++; 
        soma += vetor[i];
    }

    return soma;
}

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

//Busca binária iterativa:Inclui verificação de ordenação do vetor com ordenado() 
//imprime o rastreio visual do intervalo de busca a cada iteração.
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

//A função recebe um vetor e chama busca linear e busca binaria para o mesmo alvo, comparando indíces e retornando quantidade de comparações
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

//Contadores de custo: Foi usado para medir o custo de tempo e execução
//com os campos acesso e comparacao.
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

    int fatorial(int n, int *chamadas);
    int fatorialiterativo(int n, int *iteracoes);
    int somarecursiva(int vetor[], int tamanho, int indice, int *chamadas);
    int somaiterativa(int vetor[], int tamanho, int *iteracoes);

    int n1 = 5;
    int chamadasfat = 0;
    int iteracoesfat = 0;

    int fr = fatorial(n, &chamadasfat);
    int fi = fatorialiterativo(n, &iteracoesfat);

    int opcao;

    for (int t = 0; t < testes; t++) {
         int natual = tamanhos[t];
         int *v = (int *)malloc(n * sizeof(int));
       
          for (int i = 0; i < n; i++) {
            v[i] = i; 
          }

        c cnt_direto = {0, 0};
        c cnt_maior = {0, 0};

        int iteste = n / 2;

        //O(1): Custo constante
        acesso(v, n, iteste, &cnt_direto);

        //O(n):Pecorre todo o vetor com custo linear
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

            //O(n^2):  código imprime no console a fórmula da soma aritmética n(n-1)/2 e calcula a razão entre as comparações reais 
            //demonstrando experimentalmente o comportamento 
            int comp = pares(vetor, n, alvo);
            int teorico = (int)n * (n - 1) / 2;
            double razao = (double)comp / ((double)n * n);
            printf("Tamanho: %d| Comparações: %d| Teórico: %d| Razão: %.2f\n\n", n, comp, teorico, razao);
            free(vetor);
        }

        //Q28
        // O(log n): Na busca binária,ocorre a redução de espaço de busca pela metade
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

    printf("\nFatorial de N\n");

    printf("|Calculando Fatorial de %d:\n", n);
    printf("Recursivo : Resultado = %lld | Chamadas  = %d\n", fr, chamadasfat);
    printf("Iterativo : Resultado = %lld | Iteracoes = %d\n\n", fi,iteracoesfat);

    printf("\n|Soma dos Elementos\n");

    int chamadas_soma = 0;
    int iteracoes_soma = 0;
    int somarec = somarecursiva(vetor, n, 0, &chamadas_soma); // Passa 'n' (10)
    int somaite = somaiterativa(vetor, n, &iteracoes_soma);
    printf("Vetor (Tamanho = %d)\n", n);

    printf("Vetor: {12, 5, 8, 20, 15, 30} (Tamanho = %d)\n", tamanhos);
    printf("Recursivo : Resultado = %d | Chamadas  = %d\n", somarec, chamadas_soma);
    printf("Iterativo : Resultado = %d | Iteracoes = %d\n\n",somaite, iteracoes_soma);

    do{
        printf("\n |Menu recursivo|  \n");
        printf("1. Fibonacci Ingênuo (Ramificado)\n");
        printf("2. Busca Binária Recursiva\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                executar_fibonacci();
                break;
            case 2:
                executar_busca_binaria();
                break;
            case 3:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}