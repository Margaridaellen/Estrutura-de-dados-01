#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME 40
#define vida_maxima 100
#define Equipe 100

// Questão 20
typedef enum {
    Guerreiro = 1,
    Mago,
    Curandeiro,
    Arqueiro
} Classe;

const char* classeusuario(Classe c) {
    switch (c) {
        case Guerreiro:  return "Guerreiro";
        case Mago:       return "Mago";
        case Arqueiro:   return "Arqueiro";
        case Curandeiro: return "Curandeiro";
        default:         return "Inexistente";
    }
}

typedef struct {
    float x;
    float y;
} Posicao;

typedef struct {
    char nome[NOME];
    int vida;
    int pontuacao;
    float pos1;
    float pos2;
    int id;
    int nivel;
    int ataque;
    Classe Classe; // adicionado q20
    Posicao pos;   // adicionado q20
} Personagem;

typedef struct {
    Personagem membros[Equipe];
    int total;
} equipemenu;

Personagem criar_personagem(const char *nome, int nivel, int vida, int ataque) {
    Personagem p = { .nivel = nivel, .vida = vida, .ataque = ataque };
    strncpy(p.nome, nome, NOME - 1);
    p.nome[NOME - 1] = '\0';
    return p;
}

void nomeseguro(Personagem *p) {
    printf("Digite um novo nome para o personagem: ");
    scanf(" %39[^\n]", p->nome);
}

void exibir_personagem(Personagem p) {
    printf("[ID: %2d] Nome: %-10s | Classe: %-10s | Vida: %d | Pontos: %d | Pos: (%.1f, %.1f) | Nivel: %d | Ataque: %d\n", 
           p.id, p.nome, classeusuario(p.Classe), p.vida, p.pontuacao, p.pos.x, p.pos.y, p.nivel, p.ataque);
    printf("Endereço da cópia local (&p): %p\n", (void*)&p);
}

int calcularpoder(Personagem p) {
    return p.vida + (p.ataque * 2);
}

void md(Personagem p) {
    printf("\nModificando a vida do personagem para 0 na cópia local\n");
    p.vida = 0;
    printf("Vida alterada dentro da função: %d\n", p.vida);
}

// Funções atividade 18
void v1(Personagem *p, int vidajogador) {
    if (vidajogador < 0) {
        printf("Erro, a vida não pode ser negativa \n");
        p->vida = 0;
    } else if (vidajogador > vida_maxima) {
        printf("Erro, a vida está maior que o máximo permitido que é %d \n", vida_maxima);
        p->vida = vida_maxima;
    } else {
        p->vida = vidajogador;
    }   
}

void posicao(Personagem *p, float np1, float np2) {
    p->pos1 = np1;
    p->pos2 = np2;
}

void pontuacao(Personagem *p, int novapontuacao) {
    if (novapontuacao > 0) {
        p->pontuacao += novapontuacao;
    } else {
        printf("Erro, a pontuação deve ser positiva\n");
    }
}

// Questão 19
void ordenar(Personagem x[], int total) {
    int i,j;
    int comparacao = 0;
    for ( i = 0; i < total - 1; i++) {
        int menor = i;

        for ( j = i + 1; j < total; j++) {
            comparacao++;
            if (x[j].id < x[menor].id) {
                menor = j;
            }
        }

        if (menor != i) {
            Personagem t = x[i];
            x[i] = x[menor];
            x[menor] = t;
        }
    }
    printf("Total comparações: %d\n", comparacao);
}

// Funções cadastro menu, q20
void cadastrar_menu(equipemenu *eq) {
    if (eq->total >= Equipe) {
        printf("Equipe cheia!\n");
        return;
    }

    Personagem p;
    printf("\nID: "); 
    scanf("%d", &p.id);
    printf("Nome: "); 
    scanf(" %39[^\n]", p.nome);
    printf("Vida: "); 
    scanf("%d", &p.vida);
    printf("Ataque: "); 
    scanf("%d", &p.ataque);
    printf("Classe (1-Guerreiro, 2-Mago, 3-Curandeiro, 4-Arqueiro): "); 
    scanf("%d", (int*)&p.Classe);
    printf("Posicao X e Y: "); 
    scanf("%f %f", &p.pos.x, &p.pos.y);
    p.pontuacao = 0;
    p.nivel = 1;

    eq->membros[eq->total++] = p;
    printf("Personagem cadastrado com sucesso\n");
}

void listar_menu(equipemenu *eq) {
    int i;
    printf("\n|Integrantes da equipe \n");
    for ( i = 0; i < eq->total; i++) {
        exibir_personagem(eq->membros[i]);
    }
}

int buscar_menu(equipemenu *eq, int id) {
    int i;
    for ( i = 0; i < eq->total; i++) {
        if (eq->membros[i].id == id) return i;
    }
    return -1;
}

void alterar_menu(equipemenu *eq) {
    int id;
    printf("Digite o Id do personagem para alterar: ");
    scanf("%d", &id);
    int pos = buscar_menu(eq, id);
    if (pos == -1) {
        printf("Personagem nao encontrado!\n");
        return;
    }
    printf("Novo nome: "); 
    scanf(" %39[^\n]", eq->membros[pos].nome);
    printf("Nova vida: "); 
    scanf("%d", &eq->membros[pos].vida);
    printf("Novo ataque: "); 
    scanf("%d", &eq->membros[pos].ataque);
    printf("Alterado com sucesso\n");
}

int main(void) {
    equipemenu equipe = { .total = 0 };
    int opcao;
    int i;

    equipe.membros[0] = (Personagem){"Luis", 100, 0, 0.0f, 0.0f, 42, 15, 10, Guerreiro, {0.0f, 0.0f}};
    equipe.membros[1] = (Personagem){"Pedro", 80, 0, 0.0f, 0.0f, 10, 20, 12, Mago, {1.5f, 2.0f}};
    equipe.membros[2] = (Personagem){"Maria", 90, 0, 0.0f, 0.0f, 7, 18, 15, Arqueiro, {4.0f, 9.0f}};
    equipe.membros[3] = (Personagem){"Clara", 90, 0, 0.0f, 0.0f, 99, 5, 8, Curandeiro, {5.0f, 7.0f}};
    equipe.total = 4;

    do {
        printf("\nSistema da equipe\n");
        printf("1. Cadastrar Personagem\n");
        printf("2. Listar Personagens\n");
        printf("3. Buscar Personagem por ID\n");
        printf("4. Alterar Personagem\n");
        printf("5. Ordenar Equipe por ID\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_menu(&equipe);
                break;
            case 2:
                listar_menu(&equipe);
                break;
            case 3: {
                int id;
                printf("Digite o ID para busca: ");
                scanf("%d", &id);
                int idx = buscar_menu(&equipe, id);
                if (idx != -1) {
                    exibir_personagem(equipe.membros[idx]);
                } else {
                    printf("Personagem não encontrado!\n");
                }
                break;
            }
            case 4:
                alterar_menu(&equipe);
                break;
            case 5:
                ordenar(equipe.membros, equipe.total);
                printf("Equipe ordenada com sucesso!\n");
                break;
            case 0:
                printf("Saindo do sistema\n");
                break;
            default:
                printf("Opção invalida\n");
        }
    } while (opcao != 0);

    size_t ca = 0;
    size_t nc = 0;

    printf("\nDigite a capacidade para o vetor inicial: ");
    
    if (scanf("%zu", &ca) != 1 || ca == 0) {
        printf("Erro!\n");
        return 1;
    }

    int *vetor = (int *) calloc(ca, sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória inicial com calloc!\n");
        return 1;
    }

    printf("Vetor Inicial %zu \n", ca);
    for (i = 0; i < ca; i++) {
        printf("vetor[%zu] = %d\n", i, vetor[i]);
    }

    printf("\nDigite a nova capacidade do vetor: ");

    if (scanf("%zu", &nc) != 1 || nc == 0) {
        printf("Nova capacidade inválida!\n");
        free(vetor);
        return 1;
    }

    int *t = (int *) realloc(vetor, nc * sizeof(int));

    if (t == NULL) {
        printf("Erro ao realocar memória! O bloco %zu não foi alterado.\n", ca);
        free(vetor); 
        return 1;
    }

    vetor = t;

    if (nc > ca) {
        for ( i = ca; i < nc; i++) {
            vetor[i] = 0;
        }
    }

    printf("Capacidade Atualizada\n");
    printf("Capacidade anterior: %zu\n", ca);
    printf("Nova capacidade:     %zu\n", nc);

    printf("Conteúdo Atualizado do vetor\n");
    for ( i = 0; i < nc; i++) {
        printf("vetor[%zu] = %d\n", i, vetor[i]);
    }

    ca = nc;

    free(vetor);
    vetor = NULL;

    printf("Vetor liberado\n\n");

    Personagem p1 = {"João", 100, 0, 0.0f, 0.0f, 1, 1, 10, Guerreiro, {0.0f, 0.0f}};

    printf("\nEstado inicial do jogador\n");
    printf("ID: %d | Nome: %s | Vida: %d | Pontos: %d | Posição: (%.1f, %.1f) | Nível: %d | Ataque: %d\n", 
           p1.id, p1.nome, p1.vida, p1.pontuacao, p1.pos1, p1.pos2, p1.nivel, p1.ataque);
  
    printf("\nEndereço original no main: %p\n\n", (void*)&p1);

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

    printf("\nFunção vida\n");
    v1(&p1, -20);
    exibir_personagem(p1);

    printf("\n Funções Pontuação e posição\n");
    pontuacao(&p1, 40);
    posicao(&p1, 4.0f, 9.0f);
    v1(&p1, 100);

    printf("Dados atualizados através das funções:\n");
    exibir_personagem(p1);

    int poder = calcularpoder(p1);
    printf("Poder Total calculated: %d\n", poder);

    md(p1);

    printf("\nDados após tentativa de mudança\n");
    printf("Nome: %s | Vida: %d | Ataque: %d\n", p1.nome, p1.vida, p1.ataque);
    printf("O personagem na main continua inalterado\n");

    printf("\nAntes da ordenação:\n");
    for ( i = 0; i < equipe.total; i++) {
        printf("| Id: %2d \n| Nome: %s\n", equipe.membros[i].id, equipe.membros[i].nome);
    }

    ordenar(equipe.membros, equipe.total);

    printf("\nApós ordenação:\n");
    for (i = 0; i < equipe.total; i++) {
        printf("| Id: %2d \n| Nome: %s\n", equipe.membros[i].id, equipe.membros[i].nome);
    }

    return 0;
}