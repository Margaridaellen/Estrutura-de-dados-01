#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    int pontos;
    char jogador[50]; 
} partida;

int main() {
     char *arquivo = "Partida.bin";
    
    partida Original = {2, 500, "Jogador 1"};
    partida Restaurada = {0};

    FILE *fOut = fopen(arquivo, "wb");
    if (!fOut) {
        printf("Erro ao criar arquivo.\n");
        return 1;
    }

    size_t gravados = fwrite(&Original, sizeof(partida), 1, fOut);
    fclose(fOut);

    if (gravados != 1) {
        printf("Erro na escrita do arquivo!\n");
        return 1;
    }

    FILE *fIn = fopen(arquivo, "rb");
    if (!fIn) {
        printf("Erro ao abrir arquivo para leitura.\n");
        return 1;
    }

    fseek(fIn, 0, SEEK_END);
    if (ftell(fIn) == 0) {
        printf("Erro: Arquivo vazio!\n");
        fclose(fIn);
        return 1;
    }
    rewind(fIn);

    size_t lidos = fread(&Restaurada, sizeof(partida), 1, fIn);
    fclose(fIn);

    if (lidos != 1) {
        printf("Erro: Registro incompleto ou corrompido!\n");
        return 1;
    }

    printf("A partida foi restaurada!\n");
    printf("Resultado da partida \n");
    printf("| ID: %d \n| Pontos: %d \n| Jogador: %s\n", Restaurada.id, Restaurada.pontos, Restaurada.jogador);

    if (Original.id == Restaurada.id && Original.pontos == Restaurada.pontos && strcmp (Original.jogador,Restaurada.jogador)==0) {
        printf("\nApós a alteração os dados continuam iguais.\n");
    } else {
        printf("Os dados são diferentes.\n");
    }
    return 0;
}