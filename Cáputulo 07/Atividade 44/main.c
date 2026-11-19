#include <stdio.h>
#include "agenda.h"

int main(void) {
    Agenda* minha_agenda = agenda_criar();
    if (minha_agenda == NULL) return 1;

    Missao m1 = {101, "Configurar ambiente", 1};
    Missao m2 = {102, "Implementar lista encadeada", 2};
    Missao m3 = {103, "Escrever testes unitarios", 3};
    Missao m4 = {104, "Revisar documentacao", 1};

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