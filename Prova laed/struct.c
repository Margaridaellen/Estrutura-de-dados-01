#include <stdio.h>
#include <stdlib.h>
#define tamanho 3

struct aluno{
    char nome[15];
    int idade;
    float nota;
};

int main(){
    struct aluno *turma [tamanho];

    for(int i=0; i<tamanho;i++){
         turma[i]=(struct aluno*)malloc(sizeof(struct aluno));
    }

     for(int i=0; i<tamanho;i++){
          printf("Digite o nome, a idade e a nota do aluno[%d]:", i+1);
          scanf("%s %d %f",turma[i]->nome, &turma[i]->idade, &turma[i]->nota);
     }

    for (int i = 0; i < tamanho; i++) {
        free(turma[i]);
    }

    return 0;
}