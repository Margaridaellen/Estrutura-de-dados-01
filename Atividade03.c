#include <stdio.h>

void ganhovida(int *v){
  *v = *v+ 5;
  printf("|Você ganhou 5 pontos de vida extra!\n|Sua vida agora é: %d \n \n",*v);
}
void danovida(int *p){
    *p= *p-10;
    printf("|Que pena você perdeu 10 pontos de vida! \n|Sua vida agora é: %d \n",*p);
}
void pontuacao(int *P){
   *P=*P*2;
   printf("|Parabéns! Por avançar de nível sua pontuação duplicou \n|Sua pontuação agora é:%d pontos \n\n",*P);
   }

void tesouro(int *x){
   *x=*x+1;
   printf("|Você conseguio um novo tesouro!\n|Você possui:%d tesouro",*x);
}
int main() {

    int vida=100;
    int tesouro_ativo=0;
    int p=10;

// Usando ponteiros do tipo int* para compatibilidade com as funções
 
    int *ptr_vida=&vida;
    int *ptr_tesouro=&tesouro_ativo;
    int *ptr_p=&p;

    int pontuacao_total = 0;
    float altura_total = 0.0;

    int posicao[5]={1,2,3,4,5};

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

    printf("Você realizou 5 voltas ao longo do percurso! \n \n");
    printf("       -------Sobre cada posição------- \n");
     for (int i = 0; i < 5; i++) {
        int valor_atual = *(posicao + i);

    printf("Indice [%d] | Endereco: %p | Conteudo: %d\n", i, (void*)(posicao+1) ,valor_atual);
    //Em linguagem c vetor + 1, não significa some mais um,significa ir para o próximo.

    pontuacao_total += valor_atual;
    altura_total += (float)valor_atual / 2.0;}
    
    printf("\n|Regras da pontuação:\n->A pontuação total é a soma dos valores de cada posição\n->A altura total do percurso é a pontuação total dividida por 2 \n");

    printf("\n|Resultado final  \n");
    printf("Pontuacao Total: %d pontos\n", pontuacao_total);
    printf("Altura Total do Percurso: %.2f metros\n", altura_total);

    return 0;
     
}
