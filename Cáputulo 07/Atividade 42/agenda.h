#ifndef AGENDA_H
#define AGENDA_H

#include <stdbool.h>

typedef struct {
    int id;
    char descricao[100];
    int prioridade;
} Missao;

typedef struct agenda Agenda;

Agenda* agenda_criar(void);

bool agenda_adicionar_inicio(Agenda* agenda, Missao nova_missao);

void agenda_destruir(Agenda* agenda);

#endif 
