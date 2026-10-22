#include <stdio.h>

// 1. Definição do Enum com typedef para facilitar a declaração
typedef enum {
    SEGUNDA = 1, // Definimos o início em 1 (terça será 2, quarta 3, etc.)
    TERCA,       // 2
    QUARTA,      // 3
    QUINTA,      // 4
    SEXTA,       // 5
    SABADO,      // 6
    DOMINGO      // 7
} DiaDaSemana;

// Função que recebe o Enum como parâmetro
void verificar_dia(DiaDaSemana dia) {
    switch (dia) {
        case SEXTA:
            printf("Sextou! Fim de semana chegando.\n");
            break;
        case SABADO:
        case DOMINGO:
            printf("Fim de semana! Hora de descansar.\n");
            break;
        default:
            printf("Dia útil de trabalho ou estudo.\n");
            break;
    }
}

int main() {
    // 2. Declarando uma variável do tipo Enum
    DiaDaSemana hoje = SEXTA;

    // 3. Imprimindo a mensagem com base no Enum
    verificar_dia(hoje);

    // 4. Por baixo dos panos, o Enum em C é apenas um valor inteiro!
    printf("O valor numerico atribuido a SEXTA eh: %d\n", hoje);

    // É possível fazer comparações diretas ou operações matemáticas simples:
    if (hoje > QUINTA) {
        printf("Ja passou de quinta-feira!\n");
    }

    return 0;
}