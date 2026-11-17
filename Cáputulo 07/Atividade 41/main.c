#include <stdio.h>
#include "missao.h"

int main(void) {
    Missao m1 = criar_missao(1, "Configurar ambiente para compilar");
    Missao m2 = criar_missao(2, "Modularizar o codigo da agenda");

    printf("| Estado Inicial |\n");
    exibir_missao(&m1);
    exibir_missao(&m2);

    concluir_missao(&m1);

    printf("\n| Estado atualizada com sucesso! |\n");
    exibir_missao(&m1);
    exibir_missao(&m2);

    return 0;
}