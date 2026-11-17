#ifndef MISSAO_H
#define MISSAO_H

typedef struct {
    int id;
    char titulo[100];
    int concluida; 
} Missao;

Missao criar_missao(int id, const char *titulo);
void exibir_missao(const Missao *m);
void concluir_missao(Missao *m);

#endif // MISSAO_H