#include<stdio.h>
#include<string.h>

void ganhovida(int *v){
  printf("|Sua vida anterior era: %d\n",*v);
  *v = *v+ 5;
  printf("|Você ganhou 5 pontos de vida extra!\n|Sua vida agora é: %d \n \n",*v);
}
void pontuacao(int *P){
   printf("|Sua pontuação anterior era: %d\n",*P);
   *P=*P*2;
   printf("|Parabéns! Por avançar de nível sua pontuação duplicou \n|Sua pontuação agora é:%d pontos \n\n",*P);
   }
void posicao(int *po){
    printf("|Sua posição anterior era: %d\n",*po);
   *po=*po+1;
   printf("|Você avançou de posição! \n|Sua posição agora é: %d \n\n",*po);
   }

struct jogador {
    char n[20];
    int v;
    float p;
    int po;
}j;

int main(){
    struct jogador j;
    printf("Digite as informações do jogador:(nome, vida, pontos e posiçãoo) ");
    scanf("%s %d %f %d", j.n, &j.v, &j.p, &j.po);
    printf("Olá jogador %s\n", j.n);

    ganhovida(&j.v);
    pontuacao(&j.po);
    posicao(&j.po);

    return 0;
}
