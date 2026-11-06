#include <stdio.h>
#include <string.h>

int comp=0;
int troca=0;
int desloc=0;

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

//Q32
typedef struct {
    int id;
    char nome[60];
    int pont;
}jogador;

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
    int n[4];
    int n1=4;
    int numCopia[4];

    for(int i = 0; i < 4; i++) n[i] = num[i];

    comp = 0;
    troca = 0;
    deslocamentos = 0;

    ordenacao(n,4);

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

    for(int i = 0; i < 3; i++){
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
    printf("- Deslocamentos: %d\n", desloc);
    return 0;
}