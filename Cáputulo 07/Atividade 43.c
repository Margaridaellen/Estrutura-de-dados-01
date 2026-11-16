#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct missao{
    int id;
    char desc[100];
    struct missao* prox;
}missao;

void inserir(missao** inicio, int id, const char* desc){
    missao* novo= (missao*) malloc (sizeof(missao));
    if(novo == NULL) return;

    novo->id=id;
    strcpy (novo->desc,desc);

    novo->prox=*inicio;
    *inicio=novo;
}

void fim (missao** inicio,int id, const char* desc){
    missao* novo =(missao*) malloc (sizeof(missao));
    if(novo == NULL) return;

    novo->id=id;
    strcpy (novo->desc,desc);
    novo->prox=NULL;

    if(*inicio == NULL){
        *inicio = novo;
        return;
    }
}

void exibir (missao* inicio){
    if (inicio == NULL){
        printf("\nNenhuma missão está cadastrada!");
        return ;
    }

    missao* atual = inicio;
    printf("\n| Ordem atual |\n");
    while (atual != NULL){
        printf("[%d] %s\n",atual->id,atual->desc);
        atual=atual->prox;
    }
}

void liberar(missao** inicio){
    missao* atual = *inicio;
    missao* proximo;
    while (atual != NULL){
        proximo = atual -> prox;
        free (atual);
        atual=proximo;
    }
    *inicio=NULL;
}

int main(){
    missao* listamissoes = NULL;
    exibir(listamissoes);
    fim(&listamissoes,101,"Verificação de sensor de segurança");
    fim(&listamissoes,102,"Enviando relatório");
    inserir(&listamissoes,99,"Reiniciar sistema");
    fim(&listamissoes,103,"Arquivando");
    inserir(&listamissoes,98,"Erro critico: Falha na operação B");
    exibir(listamissoes);
    liberar(&listamissoes);

    return 0;
}