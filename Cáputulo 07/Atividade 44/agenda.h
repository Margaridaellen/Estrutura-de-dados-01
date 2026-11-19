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
bool agenda_adicionar_fim(Agenda* agenda, Missao nova_missao);

//Q44
bool agenda_buscar(const Agenda* agenda, int id, Missao* resultado);
bool agenda_adicionar_apos(Agenda* agenda, int id_referencia, Missao nova_missao);

void agenda_exibir(const Agenda* agenda);
void agenda_destruir(Agenda* agenda);

#endif