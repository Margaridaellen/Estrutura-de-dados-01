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

    return 0;
}