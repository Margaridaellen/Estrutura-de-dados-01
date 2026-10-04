#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BONUS 2.20f

typedef struct {
    int id;
    char jogador[50];
    float pontuacao;
    char *nome; // Q24: Ponteiro para string alocada dinamicamente
} Partida;

// Q24
void salvarpartidas(const char *nome_arquivo, const Partida *partidas, int t) {
    FILE *arquivo = fopen(nome_arquivo, "wb"); // binário ("wb")
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < t; i++) {
        if (fwrite(&partidas[i].id, sizeof(int), 1, arquivo) != 1 ||
            fwrite(partidas[i].jogador, sizeof(char), 50, arquivo) != 50 ||
            fwrite(&partidas[i].pontuacao, sizeof(float), 1, arquivo) != 1) {
            
            printf("Erro ao gravar dados basicos da partida %d.\n", i);
            fclose(arquivo);
            return;
        }

        // Calcula o tamanho da string apontada pelo ponteiro e grava
        size_t tam_nome = (partidas[i].nome != NULL) ? strlen(partidas[i].nome) + 1 : 0;
        if (fwrite(&tam_nome, sizeof(size_t), 1, arquivo) != 1) {
            printf("Erro ao gravar tamanho da string na partida %d.\n", i);
            fclose(arquivo);
            return;
        }

        if (tam_nome > 0) {
            if (fwrite(partidas[i].nome, sizeof(char), tam_nome, arquivo) != tam_nome) {
                printf("Erro ao gravar conteudo da string dinamica na partida %d.\n", i);
                fclose(arquivo);
                return;
            }
        }
    } 

    fclose(arquivo);
    printf("Dados salvos com sucesso em: %s\n", nome_arquivo);
}

// Q24
int lerpartidas(const char *nome, Partida *destino, int max) {
    FILE *arquivo = fopen(nome, "rb"); // "rb" (leitura binária)

    if (arquivo == NULL) {
        printf("O histórico está vazio, o arquivo não foi criado.\n");
        return 0;
    }

    int c = 0;
    printf("\n| Historico de partidas restaurado |\n");

    while (c < max) {
        Partida temp;
        temp.nome = NULL;

        size_t lidos = 0;
        lidos += fread(&temp.id, sizeof(int), 1, arquivo);
        lidos += fread(temp.jogador, sizeof(char), 50, arquivo);
        lidos += fread(&temp.pontuacao, sizeof(float), 1, arquivo);

        if (lidos == 0) {
            break; 
        }

        if (lidos < 52) { //
            printf("Registro incompleto ao ler campos fixos.\n");
            fclose(arquivo);
            return c;
        }

        size_t tam_nome = 0;
        if (fread(&tam_nome, sizeof(size_t), 1, arquivo) != 1) {
            printf("Registro incompleto ao ler tamanho do ponteiro.\n");
            fclose(arquivo);
            return c;
        }

        if (tam_nome > 0) {
            temp.nome = (char *)malloc(tam_nome);
            if (!temp.nome) {
                printf("[Erro] Falha ao alocar memoria.\n");
                fclose(arquivo);
                return c;
            }

            if (fread(temp.nome, sizeof(char), tam_nome, arquivo) != tam_nome) {
                printf("[Erro] Registro incompleto ao ler dados apontados pelo ponteiro.\n");
                free(temp.nome);
                fclose(arquivo);
                return c;
            }
        }

        destino[c] = temp;

        printf("[%d] ID: %d | Jogador: %-10s | Pontos: %.2f | Nivel: %s\n", c + 1, temp.id, temp.jogador, temp.pontuacao, temp.nome ? temp.nome : "(null)");
        c++;
    }

    fclose(arquivo);
    return c;
}

// Q24
void comparar_partidas(const Partida *origem, const Partida *rest, int qtd) {
    printf("\nComparação dos registros atuais e anteriores \n");
    for (int i = 0; i < qtd; i++) {
        int igual = (origem[i].id == rest[i].id) &&
                    (strcmp(origem[i].jogador, rest[i].jogador) == 0) &&
                    (origem[i].pontuacao == rest[i].pontuacao);

        if (origem[i].nome && rest[i].nome) {
            if (strcmp(origem[i].nome, rest[i].nome) != 0) igual = 0;
        } else if (origem[i].nome != rest[i].nome) {
            igual = 0;
        }

        if (igual) {
            printf("Partida [%d]: Restaurada com sucesso (Identica ao original)\n", i);
        } else {
            printf("Partida [%d]: Uma diferenca foi identificada\n", i);
        }
    }
}

// Questão 20
void processar(const char *origem, const char *destino) {
    FILE *f_origem = fopen(origem, "r");
    if (f_origem == NULL) {
        fprintf(stderr, "Erro ao tentar abrir arquivo na origem: %s\n", origem);
        return;
    }

    FILE *f_destino = fopen(destino, "w");
    if (f_destino == NULL) {
        fprintf(stderr, "Erro ao tentar abrir arquivo no destino: %s\n", destino);
        fclose(f_origem);
        return;
    }

    Partida p;
    int registrosprocessados = 0;

    while (fscanf(f_origem, "%d %f", &p.id, &p.pontuacao) == 2) {
        p.pontuacao *= BONUS;
        fprintf(f_destino, "%d %.2f \n", p.id, p.pontuacao);
        registrosprocessados++;
    }

    fclose(f_origem);
    fclose(f_destino);
    printf("Total de registros processados: %d\n", registrosprocessados);
}

void arquivo(const char *caminho) {
    FILE *f = fopen(caminho, "w");
    if (f != NULL) {
        fprintf(f, "100 000.0 \n"); 
        fprintf(f, "100 100.0 \n");
        fprintf(f, "100 110.0 \n");
        fclose(f);
    }
}

int main() {
    const char *caminho_arquivo = "relatorio_de_partidas.bin";

    //Q23
    const char *origem = "partidas_origem.txt";
    const char *destino = "partidas_destino.txt";

    Partida historico1[3] = {
        {0, "Maria", 100.0f, strdup("Fase_1")},
        {1, "Ana",   20.0f,  strdup("Fase_2")},
        {2, "Jose",  50.0f,  strdup("Fase_3")}
    };

    printf("Primeira rodada (Gravando arquivos em binario):\n");
    salvarpartidas(caminho_arquivo, historico1, 3);

    Partida historico_restaurado[3];
    int lidos = lerpartidas(caminho_arquivo, historico_restaurado, 3);

    comparar_partidas(historico1, historico_restaurado, lidos);

    for (int i = 0; i < 3; i++) {
        free(historico1[i].nome);
        if (i < lidos) free(historico_restaurado[i].nome);
    }

    // Questão 20
    arquivo(origem);
    printf("\nProcessamento das partidas\n");
    processar(origem, destino);

    return 0;
}