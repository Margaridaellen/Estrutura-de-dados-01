#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char jogador[50];
    int pontuacao;
} Partida;

void salvarpartidas(const char *nome, const Partida *partidas, int t) {
    FILE *arquivo = fopen(nome, "a");  // Modo "a" (append) para anexar registros no final sem apagar o arquivo

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < t; i++) {
        fprintf(arquivo, "%d %s %d\n", partidas[i].id, partidas[i].jogador, partidas[i].pontuacao);
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso em: %s\n", nome);
}

void lerpartidas(const char *nome) {
    FILE *arquivo = fopen(nome, "r");

    if (arquivo == NULL) {
        printf("O histórico está vazio, o arquivo não foi criado.\n");
        return;
    }

    Partida x;
    char l[100];
    int c = 0;
    int lido;

    printf("\n=== | Histórico de Partidas | ===\n");

    while (fgets(l, sizeof(l), arquivo) != NULL) {
        lido = sscanf(l, "%d %49s %d", &x.id, x.jogador, &x.pontuacao);
        
        if (lido == 3) {
            c++;
            printf("[%d] ID: %d | Jogador: %-15s | Pontuação: %d\n", c, x.id, x.jogador, x.pontuacao);
        }
        else {
            printf("[AVISO] Linha ignorada por conter dados malformados: %s", l);
        }
    }
    
    if (c == 0) {
        printf("O histórico está vazio ou não possui registros válidos.\n");
    } else {
        printf("----------------------------------------\n");
        printf("Total de registros lidos: %d\n", c);
    }

    fclose(arquivo);
}

int main() {
    const char *caminho_arquivo = "relatorio_de_partidas.txt";

    FILE *f_limpeza = fopen(caminho_arquivo, "w");
    if (f_limpeza != NULL) {
        fclose(f_limpeza);
    }

    Partida historico1[3] = {
        {0, "Maria", 100},
        {1, "Ana", 20},
        {2, "José", 50}
    };

    printf("Primeira rodada:\n");
    salvarpartidas(caminho_arquivo, historico1, 3);

    Partida historico2[2] = {
        {0, "Luiz", 110},
        {1, "Bianca", 120} };

    printf("\nAdicionando segunda rodada:\n");
    salvarpartidas(caminho_arquivo, historico2, 2);

    lerpartidas(caminho_arquivo);

    return 0;
}