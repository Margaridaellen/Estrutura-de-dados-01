#include <stdio.h>
int comparacoes = 0;
int trocas = 0;

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    trocas++;
}

int particao_auxiliar(int arr[], int baixo, int alto) {
    int tamanho = alto - baixo + 1;
    int temp[tamanho];
    int pivo = arr[alto];
    int pos = 0;

    // Guarda os menoresvalores do pivô
    for (int i = baixo; i < alto; i++) {
        comparacoes++;
        if (arr[i] < pivo) temp[pos++] = arr[i];
    }

    int pos_pivo = baixo + pos; 
    temp[pos++] = pivo;         // Posiciona o pivô

    for (int i = baixo; i < alto; i++) {
        comparacoes++;
        if (arr[i] >= pivo) temp[pos++] = arr[i];
    }

    for (int i = 0; i < tamanho; i++) {
        arr[baixo + i] = temp[i];
        trocas++;
    }
    return pos_pivo;
}

// In-place
int particao_inplace(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = baixo; 

    for (int j = baixo; j < alto; j++) {
        comparacoes++;
        if (arr[j] <= pivo) { 
            trocar(&arr[i], &arr[j]);
            i++;
        }
    }
    trocar(&arr[i], &arr[alto]); 
    return i; // Devolve a posição final do pivô
}

// Quick Sort Recursivo
void quick_sort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pos_pivo = particao_inplace(arr, baixo, alto);
        
        quick_sort(arr, baixo, pos_pivo - 1);
        quick_sort(arr, pos_pivo + 1, alto);
    }
}

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int vetor[] = {8, 3, 5, 2, 5, 9, 5, 1}; 
    int n = 8;

    printf("Original: ");
    imprimir(vetor, n);

    quick_sort(vetor, 0, n - 1);

    printf("Ordenado: ");
    imprimir(vetor, n);
    
    printf("Comparacoes: %d | Trocas: %d\n", comparacoes, trocas);

    return 0;
}