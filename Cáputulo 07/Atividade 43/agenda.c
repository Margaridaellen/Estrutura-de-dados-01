#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    missao dado;
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

bool agenda_adicionar_inicio(Agenda* agenda, missao nova_missao) {
    if (agenda == NULL) return false;

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) return false;

    novo_no->dado = nova_missao;
    novo_no->proximo = agenda->inicio;
    agenda->inicio = novo_no;

    return true;
}

bool agenda_adicionar_fim(Agenda* agenda, missao nova_missao) {
    if (agenda == NULL) {
        return false;
    }

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        return false;
    }

    novo_no->dado = nova_missao;
    novo_no->proximo = NULL;

    if (agenda->inicio == NULL) {
        agenda->inicio = novo_no;
    } 
   
    else {
        No* atual = agenda->inicio;

        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        
        atual->proximo = novo_no;
    }

    return true;
}

void agenda_exibir(const Agenda* agenda) {
    if (agenda == NULL) {
        printf("Erro: Agenda invalida.\n");
        return;
    }

    if (agenda->inicio == NULL) {
        printf("A agenda esta vazia.\n");
        return;
    }

    printf("Lista de missoes\n");

    No* atual = agenda->inicio;
    
    while (atual != NULL) {
        printf("[ID: %d] %s (Prioridade: %d)\n", 
               atual->dado.id, 
               atual->dado.desc, 
               atual->dado.prioridade);
        
        atual = atual->proximo; 
    }
    

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