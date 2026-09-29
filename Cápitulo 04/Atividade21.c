#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char jogador [50];
    int pontuacao;
}Partida;

void salvarpartidas(const char *nome, const Partida *partidas, int t){
    FILE *arquivo= fopen (nome, "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    for(int i= 0; i<t ; i++){
        fprintf(arquivo, "%d %s %d\n", partidas[i].id, partidas[i].jogador, partidas[i].pontuacao);
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso em: %s",nome);

}

void lerpartidas( const char *nome){
    FILE *arquivo = fopen (nome,"r");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo para leitura");
        return;
    }

    Partida x;
    printf("| Dados do arquivo |\n");
    while (fscanf(arquivo, "%d %49s %d", &x.id, x.jogador, &x.pontuacao) == 3) {
        printf("ID: %d | Jogador: %-15s | Pontuação: %d\n", x.id, x.jogador, x.pontuacao);
    }

    fclose(arquivo);

}

int main(){
    const char *caminho_arquivo = "relatorio_de_partidas.txt";

    Partida historico[3] = {
        {0, "Maria", 100},
        {1, "Ana", 20},
        {2, "José", 50}
    };

    salvarpartidas(caminho_arquivo,historico,3);
    lerpartidas(caminho_arquivo);

    return 0;

}