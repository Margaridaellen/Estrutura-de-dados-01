#include <stdio.h>
#include "agenda.h"

int main(void) {
    Agenda* minha_agenda = agenda_criar();
    if (minha_agenda == NULL) return 1;

    Missao m1 = {101, "Configurar ambiente", 1};
    Missao m2 = {102, "Implementar lista encadeada", 2};
    Missao m3 = {103, "Escrever testes unitarios", 3};
    Missao m4 = {104, "Revisar documentacao", 1};
    Missao removida;

    agenda_adicionar_fim(minha_agenda, m1);
    agenda_adicionar_fim(minha_agenda, m2); 
    agenda_adicionar_fim(minha_agenda, m3); 
    agenda_adicionar_fim(minha_agenda, m4); 
    agenda_adicionar_fim(minha_agenda, removida); 

    printf("| Lista inicial|\n");
    agenda_exibir(minha_agenda);

    printf("\n| 01- Teste de bloqueios |\n");
    if (!agenda_remover_apos(minha_agenda, 999, &removida)) {
        printf("OK: remover_apos bloqueado para referencia inexistente (999).\n");
    }
    if (!agenda_remover_antes(minha_agenda, 999, &removida)) {
        printf("OK: remover_antes bloqueado para referencia inexistente (999).\n");
    }

    if (!agenda_remover_apos(minha_agenda, 105, &removida)) {
        printf("OK: impedida remocao depois do ultimo no (105).\n");
    }

    if (!agenda_remover_antes(minha_agenda, 101, &removida)) {
        printf("OK: impedida remocao antes do primeiro no (101).\n");
    }

    printf("\n|02- Remoão antes do segundo|\n");
    if (agenda_remover_antes(minha_agenda, 102, &removida)) {
        printf("Removido antes de 102 (era o inicio): [ID: %d] %s\n",removida.id, removida.descricao);
    }
    agenda_exibir(minha_agenda); 

    printf("\n| Remoção antes do intermediário |\n");
    if (agenda_remover_antes(minha_agenda, 104, &removida)) {
        printf("Removido antes de 104: [ID: %d] %s\n",removida.id, removida.descricao);
    }
    agenda_exibir(minha_agenda); 

    printf("\n| 04- Remoção antes da interferência|\n");
    if (agenda_remover_apos(minha_agenda, 102, &removida)) {
        printf("Removido apos 102: [ID: %d] %s\n", removida.id, removida.descricao);
    }
    agenda_exibir(minha_agenda); 

    if (agenda_remover_apos(minha_agenda, 102, &removida)) {
        printf("Removido apos 102 (era o ultimo): [ID: %d] %s\n", removida.id, removida.descricao);
    }
    agenda_exibir(minha_agenda);

    agenda_destruir(minha_agenda);

    printf("\nTeste 1: Lista vazia\n");
    if (!agenda_remover_inicio(minha_agenda, &removida)) {
        printf("Protecao OK: nao e possivel remover de lista vazia.\n");
    }

    printf("\nTeste 2: Lista com nó\n");
    agenda_adicionar_inicio(minha_agenda, m1);

    if (agenda_adicionar_antes(minha_agenda, 101, m2)) { 
        printf("Inserido ID 102 antes do inicio (101).\n");
    }
    agenda_exibir(minha_agenda);

    agenda_remover_inicio(minha_agenda, &removida); 
    printf("Removido do inicio: [ID: %d] %s\n", removida.id, removida.descricao);

    agenda_remover_inicio(minha_agenda, &removida); 
    printf("Removido unico no: [ID: %d] %s\n", removida.id, removida.descricao);
    agenda_exibir(minha_agenda);

    printf("\nTeste 3: Lista com vários nós\n");
    agenda_adicionar_fim(minha_agenda, m1); 
    agenda_adicionar_fim(minha_agenda, m3); 

    if (agenda_adicionar_antes(minha_agenda, 103, m2)) {
        printf("Inserido ID 102 antes do ID 103.\n");
    }

    if (agenda_adicionar_antes(minha_agenda, 101, m4)) { 
        printf("Inserido ID 104 antes do inicio (101).\n");
    }

    Missao m_invalida = {999, "Invalida", 1};
    if (!agenda_adicionar_antes(minha_agenda, 888, m_invalida)) {
        printf("Referencia 888 inexistente: lista permaneceu inalterada.\n");
    }
    agenda_exibir(minha_agenda);

    if (agenda_remover_inicio(minha_agenda, &removida)) {
        printf("\nRemovido do inicio: [ID: %d] %s (Prioridade: %d)\n", removida.id, removida.descricao, removida.prioridade);
    }

    agenda_exibir(minha_agenda);
    agenda_destruir(minha_agenda);

    agenda_adicionar_fim(minha_agenda, m1);     
    agenda_adicionar_inicio(minha_agenda, m2);  
    agenda_adicionar_fim(minha_agenda, m3);    
    agenda_adicionar_inicio(minha_agenda, m4);  

    agenda_exibir(minha_agenda);
    printf("\n");

    Missao buscada;
    if (agenda_buscar(minha_agenda, 101, &buscada)) {
        printf("Busca: Missao %d encontrada -> %s\n", buscada.id, buscada.descricao);
    } else {
        printf("Busca: Missao nao encontrada.\n");
    }

    Missao m5 = {105, "Criar funcao de busca", 2};
    if (agenda_adicionar_apos(minha_agenda, 102, m5)) {
        printf("Sucesso: Missao %d inserida apos a missao 102.\n", m5.id);
    } else {
        printf("Falha: Missao de referencia 102 nao encontrada.\n");
    }

    Missao m6 = {106, "Entregar projeto final", 1};
    if (agenda_adicionar_apos(minha_agenda, 103, m6)) {
        printf("Sucesso: Missao %d inserida apos a missao 103 (ultimo no).\n", m6.id);
    } else {
        printf("Falha: Missao de referencia 103 nao encontrada.\n");
    }

    Missao m7 = {107, "Missao fantasma", 3};
    if (agenda_adicionar_apos(minha_agenda, 999, m7)) {
        printf("Sucesso: Missao %d inserida apos a missao 999.\n", m7.id);
    } else {
        printf("Falha: Missao de referencia 999 nao existe. Lista inalterada.\n");
    }

    printf("\n");
    agenda_exibir(minha_agenda);

    agenda_destruir(minha_agenda);
    return 0;
}