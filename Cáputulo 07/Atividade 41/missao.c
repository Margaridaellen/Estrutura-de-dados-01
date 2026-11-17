#include <stdio.h>
#include <string.h>
#include "missao.h"

Missao criar_missao(int id, const char *titulo) {
    Missao nova;
    nova.id = id;
    nova.concluida = 0;

    strncpy(nova.titulo, titulo, sizeof(nova.titulo) - 1);
    nova.titulo[sizeof(nova.titulo) - 1] = '\0'; 

    return nova;
}

void exibir_missao(const Missao *m) {
    if (m == NULL) return;

    printf("[%s] Missao #%d: %s\n",
           m->concluida ? "X" : " ",
           m->id,
           m->titulo);
}

void concluir_missao(Missao *m) {
    if (m != NULL) {
        m->concluida = 1;
    }
}