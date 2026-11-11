#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int id;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
}

void push(Pilha *p, int id) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;

    novo->id = id;
    novo->proximo = p->topo;
    p->topo = novo;
    printf("Push: %d\n", id);
}

void exibir(Pilha *p) {
    if (!p->topo) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Pilha: ");
    for (No *atual = p->topo; atual != NULL; atual = atual->proximo) {
        printf("[%d] ", atual->id);
    }
    printf("\n");
}

int pop(Pilha *p, int *removido) {
    if (p->topo == NULL) return 0; 

    No *temp = p->topo;
    *removido = temp->id;
    p->topo = p->topo->proximo;
    free(temp);

    return 1; 
}

int main() {
    Pilha p;
    int valor;

    inicializar(&p);

    printf("Teste 1: Vazia\n");
    exibir(&p);
    if (!pop(&p, &valor)) printf("Erro: Pilha vazia ao tentar Pop!\n");

    printf("\n Teste 2: Um Elemento\n");
    push(&p, 10);
    exibir(&p);
    if (pop(&p, &valor)) printf("Pop: %d\n", valor);
    exibir(&p);

    printf("\n Teste 3: Varios Elementos \n");
    push(&p, 100);
    push(&p, 200);
    push(&p, 300);
    exibir(&p);

    while (pop(&p, &valor)) {
        printf("Pop: %d\n", valor);
    }
    exibir(&p);

    return 0;
}