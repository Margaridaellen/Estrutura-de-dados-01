#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef enum {
    ti,
    ts
} Tdado;

void mostrar(const void *ptr, Tdado tipo) {
    if (ptr == NULL) {
        printf("Ponteiro nulo.\n");
        return;
    }

    switch (tipo) {
        case ti: {
            const int *p_int = (const int *)ptr;
            printf("Valor int: %d\n", *p_int);
            break;
        }
        case ts: {
            const char *p_char = (const char *)ptr;
            printf("Valor char: %c\n", *p_char);
            break;
        }
    }
}

void liberar(void **ptr_lugar) {
    if (ptr_lugar == NULL || *ptr_lugar == NULL) {
        return; 
    }
    free(*ptr_lugar);   
    *ptr_lugar = NULL; 
}

float pontuacao(int *n, int *p) {
    printf("Sua equipe participou de quantas partidas: ");
    scanf("%d", p);

    if (*p > 10 || *p <= 0) {
        printf("Numero de partidas invalido! Informe um valor entre 1 e 10.\n");
        return 0.0;
    }

    int *partida = (int*) malloc(*p * sizeof(*partida));
    if (partida == NULL) {
        printf("Erro de alocacao.\n");
        return 0;
    }

    int soma = 0, maior = 0, np = 0;
    for (int i = 0; i < *p; i++) {
        partida[i] = (i + 1);
    } 

    for (int i = 0; i < *p; i++) {
        printf("Digite a pontuacao obtida na partida %d: ", partida[i]);
        scanf("%d", &n[i]);
        soma += n[i];

        if (i == 0 || n[i] > maior) {
            maior = n[i]; 
            np = partida[i];
        }
    }
    printf("\nA media de pontuacao por partida: %.2f\n", (float)soma / *p);
    printf("A maior pontuacao foi: %d na posicao %d\n", maior, np);

    free(partida);
    partida = NULL;

    return 0;
}

//Matriz linear: Sua memória aloca um único bloco, possui  maior velocidade e eficiência, e é mais simples possuindo um único free.
void linear(int l, int c) {
    if (l <= 0 || c <= 0) return;

    int *m = (int*) malloc(l * c * sizeof(int));
    if (!m) return;

    printf("\nMatriz Linear \n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &m[i * c + j]);
        }
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", m[i * c + j]);
        }
        printf("\n");
    }
    free(m);
}

//Matriz ponteiro de ponteiro:Aloca um vetor de ponteiros e depois cada linha separadamente, ocorre maior fragmentação da memória e é necessário liberar linha por linha
void pp(int l1, int c1) {
    if (l1 <= 0 || c1 <= 0) return;

    int **m = (int**) malloc(l1 * sizeof(int*));
    if (!m) return;

    for (int i = 0; i < l1; i++) {
        m[i] = (int*) malloc(c1 * sizeof(int));
        if (!m[i]) {
            for (int j = 0; j < i; j++) free(m[j]); 
            free(m);
            return;
        }
    }

    printf("\nMatriz Ponteiro de Ponteiros\n");
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < l1; i++) free(m[i]);
    free(m);
}

int main(void) { 
    char a[10], a1[30];
    char s[5], s1[5];
    char n[5][60];
    char ne[30];
    char nbusca[5][60];
    int c, l, nl, nc;
    int *pc = &c;
    int *pl = &l;
    int na, v;
    int x[10], p = 0; 
    int linear, l0, c0;

    printf("Digite a quantidade de jogadores:");
    scanf("%d", &na); 
    if (na <= 0 || na > 5) {
        printf("Quantidade invalida de jogadores.\n");
        return 1;
    }

    int *quantidade = (int*) malloc(na * sizeof(*quantidade));
    if (quantidade == NULL) {
        printf("Erro\n");
        exit(1);
    }
    for (int p_idx = 0; p_idx < na; p_idx++) {
        quantidade[p_idx] = (p_idx + 1);
    } 

    free(quantidade);
    quantidade = NULL;

    for (int i = 0; i < na; i++) {
        printf("Cadastro do jogador %d\n", i + 1);
        printf("Digite o seu nome:");
        scanf("%s", n[i]);

        strcpy(nbusca[i], n[i]);

        printf("Ola! Para prosseguir com a aventura adote um apelido:");
        scanf("%9s", a);
        strcpy(a1, a);

        printf("%s, por questoes de seguranca, escolha uma senha:", a1);
        scanf("%s", s);
        printf("Digite a senha novamente:");
        scanf("%s", s1);
        
        if (strcmp(s, s1) == 0) {
            printf("Cadastro realizado com sucesso!\n");
        } else {
            printf("Erro, realize o cadastro novamente\n");
        }
    }

    printf("Digite o nome da sua equipe:");
    scanf("%s", ne);

    for (int i = 0; i < na; i++) {
        strcat(n[i], " - "); 
        strcat(n[i], ne);   
        printf("Integrante %d: %s\n", i + 1, n[i]);
    }

    char aa[60];
    int encontrado = 0;

    printf("\nDigite apenas o nome do jogador para pesquisar: ");
    scanf("%s", aa);

    for (int i = 0; i < na; i++) {
        if (strcmp(nbusca[i], aa) == 0) {
            printf("Jogador %s encontrado na posicao %d! (Cadastro completo: %s)\n\n", nbusca[i], i + 1, n[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Jogador nao encontrado.\n\n");
    }

    printf("Construindo o mapa!\n");
    printf("Digite o valor de colunas:");
    scanf("%d", &c);
    printf("Digite o valor de linhas:");
    scanf("%d", &l);

    if (l <= 0 || c <= 0) {
        printf("Dimensoes invalidas.\n");
        return 1;
    }

    int m[*pl][*pc];
    for (int i0 = 0; i0 < l; i0++) {
        for (int j0 = 0; j0 < c; j0++) {
            m[i0][j0] = 0; 
        }
    }

    for (int i0 = 0; i0 < *pl; i0++) {
        for (int j0 = 0; j0 < *pc; j0++) {
            printf("Digite o valor da posicao [%d][%d]:", i0, j0);
            scanf("%d", &m[i0][j0]);
        }
    }

    printf("Digite o valor que deseja achar:");
    scanf("%d", &v);
    for (int i0 = 0; i0 < *pl; i0++) {
        for (int j0 = 0; j0 < *pc; j0++) {
            if (m[i0][j0] == v) {
                printf("O valor esta na linha %d e coluna %d\n", i0 + 1, j0 + 1);
            }
        }
    }

    printf("Posicoes livres ou ocupadas:\n");
    for (int i0 = 0; i0 < l; i0++) {
        for (int j0 = 0; j0 < c; j0++) {
            if (m[i0][j0] == 0) {
                printf(" Livre ");
            } else {
                printf(" Ocupada | %d \n", m[i0][j0]); 
            }
        }
    }

    char r;
    printf("Deseja alterar a posicao de algum jogador?(s/n):");
    scanf(" %c", &r);
    if (r == 's' || r == 'S') {
        printf("Digite a linha que deseja alterar:");
        scanf("%d", &nl);
        printf("Digite a coluna que deseja alterar:");
        scanf("%d", &nc);

        if (nl >= 1 && nl <= l && nc >= 1 && nc <= c) {
            printf("Digite o novo valor da posicao [%d][%d]: ", nl, nc);
            scanf("%d", &m[nl - 1][nc - 1]);
        } else {
            printf("Posicao invalida no mapa!\n");
        }
    }

    printf("Mapa final:\n");
    for (int i0 = 0; i0 < l; i0++) {
        for (int j0 = 0; j0 < c; j0++) {
            if (m[i0][j0] == 0) {
                printf("[%d][%d]: Livre | \n", i0 + 1, j0 + 1);
            } else {
                printf("[%d][%d]: Ocupada (Valor: %d)  | \n", i0 + 1, j0 + 1, m[i0][j0]);
            }
        }
    }
        
    int *p1 = (int *)malloc(sizeof(int));
    char *p2 = (char *)malloc(sizeof(char));

    if (p1 == NULL || p2 == NULL) {
        liberar((void **)&p1);
        liberar((void **)&p2);
        return EXIT_FAILURE;
    }

    *p1 = 42;
    *p2 = 'A';

    mostrar(p1, ti);
    mostrar(p2, ts);

    liberar((void **)&p1);
    liberar((void **)&p2);

    mostrar(p1, ti); 

    pontuacao(x, &p);
    printf("\n-Tabela de pontuacao\n");
    for (int i = 0; i < p; i++) {
        printf("Partida %d: %d pontos\n", i + 1, x[i]);
    }

    do {
        printf("\nMenu de matrizes dinâmicas\n");
        printf("1. Matriz Linear\n2. Matriz Ponteiro de Ponteiros\n0. Sair\nOpcao: ");
        scanf("%d", &linear);

        if (linear == 1 || linear== 2) {
            printf("Digite as Linhas e Colunas: ");
            scanf("%d %d", &l0, &c0);

            if (linear == 1) {
                pp(l0, c0); 
            } else {
                pp(l0, c0);
            }
        }
    } while (linear != 0);

    return 0;
}
