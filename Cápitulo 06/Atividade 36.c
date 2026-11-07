#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int comp=0;
int troca=0;
int desloc=0;
int passagens;
bool trocou;

typedef struct {
    int id;
    char nome[60];
    int pont;
    int vida;
}jogador;

//Q36
bool trocar(jogador a, jogador b, int campo, int ordem){
    int valora = (campo == 1) ? a.vida : a.id;
    int valorb = (campo == 1) ? b.vida : b.id;

    if (ordem == 1) {
        return valora > valorb;
    } else {
        return valora < valorb; 
    }
}

//Q35
void bubblesort(const char* cenario, int origem[],int n){
    
    int comp=0;
    int passagens;
    int troca=0;

    int v[10];
    for (int i = 0; i < n; i++) {
        v[i] = origem[i];
    }

    for (int i = 0; i < n - 1; i++) {
        trocou = false;
        passagens++;

        for (int j = 0; j < n - 1 - i; j++) {
        comp++;
          if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                troca++;
                trocou = true;
      }
    }
    printf(" %s\n",cenario);
    printf("Passagens:   %d\n", passagens);
    printf("Comparacoes: %d\n", comp);
    printf("Trocas:      %d\n\n", troca);
}
}
//Q33
int deslocamentos = 0;

void inserirprefixo(int v[], int i) {
    int chave = v[i];
    int j = i - 1;
    while (j >= 0) {
        comp++;
        if (v[j] > chave) {
            v[j + 1] = v[j];
            deslocamentos++;
            j--;
        } else {
            break;
        }
    }
    v[j + 1] = chave;
}

void insertionSort(int vetor[], int n) {
    for (int i = 1; i < n; i++) {
        inserirprefixo(vetor, i);
    }
}

void imprimirvetor(int vetor[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int validarordenacao(int v[],int n){
    for (int i=0; i <n-1; i++){
        if (v[i]>v[i+1]){
            return 0;
        }
    }
    return 1;
}

int menor(int vetor [], int inicio, int n ){
    int menorindice=inicio;
    for(int i=inicio+1; i<n;i++){
        comp++;
        if (vetor[i]<vetor[menorindice]){
            menorindice=i;
        }
    }
    return menorindice;
}

//selection sort
void ordenacao(int vetor[], int n){
    for(int i=0; i<n-1;i++){
        int m=menor(vetor,i,n);
        if (m != i){
            int temp= vetor [i]; 
            vetor[i]=vetor[m];
            vetor[m]=temp;
            troca++;
        }
    }
}

int vencedor (jogador a, jogador b){
    comp++;
    if (a.pont != b.pont) return a.pont > b.pont;

    comp ++;
    int c= strcmp(a.nome, b.nome);
    if(c!=0) return c<0;

    comp++;
    return a.id< b.id;
}

int melhor(jogador v[], int inicio, int n){
    int m= inicio;
    for(int i= inicio +1; i <n; i++){
        if (vencedor(v[i], v[m])) m=i;
    }
    return m;
}

void ordenarjogadores(jogador v[], int n){
    for (int i = 0; i < n - 1; i++) {
        int m= melhor(v,i,n);
        if (m!=i){
            jogador temp = v[i]; v[i] = v[m]; v[m] = temp;
            troca++;
        }
    }
}


//Q34
int alfabeto (jogador a , jogador b){
    comp++;
    int r= strcmp (a.nome,b.nome);
    if (r != 0){
        return r<0;
    }

    comp++;
    if (a.pont != b.pont) {
        return a.pont > b.pont;
    }

    comp++;
    if (a.id != b.id) {
        return a.id < b.id;
    }
    return 0;
}

void jogadornome(jogador v[], int n){
    for( int i=1; i<n; i++){
        jogador chave= v[i];
        int j = i - 1;

        while (j >= 0 && alfabeto(chave, v[j])) {
            v[j + 1] = v[j];
            desloc++;
            j--;

        }
        v[j + 1] = chave;
    }
}

void imprimirjogadores (jogador v[], int n){
    printf("Id | Nome  |  Pontuação\n");
    for (int i = 0; i < n; i++) {
        printf("%-2d | %-8s | %d\n", v[i].id, v[i].nome, v[i].pont);
    }
}

int main (){
    int num []= {50,20,30,40};
    int v_inverso[]= {50,40,30,20};
    int v_aleatorio[]= {50,20,30,40};
    int v_ordenado[]= {20,30,40,50};
    int n[4];
    int n1=4;
    int numCopia[4];
    int x = 4;
    int campo, ordem;

    for(int i = 0; i < 4; i++) n[i] = num[i];

    comp = 0;
    troca = 0;
    deslocamentos = 0;

    ordenacao(n,4);

    jogador time[] = {
        {105, "Heroi",100, 85},
        {108, "Mago",90, 95},
        {102, "Curandeiro",80, 120},
        {104, "Vilao",110, 60}
    };

    int n_time = 4;

    printf("|Números ordenados|\n");
    for(int i = 0; i < 4; i++){
        printf("%d ", n[i]);
    }
    printf("\nComparações: %d  - Trocas %d \n",comp,troca);

    jogador jogoriginais[]={
        {1, "Carlos", 100},
        {2, "Maria", 150},
        {3, "Ana", 200},
        {4, "Ana", 210}
    };
    jogador jogCopia[4];

    for(int i = 0; i < 4; i++){
        jogCopia[i] = jogoriginais [i];
    }

    comp=0; troca=0; 
    ordenarjogadores(jogCopia,4);

    printf("| Jogadores ordenados |\n");
    for (int i = 0; i < 3; i++) {
        printf("Id: %d | Nome: %s | Pontos: %d\n", jogCopia[i].id, jogCopia[i].nome, jogCopia[i].pont);
    }
    printf("Comparações: %d | Trocas: %d\n", comp, troca);

    for (int i = 0; i < n1; i++) {
        numCopia[i] = num[i];
    }

    printf("\nVetor original: ");
    imprimirvetor(num,n1);

    insertionSort(numCopia, n1);

    printf("\nVetor ordenado:\n  ");
    imprimirvetor(numCopia,n1);

    printf("\n| Métricas: |\n");
    printf("Comparações:  %d\n", comp);
    printf("Deslocamentos: %d\n", deslocamentos);

    if (validarordenacao(numCopia, n1)) {
        printf("Validação: Bem sucedida\n");
    } else {
        printf("Validação: Erro, o vetor não foi ordenado corretamente\n");
    }

    for (int i = 0; i < n1; i++) {
        jogCopia[i] = jogoriginais[i];
    }

    printf("\n|Registradore originais - Antes\n");
    imprimirjogadores(jogoriginais, n1);

    jogadornome(jogCopia, n1);

    printf("\n Rgeistradores originais - Depois\n");
    imprimirjogadores(jogCopia, n1);

    printf("Métricas do Insertion Sort:\n");
    printf("- Comparações:  %d\n", comp);
    printf("- Deslocamentos: %d\n\n", desloc);

    bubblesort("Vetor Ordenado", v_ordenado, x);
    bubblesort("Vetor Inverso", v_inverso, x);
    bubblesort("Vetor Aleatorio", v_aleatorio, x);

    printf("Campo (1-Vida, 2-ID): ");
    scanf("%d", &campo);
    printf("Ordem (1-Crescente, 2-Decrescente): ");
    scanf("%d", &ordem);

    printf("\n--- Ordenando por %s (%s) ---\n", 
           (campo == 1) ? "Vida" : "ID", 
           (ordem == 1) ? "Crescente" : "Decrescente");
    
    for (int i = 0; i <n_time  - 1; i++) {
        bool houveTroca = false;

        for (int j = 0; j < n_time - 1 - i; j++) {
            comp++;

            if (trocar(time[j], time[j + 1], campo, ordem)) {
                jogador temp = time[j];
                time[j] = time[j + 1];
                time[j + 1] = temp;

                troca++;
                troca= true; 
            }
        }
      if (troca) break;  
    }

    printf("\nID\tNome\t\tVida\n");
    printf("-----------------------------\n");
    for (int i = 0; i < n_time; i++) {
        printf("%d\t%-12s\t%d\n", time[i].id, time[i].nome, time[i].vida);
    }

    printf("\n | Métricas |\n");
    printf("Comparacoes: %d\n", comp);
    printf("Trocas:      %d\n", troca);
    printf("Validacao:   %s\n", ordem ? "OK (Ordenado)" : "ERRO");

    return 0;
}