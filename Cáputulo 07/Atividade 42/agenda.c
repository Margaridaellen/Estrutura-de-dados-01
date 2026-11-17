#include "agenda.h"
#include <stdlib.h>
#include <string.h>

typedef struct no {
    Missao dado;
    struct no* proximo;
} No;

struct agenda {
    No* inicio;
};

Agenda* agenda_criar(void) {
    Agenda* nova_agenda = (Agenda*) malloc(sizeof(Agenda));
    
    if (nova_agenda != NULL) {
        nova_agenda->inicio = NULL; 
    }
    
    return nova_agenda;
}

bool agenda_adicionar_inicio(Agenda* agenda, Missao nova_missao) {
    if (agenda == NULL) {
        return false;
    }

    No* novo_no = (No*) malloc(sizeof(No));
    
    if (novo_no == NULL) {
        return false;
    }

    novo_no->dado = nova_missao;

    novo_no->proximo = agenda->inicio;

    agenda->inicio = novo_no;

    return true;
}

void agenda_destruir(Agenda* agenda) {
    if (agenda == NULL) return;

    No* atual = agenda->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    
    free(agenda);
}