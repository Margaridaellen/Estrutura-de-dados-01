#include <stdio.h>
#include <stdlib.h>

struct jogador{
    int vida;
    int pontuacao;
};

int main(void){
    struct jogador v[3];
    int i;

    for(i=0;i<3;i++){
    printf("Jogador \n Vida: %d \nPontuação: %d");
    scanf("%d %d", &v[i].vida, &v[i].pontuacao);
    
}
return 0;
}