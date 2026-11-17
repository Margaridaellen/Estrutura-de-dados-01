#include <stdio.h>
#include "agenda.h"

int main(void) {
    Agenda* minha_agenda = agenda_criar();
    if (minha_agenda == NULL) return 1;

    agenda_exibir(minha_agenda);

    missao m1 = {101, "Configurar ambiente", 1};
    missao m2 = {102, "Implementar lista encadeada", 2};
    missao m3 = {103, "Escrever testes unitarios", 3};
    missao m4 = {104, "Revisar documentacao", 1};

    agenda_adicionar_fim(minha_agenda, m1);     

    agenda_adicionar_inicio(minha_agenda, m2);  

    agenda_adicionar_fim(minha_agenda, m3);   

    agenda_adicionar_inicio(minha_agenda, m4); 

    agenda_exibir(minha_agenda);

    agenda_destruir(minha_agenda);
    return 0;
}