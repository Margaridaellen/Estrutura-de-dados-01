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

//Q44
missao* buscaid(missao* inicio, int idbuscar){
    missao*atual = inicio;
    while (atual !=  NULL){
        if(atual -> id == idbuscar){
            return atual;
        }
        atual= atual -> prox;
    }
    return NULL;
}

void inseririd(missao* inicio, int idref, int nid, const char* ndesc){
    missao* referencia = buscaid(inicio, idref);

    if (referencia == NULL){
        printf("Missão id %d não encontrada, nenhuma alteração foi feita.\n", idref);
        return;
    }

    missao* novo = (missao*)malloc(sizeof(missao));
    if (novo == NULL) {
        printf("\n Memória insuficiente para criar a missao.\n");
        return;
    }

    novo->id = nid;
    strncpy(novo->desc, ndesc, sizeof(novo->desc) - 1);
    novo->desc[sizeof(novo->desc) - 1] = '\0';

    novo->prox = referencia->prox;
    referencia->prox = novo;

    printf("Sucesso! Missão [%d] \"%s\" inserida depois da missão [%d].\n",nid, ndesc, idref);

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

    missao* lista = NULL;
    fim(&lista, 101, "Calibrar antenas");
    fim(&lista, 102, "Coletando amostras");
    fim(&lista, 103, "Retornar a base");
    exibir(lista);

    inseririd(lista,101,150,"Realizar tarefa");
    inseririd(lista,103,200,"Descarregar dados");
    inseririd(lista,999,300,"Missão 01");
    exibir(lista);
    liberar(&lista);

    return 0;
}