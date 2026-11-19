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

//Q45
bool agenda_adicionar_antes(Agenda* agenda, int id_referencia, Missao nova_missao);
bool agenda_remover_inicio(Agenda* agenda, Missao* removida);

//Q46
bool agenda_remover_fim(Agenda* agenda, Missao* removida);
bool agenda_remover_por_id(Agenda* agenda, int id, Missao* removida);

//Q47
bool agenda_remover_apos(Agenda* agenda, int id_referencia, Missao* removida);
bool agenda_remover_antes(Agenda* agenda, int id_referencia, Missao* removida);

void agenda_exibir(const Agenda* agenda);
void agenda_destruir(Agenda* agenda);

#endif