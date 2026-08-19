#include <stdio.h>

void ganhovida(int *v){
  *v = *v+ 5;
  printf("|Você ganhou 5 pontos de vida extra!\n|Sua vida agora é: %d \n \n",*v);
  return;
}
void danovida(int *p){
    *p= *p-10;
    printf("|Que pena você perdeu 10 pontos de vida! \n|Sua vida agora é: %d \n",*p);
    return;
}
void pontuacao(int *P){
   *P=*P*2;
   printf("|Parabéns! Por avançar de nível sua pontuação duplicou \n|Sua pontuação agora é:%d pontos",*P);
   }

void tesouro(int *x){
   *x=*x+1;
   printf("|Você conseguio um novo tesouro!\n|Você possui:%d tesouro",*x);
    return;
}
int main() {

    int vida=100;
    int tesouro_ativo=0;
    int p=10;

    void *ptr_vida=&vida;
    void *ptr_tesouro=&tesouro_ativo;
    int *ptr_p=&p;

    printf("Jogador\n");
    printf("| Vida inicial: %d  \n| Tesouro Ativo: %d\n| Pontuação inicial:%d \n| Endereço da vida: %p\n\n", vida, tesouro_ativo,p,ptr_vida);

    printf("Dano de vida\n");
    danovida(ptr_vida);

    printf("\nPontos de vida\n");
    ganhovida(ptr_vida);
    

    printf("Tesouro\n");
    tesouro(ptr_tesouro);
    printf("\n|Endereço do tesouro:%p\n\n",ptr_tesouro);

    printf("Pontuação\n");
    pontuacao(ptr_p);
    return 0;
}