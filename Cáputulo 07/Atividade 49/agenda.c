#include "agenda.h"
#include <stdio.h>
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
    if (agenda == NULL) return false;

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) return false;

    novo_no->dado = nova_missao;
    novo_no->proximo = agenda->inicio;
    agenda->inicio = novo_no;

    return true;
}

bool agenda_adicionar_fim(Agenda* agenda, Missao nova_missao) {
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
               atual->dado.descricao, 
               atual->dado.prioridade);
        
        atual = atual->proximo; 
    }
}

static No* buscar_no_por_id(const Agenda* agenda, int id) {
    if (agenda == NULL) return NULL;

    No* atual = agenda->inicio;
    while (atual != NULL) {
        if (atual->dado.id == id) {
            return atual;  
        }
        atual = atual->proximo;
    }
    return NULL;
}
bool agenda_buscar(const Agenda* agenda, int id, Missao* resultado) {
    No* encontrado = buscar_no_por_id(agenda, id);
    if (encontrado == NULL) {
        return false;
    }

    if (resultado != NULL) {
        *resultado = encontrado->dado;
    }
    return true;
}

bool agenda_adicionar_apos(Agenda* agenda, int id_referencia, Missao nova_missao) {
    if (agenda == NULL) return false;

    No* referencia = buscar_no_por_id(agenda, id_referencia);
    if (referencia == NULL) {
        return false; 
    }

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) return false;

    novo_no->dado = nova_missao;

    novo_no->proximo = referencia->proximo;

    referencia->proximo = novo_no;

    return true;
}
bool agenda_adicionar_antes(Agenda* agenda, int id_referencia, Missao nova_missao) {
    if (agenda == NULL || agenda->inicio == NULL) {
        return false;
    }

    No* anterior = NULL;
    No* atual = agenda->inicio;

    while (atual != NULL && atual->dado.id != id_referencia) {
        anterior = atual;
        atual = atual->proximo;
    }


    if (atual == NULL) {
        return false;
    }

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        return false;
    }

    novo_no->dado = nova_missao;
    novo_no->proximo = atual;

    if (anterior == NULL) {
        agenda->inicio = novo_no;
    } else {
        anterior->proximo = novo_no;
    }

    return true;
}

bool agenda_remover_inicio(Agenda* agenda, Missao* removida) {
    if (agenda == NULL || agenda->inicio == NULL) {
        return false;
    }

    No* no_removido = agenda->inicio;

    if (removida != NULL) {
        *removida = no_removido->dado;
    }

    agenda->inicio = no_removido->proximo;
    free(no_removido);

    return true;
}

bool agenda_remover_fim(Agenda* agenda, Missao* removida) {
    if (agenda == NULL || agenda->inicio == NULL) {
        return false;
    }

    No* anterior = NULL;
    No* atual = agenda->inicio;


    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (removida != NULL) {
        *removida = atual->dado;
    }

    if (anterior == NULL) {
        agenda->inicio = NULL;
    } else {
     
        anterior->proximo = NULL;
    }

    free(atual);
    return true;
}

bool agenda_remover_por_id(Agenda* agenda, int id, Missao* removida) {
    if (agenda == NULL || agenda->inicio == NULL) {
        return false;
    }

    No* anterior = NULL;
    No* atual = agenda->inicio;

    while (atual != NULL && atual->dado.id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return false;
    }

    if (removida != NULL) {
        *removida = atual->dado;
    }

    if (anterior == NULL) {
        agenda->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return true;
}

bool agenda_remover_apos(Agenda* agenda, int id_referencia, Missao* removida) {
    if (agenda == NULL || agenda->inicio == NULL) {
        return false;
    }

    No* referencia = buscar_no_por_id(agenda, id_referencia);

    if (referencia == NULL || referencia->proximo == NULL) {
        return false;
    }

    No* no_removido = referencia->proximo;

    if (removida != NULL) {
        *removida = no_removido->dado;
    }

    referencia->proximo = no_removido->proximo;
    free(no_removido);

    return true;
}

bool agenda_remover_antes(Agenda* agenda, int id_referencia, Missao* removida) {
    if (agenda == NULL || agenda->inicio == NULL) {
        return false;
    }

    No* ant_anterior = NULL;
    No* anterior = NULL;
    No* atual = agenda->inicio;

    while (atual != NULL && atual->dado.id != id_referencia) {
        ant_anterior = anterior;
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL || anterior == NULL) {
        return false;
    }
    if (removida != NULL) {
        *removida = anterior->dado;
    }
    if (ant_anterior == NULL) {
        agenda->inicio = atual;
    } else {
        ant_anterior->proximo = atual;
    }

    free(anterior);

    return true;
}

void agenda_limpar(Agenda* agenda) {
    if (agenda == NULL) return;

    No* atual = agenda->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    agenda->inicio = NULL;
}

void agenda_destruir(Agenda* agenda) {
    if (agenda == NULL) return;

    agenda_limpar(agenda);
    free(agenda);
}

bool agenda_alterar(Agenda* agenda, int id, Missao novos_dados) {
    if (agenda == NULL) return false;

    No* alvo = buscar_no_por_id(agenda, id);
    if (alvo == NULL) {
        return false;
    }

    if (strlen(novos_dados.descricao) == 0 || novos_dados.prioridade <= 0) {
        return false;
    }

    alvo->dado = novos_dados;
    alvo->dado.id = id;

    return true;
}

int agenda_contar(const Agenda* agenda) {
    if (agenda == NULL) {
        return 0;
    }

    int total = 0;
    const No* atual = agenda->inicio;

    while (atual != NULL) {
        total++;
        atual = atual->proximo;
    }

    return total;
}

int agenda_importar_lote(Agenda* agenda, const Missao* lote, int quantidade) {
    if (agenda == NULL || lote == NULL || quantidade <= 0) {
        return -1;
    }

    int inseridos = 0;

    for (int i = 0; i < quantidade; i++) {
        if (!agenda_adicionar_fim(agenda, lote[i])) {
            break;
        }
        inseridos++;
    }

    return inseridos;
}