#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main(void) {
    Agenda* minha_agenda = agenda_criar();
    if (minha_agenda == NULL) {
        printf("Erro critico: falha ao inicializar a agenda.\n");
        return 1;
    }

    Missao m1;
    m1.id = 101;
    strcpy(m1.descricao, "Revisar encapsulamento em C");
    m1.prioridade = 1;

    Missao m2 = {102, "Implementar remocao de nos", 2};

    if (agenda_adicionar_inicio(minha_agenda, m1)) {
        printf("Missao %d adicionada com sucesso.\n", m1.id);
    }

    if (agenda_adicionar_inicio(minha_agenda, m2)) {
        printf("Missao %d adicionada no inicio.\n", m2.id);
    }

    agenda_destruir(minha_agenda);
    return 0;
}