#include <stdio.h>
#include "agenda.h"

int main(void) {
    Agenda* minha_agenda = agenda_criar();
    if (minha_agenda == NULL) return 1;

    Missao m1 = {101, "Configurar ambiente", 1};
    Missao m2 = {102, "Implementar lista encadeada", 2};
    Missao m3 = {103, "Escrever testes unitarios", 3};
    Missao m4 = {104, "Revisar documentacao", 1};
    Missao m5 = {105, "Publicar versao final", 2};
    Missao removida;

    printf("Busca e inserção após \n");
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

    Missao m_busca = {106, "Criar funcao de busca", 2};
    if (agenda_adicionar_apos(minha_agenda, 102, m_busca)) {
        printf("Sucesso: Missao %d inserida apos a missao 102.\n", m_busca.id);
    }

    Missao m_final = {107, "Entregar projeto final", 1};
    if (agenda_adicionar_apos(minha_agenda, 103, m_final)) {
        printf("Sucesso: Missao %d inserida apos a missao 103 (ultimo no).\n", m_final.id);
    }

    Missao m_fantasma = {108, "Missao fantasma", 3};
    if (!agenda_adicionar_apos(minha_agenda, 999, m_fantasma)) {
        printf("Falha: Missao de referencia 999 nao existe. Lista inalterada.\n");
    }

    agenda_exibir(minha_agenda);

    agenda_limpar(minha_agenda);
    printf("\nInserção antes e remoção\n");

    printf("Teste 1: Lista vazia\n");
    if (!agenda_remover_inicio(minha_agenda, &removida)) {
        printf("Protecao OK: nao e possivel remover de lista vazia.\n");
    }

    printf("\nTeste 2: Lista com 1 no\n");
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

    printf("\nTeste 3: Lista com varios nos\n");
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
        printf("Removido do inicio: [ID: %d] %s (Prioridade: %d)\n",
               removida.id, removida.descricao, removida.prioridade);
    }
    agenda_exibir(minha_agenda);

    agenda_limpar(minha_agenda);
    printf("\n=== BLOCO 3: REMOCOES POSICIONAIS ===\n");

    agenda_adicionar_fim(minha_agenda, m1); 
    agenda_adicionar_fim(minha_agenda, m2);
    agenda_adicionar_fim(minha_agenda, m3);
    agenda_adicionar_fim(minha_agenda, m4); 
    agenda_adicionar_fim(minha_agenda, m5); 

    printf("| Lista inicial |\n");
    agenda_exibir(minha_agenda);

    printf("\n| 01 - Teste de bloqueios |\n");
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

    printf("\n| 02 - Remocao antes do segundo (altera inicio) |\n");
    if (agenda_remover_antes(minha_agenda, 102, &removida)) {
        printf("Removido antes de 102 (era o inicio): [ID: %d] %s\n",
               removida.id, removida.descricao);
    }
    agenda_exibir(minha_agenda);

    printf("\n| 03 - Remocao antes de no intermediario |\n");
    if (agenda_remover_antes(minha_agenda, 104, &removida)) {
        printf("Removido antes de 104: [ID: %d] %s\n",
               removida.id, removida.descricao);
    }
    agenda_exibir(minha_agenda); 

    printf("\n| 04 - Remocao apos referencia (meio e fim) |\n");
    if (agenda_remover_apos(minha_agenda, 102, &removida)) {
        printf("Removido apos 102: [ID: %d] %s\n",
               removida.id, removida.descricao);
    }
    agenda_exibir(minha_agenda);

    if (agenda_remover_apos(minha_agenda, 102, &removida)) {
        printf("Removido apos 102 (era o ultimo): [ID: %d] %s\n",
               removida.id, removida.descricao);
    }
    agenda_exibir(minha_agenda);

    agenda_limpar(minha_agenda);
    printf("\n=== BLOCO 4: ALTERACAO E LIMPEZA ===\n");

    agenda_adicionar_fim(minha_agenda, m1);
    agenda_adicionar_fim(minha_agenda, m2);
    agenda_adicionar_fim(minha_agenda, m3);
    agenda_exibir(minha_agenda);

    Missao edicao_valida = {999, "Implementar lista encadeada completa", 1};
    if (agenda_alterar(minha_agenda, 102, edicao_valida)) {
        printf("\nSucesso: Missao 102 atualizada (chave ID preservada).\n");
    }

    Missao edicao_invalida = {101, "", -1};
    if (!agenda_alterar(minha_agenda, 101, edicao_invalida)) {
        printf("Bloqueado: Dados invalidos rejeitados para ID 101.\n");
    }

    if (!agenda_alterar(minha_agenda, 888, edicao_valida)) {
        printf("Bloqueado: ID 888 nao encontrado.\n");
    }
    agenda_exibir(minha_agenda);

    printf("\n--- Testes de limpeza ---\n");
    agenda_limpar(minha_agenda);
    printf("Apos primeira limpeza:\n");
    agenda_exibir(minha_agenda);

    agenda_limpar(minha_agenda);
    printf("Apos segunda limpeza (em lista ja vazia): OK sem erros.\n");

    Missao m_pos_limpeza = {201, "Nova tarefa pos-limpeza", 1};
    agenda_adicionar_fim(minha_agenda, m_pos_limpeza);
    printf("\nAgenda reutilizada apos limpeza:\n");
    agenda_exibir(minha_agenda);

    agenda_limpar(minha_agenda);
    printf("\nContagem e impostação de lote\n");

    printf("Tamanho inicial (lista vazia): %d missoes\n", agenda_contar(minha_agenda));

    Missao lote_vazio[1];
    if (agenda_importar_lote(minha_agenda, lote_vazio, 0) == -1) {
        printf("Protecao validada: lote com quantidade 0 rejeitado.\n");
    }

    Missao lote_missoes[] = {
        {301, "Modelar banco de dados", 1},
        {302, "Criar endpoints da API", 2},
        {303, "Implementar autenticacao", 1},
        {304, "Realizar deploy em homologacao", 3}
    };
    int qtd_lote = 4;

    printf("\nTamanho anterior a importacao: %d\n", agenda_contar(minha_agenda));

    int importados = agenda_importar_lote(minha_agenda, lote_missoes, qtd_lote);
    if (importados == qtd_lote) {
        printf("Sucesso: Todas as %d missoes do lote foram importadas na ordem original.\n", importados);
    } else if (importados >= 0) {
        printf("Alerta de memoria: Apenas %d de %d missoes foram importadas.\n", importados, qtd_lote);
    }

    printf("Tamanho depois da importacao: %d\n", agenda_contar(minha_agenda));
    agenda_exibir(minha_agenda);

    return 0;
}