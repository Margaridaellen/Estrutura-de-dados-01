#include <stdio.h>
#include <stdlib.h>



struct personagem{
    char nome [30];
    int vida;
    int pontuacao;
    float pos1;
    float pos2;
    int id;
};

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

    struct personagem p1={"João",0, 100, 00, 20.0f, 10.0f};

    printf("Estado inicial do jogador\n");
    printf("ID: %d | Nome: %s | Vida: %d | Pontos: %d | Posição: (%.1f, %.1f)\n\n", p1.id, p1.nome, p1.vida, p1.pontuacao, p1.pos1, p1.pos2);

    p1.pontuacao= p1.pontuacao +20;
    p1.vida=p1.vida-10;
    p1.pos1=p1.pos1+2.0f;
    p1.pos2=p1.pos2+2.0f;

    if(p1.vida<0){
        p1.vida=0;
    }

    printf("Estado alterado do jogador\n");
    printf("ID: %d | Nome: %s | Vida: %d | Pontos: %d | Posição: (%.1f, %.1f)\n",
           p1.id, p1.nome, p1.vida, p1.pontuacao, p1.pos1, p1.pos2);

    return 0;

}