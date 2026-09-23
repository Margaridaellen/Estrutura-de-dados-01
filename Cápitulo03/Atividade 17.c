#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME 40

typedef struct {
    char nome[NOME];
    int vida;
    int pontuacao;
    float pos1;
    float pos2;
    int id;
    int nivel;
    int ataque;
} Personagem;

Personagem criar_personagem(const char *nome, int nivel, int vida, int ataque) {
    Personagem p = { .nivel = nivel, .vida = vida, .ataque = ataque };
    strncpy(p.nome, nome, NOME - 1);
    p.nome[NOME - 1] = '\0';
    return p;
}

void nomeseguro(Personagem *p) {
    printf("Digite um novo nome para o personagem: ");
    scanf("%39s", p->nome);
}

void exibir_personagem(Personagem p) {
    printf(" [Personagem] Nome: %s | ID: %d | Vida: %d | Pontos: %d | Posição: (%.1f, %.1f) | Nível: %d | Ataque: %d\n", 
           p.nome, p.id, p.vida, p.pontuacao, p.pos1, p.pos2, p.nivel, p.ataque);
    printf("Endereço da cópia local (&p): %p\n", (void*)&p);
}

int calcularpoder(Personagem p) {
    return p.vida + (p.ataque * 2);
}

void md(Personagem p) {
    printf("\nDemonstração: Modificando a vida do personagem para 0 na cópia local...\n");
    p.vida = 0;
   
    printf("Vida alterada dentro da função: %d\n", p.vida);
}

int main(void) {
    size_t ca = 0;
    size_t nc = 0;

    printf("Digite a capacidade para o vetor inicial: ");
    
    if (scanf("%d", &ca) != 1 || ca == 0) {
        printf("Erro!\n");
        return 1;
    }

    int *vetor = (int *) calloc(ca, sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória inicial com calloc!\n");
        return 1;
    }

    printf("Vetor Inicial %d \n", ca);
    for (size_t i = 0; i < ca; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    printf("\nDigite a nova capacidade do vetor: ");

    if (scanf("%d", &nc) != 1 || nc == 0) {
        printf("Nova capacidade inválida!\n");
        free(vetor);
        return 1;
    }

    int *t = (int *) realloc(vetor, nc * sizeof(int));

    if (t == NULL) {

        printf("Erro ao realocar memória! O bloco %d não foi alterado.\n", ca);
        free(vetor); 
        return 1;
    }

    vetor = t;

    if (nc > ca) {
        for (size_t i = ca; i < nc; i++) {
            vetor[i] = 0;
        }
    }

    printf("Capacidade Atualizada\n");
    printf("Capacidade anterior: %d\n", ca);
    printf("Nova capacidade:     %d\n", nc);

    printf("Conteúdo Atualizado do vetor\n");
    for (size_t i = 0; i < nc; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    ca = nc;

    free(vetor);
    vetor = NULL;

    printf("Vetor liberado\n\n");

    Personagem p1 = {"João", 100, 0, 0.0f, 0.0f, 1, 1, 10};

    printf("Estado inicial do jogador\n");
    printf("ID: %d | Nome: %s | Vida: %d | Pontos: %d | Posição: (%.1f, %.1f) | Nível: %d | Ataque: %d\n", 
           p1.id, p1.nome, p1.vida, p1.pontuacao, p1.pos1, p1.pos2, p1.nivel, p1.ataque);
  
    printf("Endereço original no main: %p\n\n", (void*)&p1);

    p1.pontuacao = p1.pontuacao + 20;
    p1.vida = p1.vida - 10;
    p1.pos1 = p1.pos1 + 2.0f;
    p1.pos2 = p1.pos2 + 2.0f;

    if (p1.vida < 0) {
        p1.vida = 0;
    }

    printf("Estado alterado do jogador (na main)\n");
    printf("ID: %d | Nome: %s | Vida: %d | Pontos: %d | Posição: (%.1f, %.1f) | Nível: %d | Ataque: %d\n\n", 
           p1.id, p1.nome, p1.vida, p1.pontuacao, p1.pos1, p1.pos2, p1.nivel, p1.ataque);

    nomeseguro(&p1);
    exibir_personagem(p1);

    int poder = calcularpoder(p1);
    printf("Poder Total calculado: %d\n", poder);

    md(p1);

    printf("\nDados após tentativa de mudança\n");
    printf("Nome: %s | Vida: %d | Ataque: %d\n", p1.nome, p1.vida, p1.ataque);
    printf("O personagem na main continua inalterado\n");

    return 0;
}