#include <stdio.h>
#include <stdlib.h>

#define BONUS 2.20f

typedef struct {
    int id;
    char jogador[50];
    float pontuacao;
} Partida;

void salvarpartidas(const char *nome, const Partida *partidas, int t) {
    FILE *arquivo = fopen(nome, "a");  // Modo "a" (append) para anexar registros no final sem apagar o arquivo

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < t; i++) {
        fprintf(arquivo, "%d %s %.2f\n", partidas[i].id, partidas[i].jogador, partidas[i].pontuacao);
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

    printf("\n Histórico de Partidas\n");

    while (fgets(l, sizeof(l), arquivo) != NULL) {
        lido = sscanf(l, "%d %49s %d", &x.id, x.jogador, &x.pontuacao);
        
        if (lido == 3) {
            c++;
            printf("[%d] ID: %d | Jogador: %-15s | Pontuação: %.2f\n", c, x.id, x.jogador, x.pontuacao);
        }
        else {
            printf("Linha ignorada por conter dados malformados: %s", l);
        }
    }
    
    if (c == 0) {
        printf("O histórico está vazio ou não possui registros válidos.\n");
    } else {
        printf("Total de registros lidos: %d\n", c);
    }

    fclose(arquivo);
}

//Qestão 20

void processar (const char *origem, const char*destino){
   FILE *f_origem = NULL;
   FILE *f_destino = NULL;
   int registrosprocessados =0;
     
   //Verificar o retorno do fopen na origem
   f_origem = fopen(origem,"r");
   if(f_origem == NULL){
        fprintf(stderr,"Erro ao tentar abrir arquivo na origem: %s\n",origem);
        return;
    }

   //Verificar retorno do fopen para o destino
   
   f_destino = fopen(destino, "w");
   if(f_destino == NULL){
    fprintf(stderr,"Erro ao tentar abrir arquivo no destino: %s\n",destino);
    fclose(f_origem);
    return;
   }

   Partida p;

   while(fscanf(f_origem, "%d %f", &p.id, &p.pontuacao)==2){
    p.pontuacao *= BONUS;
    fprintf(f_destino,"%d %.2f \n", p.id, p.pontuacao);
    registrosprocessados++;
   }

   fclose(f_origem);
   fclose(f_destino);
   printf("Total de registros processados: %d\n",registrosprocessados);

}

void arquivo(const char *caminho){
    FILE *f = fopen(caminho,"w");
    if(f!=NULL){
        fprintf(f, "100 000.0 \n"); 
        fprintf(f, "100 100.0 \n");
        fprintf(f, "100 110.0 \n");
        fclose(f);
    }
}

int main() {
    const char *caminho_arquivo = "relatorio_de_partidas.txt";

    //Q20
    const char *origem = "partidas_origem.txt";
    const char *destino = "partidas_destino.txt";

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

    arquivo(origem);

    printf("Processamento das partidas\n");
    processar(origem,destino);

    return 0;
}