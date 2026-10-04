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

// Q25
void liberar_partidas(Partida **partidas, int *qtd) {
    if (*partidas != NULL) {
        for (int i = 0; i < *qtd; i++) {
            free((*partidas)[i].nome);
            (*partidas)[i].nome = NULL;
        }
        free(*partidas);
        *partidas = NULL;
    }
    *qtd = 0;
}

// Q24 / Q25
void salvarpartidas(const char *nome_arquivo, const Partida *partidas, int t) {
    if (t <= 0 || partidas == NULL) {
        printf("Não ha partidas registradas para salvar.\n");
        return;
    }

    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    if (fwrite(&t, sizeof(int), 1, arquivo) != 1) {
        printf("Erro ao gravar o total de registros.\n");
        fclose(arquivo);
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

        size_t tam_nome = (partidas[i].nome != NULL) ? strlen(partidas[i].nome) + 1 : 0;
        if (fwrite(&tam_nome, sizeof(size_t), 1, arquivo) != 1) {
            printf("Erro ao gravar tamanho do campo 'nome' na partida %d.\n", i);
            fclose(arquivo);
            return;
        }

        if (tam_nome > 0) {
            if (fwrite(partidas[i].nome, sizeof(char), tam_nome, arquivo) != tam_nome) {
                printf("Erro ao gravar  %d.\n", i);
                fclose(arquivo);
                return;
            }
        }
    }

    fclose(arquivo);
    printf("Os dados foram salvos com sucesso em %s! (Total: %d partidas)\n", nome_arquivo, t);
}

int lerpartidas(const char *nome, Partida **partidas, int *qtd) {
    FILE *arquivo = fopen(nome, "rb");

    if (arquivo == NULL) {
        printf("O histórico esta vazio ou o arquivo não foi encontrado.\n");
        return 0;
    }

    int novaquantidade = 0;
    if (fread(&novaquantidade, sizeof(int), 1, arquivo) != 1) {
        printf("Falha ao ler a quantidade de partidas do arquivo.\n");
        fclose(arquivo);
        return 0;
    }

    if (novaquantidade <= 0) {
        printf("Quantidade invalida lida do arquivo (%d).\n", novaquantidade);
        fclose(arquivo);
        return 0;
    }

    liberar_partidas(partidas, qtd);

    *partidas = (Partida *) malloc(novaquantidade * sizeof(Partida));
    if (*partidas == NULL) { 
        printf(" Falha ao alocar memoria para as partidas.\n");
        fclose(arquivo);
        return 0;
    }

    for (int i = 0; i < novaquantidade; i++) {
        (*partidas)[i].nome = NULL;

        if (fread(&(*partidas)[i].id, sizeof(int), 1, arquivo) != 1 ||
            fread((*partidas)[i].jogador, sizeof(char), 50, arquivo) != 50 ||
            fread(&(*partidas)[i].pontuacao, sizeof(float), 1, arquivo) != 1) {
            
            printf("[Erro] Registro incompleto ao ler campos fixos da partida %d.\n", i);
            liberar_partidas(partidas, qtd);
            fclose(arquivo);
            return 0;
        }

        size_t tam_nome = 0;
        if (fread(&tam_nome, sizeof(size_t), 1, arquivo) != 1) {
            printf(" Registro incompleto ao ler tamanho da string na partida %d.\n", i);
            liberar_partidas(partidas, qtd);
            fclose(arquivo);
            return 0;
        }

        if (tam_nome > 0) {
            (*partidas)[i].nome = (char *) malloc(tam_nome);
            if (!(*partidas)[i].nome) {
                printf("Falha ao alocar memoria para a string dinamica.\n");
                liberar_partidas(partidas, qtd);
                fclose(arquivo);
                return 0;
            }

            if (fread((*partidas)[i].nome, sizeof(char), tam_nome, arquivo) != tam_nome) {
                printf(" Erro ao ler a string dinamica da partida %d.\n", i);
                liberar_partidas(partidas, qtd);
                fclose(arquivo);
                return 0;
            }
        }
    }

    *qtd = novaquantidade;
    fclose(arquivo);
    printf("Historico restaurado com sucesso! %d partidas carregadas.\n", *qtd);
    return 1;
}

void cadastrarPartida(Partida **partidas, int *qtd) {
    int novaQtd = *qtd + 1;
    Partida *temp = (Partida *) realloc(*partidas, novaQtd * sizeof(Partida));

    if (temp == NULL) {
        printf(" Falha ao realocar memoria para nova partida.\n");
        return;
    }

    *partidas = temp;
    Partida *p = &((*partidas)[*qtd]);

    printf("\n |Cadastrar Partida [%d]|\n", novaQtd);
    printf("ID: ");
    scanf("%d", &p->id);

    printf("Nome do Jogador: ");
    scanf(" %[^\n]", p->jogador);

    printf("Pontuação: ");
    scanf("%f", &p->pontuacao);

    char buffer[100];
    printf("Nivel: ");
    scanf(" %[^\n]", buffer);

    p->nome = (char *) malloc(strlen(buffer) + 1);
    if (p->nome != NULL) {
        strcpy(p->nome, buffer);
    }

    *qtd = novaQtd;
    printf("Partida cadastrada com sucesso!\n");
}

void listarPartidas(const Partida *partidas, int qtd) {
    if (qtd == 0 || partidas == NULL) {
        printf("\nNenhuma partida em memoria.\n");
        return;
    }

    printf("\n| Historico de Partidas (%d)|\n", qtd);
    for (int i = 0; i < qtd; i++) {
        printf("[%d] ID: %d | Jogador: %-12s | Pontos: %6.2f | Nivel: %s\n", 
               i + 1, 
               partidas[i].id, 
               partidas[i].jogador, 
               partidas[i].pontuacao, 
               partidas[i].nome ? partidas[i].nome : "(null)");
    }
}

// Q2: Compara os registros dinâmicos
void comparar_partidas(const Partida *origem, const Partida *rest, int qtd) {
    printf("\nComparacao dos registros atuais e anteriores:\n");
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
    const char *origem = "partidas_origem.txt";
    const char *destino = "partidas_destino.txt";

    Partida *partidas = NULL;
    int quantidade = 0;
    int opcao;

    do {
        printf("\n|Menu de Cadastros|\n");
        printf("1. Cadastrar partida\n");
        printf("2. Listar partidas\n");
        printf("3. Salvar em arquivo\n");
        printf("4. Carregar do arquivo\n");
        printf("5. Executar teste de comparacao e processamento (Q20 / Q24)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Erro o tentar acessar\n");
            break;
        }

        switch (opcao) {
            case 1:
                cadastrarPartida(&partidas, &quantidade);
                break;

            case 2:
                listarPartidas(partidas, quantidade);
                break;
            
            case 3:
                salvarpartidas(caminho_arquivo, partidas, quantidade);
                break;

            case 4:
                lerpartidas(caminho_arquivo, &partidas, &quantidade);
                break;
            
            case 5: {
                // Teste de gravação, leitura e comparação dinâmicos
                Partida historico1[3] = {
                    {0, "Maria", 100.0f, strdup("Fase_1")},
                    {1, "Ana",   20.0f,  strdup("Fase_2")},
                    {2, "Jose",  50.0f,  strdup("Fase_3")}
                };

                printf("\nGravando em binário\n");
                salvarpartidas("teste_temp.bin", historico1, 3);

                Partida *historico_restaurado = NULL;
                int qtd_restaurada = 0;
                lerpartidas("teste_temp.bin", &historico_restaurado, &qtd_restaurada);

                comparar_partidas(historico1, historico_restaurado, qtd_restaurada);

                for (int i = 0; i < 3; i++) {
                    free(historico1[i].nome);
                }
                liberar_partidas(&historico_restaurado, &qtd_restaurada);

                // Q20
                arquivo(origem);
                printf("\n|Processamento de Texto|\n");
                processar(origem, destino);
                break;
            }

            case 0:
                printf("Encerrando\n");
                break;

            default:
                printf("Opçãoo invalida!\n");
                break;
        } 
    } while (opcao != 0);

    liberar_partidas(&partidas, &quantidade);
    return 0;
}