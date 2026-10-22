#include <stdio.h>
#include <stdlib.h>

 struct jogador{
   char nome [10];
   int vida;
   int pontuacaoo;
   int posicao;
};

void vida(int v){
    v=v+5;
}

int main(){
    struct jogador v[3];
    int i,vi=0;

    for (i=0;i<3;i++){
        printf("Informe os dados do jogador:\n");
        scanf("%s %d %d %d", v[i].nome, &v[i].vida, &v[i].pontuacaoo, &v[i].posicao);

    }

    vida(vi);

    for(i=0;i<3;i++){
       printf("Jogador%d \n Nome: %s\n Vida:%d \n Pontuação:%d \n Posição:%d \n\n",i+1,v[i].nome,v[i].vida, v[i].pontuacaoo, v[i].posicao);

    }
    
    return 0;
}