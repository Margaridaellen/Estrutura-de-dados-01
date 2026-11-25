#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char desc[100];
} Acao;

typedef struct No {
    Acao dado;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
}

int esta_vazia(Pilha *p) { 
    return p->topo == NULL;
 }

int push(Pilha *p, Acao a) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->dado = a;
    novo->prox = p->topo;
    p->topo = novo;
    return 1;
}

void exibir(Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia.\n");
        return;
    }

    for (No *atual = p->topo; atual != NULL; atual = atual->prox) {
        printf("[%d] %s\n", atual->dado.id, atual->dado.desc);
    }
}

int peek (Pilha *p, Acao *topo) {
    if (esta_vazia(p)) return 0;
    *topo = p->topo->dado;
    return 1;
}

int pop(Pilha *p, Acao *removida) {
    if (p->topo == NULL) return 0;

    No *aux = p->topo;
    *removida = aux->dado;
    p->topo = aux->prox;
    free(aux);
    return 1;
}

int main(void) {
    Pilha p;
    Acao r;
    Acao a;
    inicializar(&p);
    int op = -1, id = 1;

    inicializar(&p);

    printf("| Pilha vazia | \n");
    exibir(&p);
    printf("Pop em que a pilha vazia retornou: %d\n\n", pop(&p, &r));

    printf("| Um elemento |\n");
    push(&p, (Acao){1, "Abriu o atendimento"});
    exibir(&p);
    if (pop(&p, &r)) printf("Removido: [%d] %s\n", r.id, r.desc);
    printf("Pop após esvaziar a pilha retornou: %d\n\n", pop(&p, &r));

    printf("| Varios elementos |\n");
    push(&p, (Acao){1, "Número de telefone"});
    push(&p, (Acao){2, "Endereco"});
    push(&p, (Acao){3, "Emitiu boleto"});
    exibir(&p);

    printf("Removendo todos os elementos:\n");
    while (pop(&p, &r)) {
        printf("Removido: [%d] %s\n", r.id, r.desc);
    }

    while (op != 0) {
        if (esta_vazia(&p))
            printf("\nStatus: nada para desfazer.\n");
        else if (peek(&p, &a))
            printf("\nTopo atual: [%d] %s\n", a.id, a.desc);

        printf("1-Push \n2-Peek \n3-Pop  \n4-Exibir  \n0-Sair:\n Escolha uma opçaõ: ");
        if (scanf("%d", &op) != 1) break;

        if (op >= 2 && op <= 4 && esta_vazia(&p)) {
            printf("Pilha vazia. Operacao cancelada.\n");
            continue;
        }

        switch (op) {
            case 1:
                a.id = id++;
                printf("Acao: ");
                scanf(" %99[^\n]", a.desc);
                if (!push(&p, a)) printf("Erro de memoria.\n");
                break;

            case 2:
                printf("Antes:\n");  exibir(&p);
                if (peek(&p, &a))    printf("Peek -> [%d] %s\n", a.id, a.desc);
                printf("Depois:\n"); exibir(&p);
                break;

            case 3:
                if (pop(&p, &a)) printf("Desfeito: [%d] %s\n", a.id, a.desc);
                break;

            case 4:
                exibir(&p);
                break;

            default:
                if (op != 0) printf("Opcao invalida.\n");
        }
    }

    while (pop(&p, &a)) {}

    return 0;
}