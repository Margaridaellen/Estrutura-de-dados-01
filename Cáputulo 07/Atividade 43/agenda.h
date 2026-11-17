#ifndef AGENDA_H
#define AGENDA_H

#include <stdbool.h>

typedef struct {
    int id;
    char desc[100];
    int prioridade;
} missao;

typedef struct agenda Agenda;

Agenda* agenda_criar(void);
bool agenda_adicionar_inicio(Agenda* agenda, missao nova_missao);

bool agenda_adicionar_fim(Agenda* agenda, missao nova_missao);


void agenda_exibir(const Agenda* agenda);

void agenda_destruir(Agenda* agenda);

#endif 