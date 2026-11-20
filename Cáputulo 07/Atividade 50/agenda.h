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
bool agenda_buscar(const Agenda* agenda, int id, Missao* resultado);
bool agenda_adicionar_apos(Agenda* agenda, int id_referencia, Missao nova_missao);
bool agenda_adicionar_antes(Agenda* agenda, int id_referencia, Missao nova_missao);

bool agenda_remover_inicio(Agenda* agenda, Missao* removida);
bool agenda_remover_fim(Agenda* agenda, Missao* removida);
bool agenda_remover_por_id(Agenda* agenda, int id, Missao* removida);
bool agenda_remover_apos(Agenda* agenda, int id_referencia, Missao* removida);
bool agenda_remover_antes(Agenda* agenda, int id_referencia, Missao* removida);

bool agenda_alterar(Agenda* agenda, int id, Missao novos_dados);
void agenda_limpar(Agenda* agenda);
void agenda_exibir(const Agenda* agenda);
void agenda_destruir(Agenda* agenda);

int agenda_contar(const Agenda* agenda);
int agenda_importar_lote(Agenda* agenda, const Missao* lote, int quantidade);

void agenda_ordenar(Agenda* agenda);
bool agenda_salvar(const Agenda* agenda, const char* nome_arquivo);

#endif