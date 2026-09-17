#include <stdio.h>
#include <stdlib.h>

int main(){
    size_t ca = 0;
    size_t nc = 0;

    printf("Digite a capacidade para o vetor inicial: ");
    if (scanf("%d", &ca) != 1 || ca == 0) {
        printf("Erro!\n");
        return 1;
    }

    int *vetor = (int *) calloc(ca, sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória inicial com calloc!\n");
        return 1;
    }

    printf("Vetor Inicial %d \n", ca);
    for (size_t i = 0; i < ca; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    printf("\nDigite a nova capacidade do vetor: ");
    if (scanf("%d", &nc) != 1 || nc== 0) {
        printf("Nova capacidade inválida!\n");
        free(vetor);
        return 1;
    }

    int *t = (int *) realloc(vetor, nc* sizeof(int));

    if (t == NULL) {
        printf("Erro ao realocar memória! O bloco %d não foi alterado.\n", ca);
        free(vetor); 
        return 1;
    }

    vetor = t;

    if (nc > ca) {
        for (size_t i = ca; i < nc; i++) {
            vetor[i] = 0;
        }
    }

    printf("Capacidade Atualizada\n");
    printf("Capacidade anterior: %d\n", ca);
    printf("Nova capacidade:     %d\n", nc);

    printf("Conteúdo Atualizado do vetor\n");
    for (size_t i = 0; i < nc; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    ca = nc;

    free(vetor);
    vetor = NULL;

    printf("Vetor liberado");

    return 0;

}