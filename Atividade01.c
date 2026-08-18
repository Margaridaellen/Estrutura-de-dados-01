#include <stdio.h>

int main() {

    int vida;
    int tesouro_ativo;
    
    int *ptr_vida;
    int *ptr_tesouro;

    vida = 100;
    tesouro_ativo = 0;

    ptr_vida = &vida;
    ptr_tesouro = &tesouro_ativo;

    printf("Jogador\n");
    printf("| Vida: %d  \n| Tesouro Ativo: %d\n| Endereço da vida: %p\n", vida, tesouro_ativo, ptr_vida);

    printf("\n| Dano de vida : -10 pontos \n");
 printf("| Vida antes: %d\n", *ptr_vida);
    *ptr_vida = *ptr_vida - 10;
    printf("| Vida atual: %d\n\n", vida);

    printf("Pontos de vida : +5 pontos\n");
    printf("|Vida antes: %d\n", *ptr_vida);
    *ptr_vida = *ptr_vida + 5;
    printf("|Vida atual: %d\n\n", vida);

    printf("TESOURO\n");
    *ptr_tesouro = 1;
    printf("|Tesouro antes: 0 \n|Tesouro depois: %d\n|Endereço do tesouro:%p\n", tesouro_ativo,ptr_tesouro);

    return 0;
}