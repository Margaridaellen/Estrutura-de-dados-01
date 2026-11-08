#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int comp=0;
int troca=0;
int desloc=0;
int passagens;
bool trocou;
int intercalacao=0;

typedef struct {
    int id;
    char nome[60];
    int pont;
    int vida;
}jogador;

//Q40
void trocar0(jogador *a, jogador *b) {
    jogador temp = *a;
    *a = *b;
    *b = temp;
    troca++;
}

int anterior(jogador j1, jogador j2) {
    comp++;
    if (j1.pont != j2.pont)
        return j1.pont > j2.pont;
    return j1.id < j2.id;
}

int particionar(jogador v[], int inicio, int fim) {
    int idx_pivo = inicio + rand() % (fim - inicio + 1);
    trocar0(&v[idx_pivo], &v[fim]);
    jogador pivo = v[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (anterior(v[j], pivo)) {
            i++;
            trocar0(&v[i], &v[j]);
        }
    }
    trocar0(&v[i + 1], &v[fim]);
    return i + 1;
}

void quicksort(jogador v[], int f, int i) {
    if (i < f) {
        int p = particionar(v, i, f);
        quicksort(v, i, p - 1);
        quicksort(v, p + 1, f);
    }
}

void copiar(jogador dest[], jogador orig[], int n) {
    for (int i = 0; i < n; i++) dest[i] = orig[i];
}

//Q39
void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
}
int particionar_auxiliar(int v[], int inicio, int fim) {
    int pivo = v[fim], tam = fim - inicio + 1;
    int *aux = (int *)malloc(tam * sizeof(int));
    int esq = 0, dir = tam - 1;

    for (int k = inicio; k < fim; k++) {
        if (v[k] <= pivo) aux[esq++] = v[k];
        else aux[dir--] = v[k];
    }
    
    aux[esq] = pivo;
    
    for (int i = 0; i < tam; i++) v[inicio + i] = aux[i];
    free(aux);
    
    return inicio + esq;
}

int particionar_inplace(int v[], int inicio, int fim) {
    int pivo = v[fim], i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        comp++;
        if (v[j] <= pivo) {
            i++;
            int temp = v[i]; v[i] = v[j]; v[j] = temp;
            troca++;
        }
    }
    int pos_pivo = i + 1;
    int temp = v[pos_pivo]; v[pos_pivo] = v[fim]; v[fim] = temp;
    troca++;

    return pos_pivo;
}
void quicksortjogador(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int pos_pivo = particionar_inplace(v, inicio, fim);

       quicksortjogador(v, inicio, pos_pivo - 1);
       quicksortjogador(v, pos_pivo + 1, fim);
    }

}


//Q38
void merge(char *v, char *aux, int esq, int meio, int dir, size_t tam, int (*cmp)(const void*, const void*)) {
    int i = esq, j = meio + 1, k = esq;

    while (i <= meio && j <= dir) {
        if (cmp(v + i * tam, v + j * tam) <= 0) {
            memcpy(aux + k * tam, v + i * tam, tam);
            i++;
        } else {
            memcpy(aux + k * tam, v + j * tam, tam);
            j++;
        }
        k++;
    }
    while (i <= meio) {
        memcpy(aux + k * tam, v + i * tam, tam);
        i++; k++;
    }
    while (j <= dir) {
        memcpy(aux + k * tam, v + j * tam, tam);
        j++; k++;
    }
    memcpy(v + esq * tam, aux + esq * tam, (dir - esq + 1) * tam);
}
void mergesortrec(char *v, char *aux, int esq, int dir, size_t tam, int (*cmp)(const void*, const void*)) {
    if (esq >= dir) return;

    int meio = esq + (dir - esq) / 2;

    mergesortrec(v, aux, esq, meio, tam, cmp);
    mergesortrec(v, aux, meio + 1, dir, tam, cmp);
    merge(v, aux, esq, meio, dir, tam, cmp);

}
void merge_sort(void *v, int n, size_t tam, int (*cmp)(const void*, const void*)) {
    if (n <= 1 || v == NULL) return;

    char *aux = (char *)malloc(n * tam);
    if (!aux) return;

    mergesortrec((char *)v, aux, 0, n - 1, tam, cmp);

    free(aux); 
}
int cmp_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int cmp_jogador(const void *a, const void *b) {
    const jogador *j1 = (const jogador *)a;
    const jogador *j2 = (const jogador *)b;

    if (j1->pont != j2->pont) 
        return (j2->pont > j1->pont) ? 1 : -1;
    
    return j1->id - j2->id;
}
//Q37
void intercalar(int v[],int inicio, int meio, int fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int l[n1], r[n2];
    int i1 = 0;      
    int j1 = 0;    
    int k = inicio;

    for (int i = 0; i < n1; i++) l[i] = v[inicio + i];
    for (int j = 0; j < n2; j++) r[j] = v[meio + 1 + j];

    while (i1 < n1 && j1 < n2) {
        intercalacao++;
        if (l[i1] <= r[j1]) {
            v[k] = l[i1];
            i1++;
        } else {
            v[k] = r[j1];
            j1++;
        }
        k++;
    }
    while (i1 < n1) {
        v[k] = l[i1];
        i1++;
        k++;
    }
    while (j1 < n2) {
        v[k] = r[j1];
        j1++;
        k++;
    }
}
void mergesort(int v[], int inicio, int fim){
    if(inicio<fim){
        int meio = inicio + (fim - inicio) / 2;

        mergesort(v, inicio, meio);
        mergesort(v, meio + 1, fim);
        intercalar(v, inicio, meio, fim);
    }
}
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
void bubblesort(const char* cenario, int origem[], int n) {
    int comp_local = 0;
    int passagens_local = 0;
    int troca_local = 0;

    int *v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {
        fprintf(stderr, "Erro de alocação de memória na função bubblesort.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        v[i] = origem[i];
    }

    for (int i = 0; i < n - 1; i++) {
        bool trocou_local = false;
        passagens_local++;

        for (int j = 0; j < n - 1 - i; j++) {
            comp_local++;
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                troca_local++;
                trocou_local = true;
            }
        }
        
        if (!trocou_local) break;
    }

    printf(" %s\n", cenario);
    printf("Passagens:   %d\n", passagens_local);
    printf("Comparacoes: %d\n", comp_local);
    printf("Trocas:      %d\n\n", troca_local);

    free(v);
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
    int v_teste[] = {50,20,30,40};
    int v1[] = {50,20,30,40};
    int t = sizeof(v_teste) / sizeof(v_teste[0]);
    int n[4];
    int n1=4;
    int numCopia[4];
    int x = 4;
    int campo, ordem;
    int nums []= {50,30,20,30,40};
    int n_nums = sizeof(nums) / sizeof(nums[0]);
    int z = sizeof(v1) / sizeof(v1[0]);
    int v2[] = {4, 2, 4, 1, 4, 3, 2, 4};
    int a=5;
    jogador orig[5], copia[5];

    srand(time(NULL));

    comp = 0; troca = 0;

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
    printf("Validacao:   %s\n", ordem ? " Ordenada" : "Erro");

    printf("Vetor original: ");
    imprimirvetor(v_teste, t);

    intercalacao = 0;

    mergesort(v_teste, 0, t - 1);

    printf("\nVetor final intercalado/ordenado: ");
    imprimirvetor(v_teste, t);

    printf("\n| Métricas de intercalação |\n");
    printf("Comparacoes na intercalacao: %d\n", intercalacao);

    merge_sort(nums, n_nums, sizeof(int), cmp_int);
    printf("Inteiros ordenados: ");
    for (int i = 0; i < n_nums; i++) printf("%d ", nums[i]);
    printf("\n");

    jogador equipe[] = {{103, 8.5}, {101, 7.0}, {105, 8.5}, {102, 9.2}};
    int n_turma = sizeof(equipe) / sizeof(equipe[0]);

    merge_sort(equipe, n_turma, sizeof(jogador), cmp_jogador);

    printf("\nJogadores ordenados:\n");
    for (int i = 0; i < n_turma; i++) {
        printf("ID: %d | Pontuação: %.1f\n", equipe[i].id, equipe[i].pont);
    }

    printf("\n| Partição auxiliar |\nOriginal: ");
    imprimir(v1, z);
    int pos_aux = particionar_auxiliar(v1, 0, z - 1);
    printf("Após partição: ");
    imprimir(v1, z);
    printf("Pivô (%d) parou no índice: %d\n\n", v1[pos_aux], pos_aux);
    
    printf("\n| Quick Sort |\nOriginal: ");
    imprimir(v2, z);
    
    quicksortjogador(v2, 0, z - 1);
    
    printf("Ordenado: ");
    imprimir(v2, z);
    printf("Métricas -> Comparações: %d | Trocas: %d\n", comp, troca);
  
    for (int i = 0; i < a; i++) {
        orig[i].id = i + 1;
        orig[i].pont = rand() % 100;
    }

    copiar(copia, orig, a);
    quicksort(copia, 0, a - 1);

    printf("\n| Relatório de metricas|\n");
    printf("Elementos ordenados: %d\n", n);
    printf("Comparações: %lld\n", comp);
    printf("Trocas: %lld\n", troca);

    return 0;
}