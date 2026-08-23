#include <stdio.h>
int tm=10;
int vm=100;

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

int ler_mapa(int *mapa, int tamanho) { 
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor para a posição [%d]: ", i);
        scanf("%d", mapa + i); 

        if (*(mapa + i) < 0 || *(mapa + i) > vm){
          printf("Erro, o valor deve estar entre 0 e %d\n",vm);
          return 0;
        }
    }
    return 1;
}

void mostrar_mapa(const int *mapa, int tamanho) {
    printf("\nMapa \n");
    for (int i = 0; i < tamanho; i++) {
        printf("|Posicao %d: %d\n", i, *(mapa + i));
    }
}

void explorar_mapa(const int *mapa, int tamanho) {
    printf("\nExplorando o mapa!\n");
    for (int i = 0; i < tamanho; i++) {
        printf("|Visitando posicao %d com valor %d\n", i, *(mapa + i));
    }
}

//Acesso por Índice (mapa[i]): A cada iteração, calcula: (Endereço Inicial do Mapa + i).
//Incremento de Ponteiro (ptr++):penas avança o ponteiro para o próximo endereço consecutivo na memória.
 
void explorar_mapa_ponteiro(const int *mapa, int tamanho) {
    printf("\nPecorrendo o mapa\n");
    int pontuacao_total = 0;

    for (int i = 0; i < tamanho; i++) {
        pontuacao_total += mapa[i];

        printf("|Visitando posicao logica %d | Valor: %d | Pontuacao Acumulada: %d\n", 
               i, mapa[i], pontuacao_total);
    }

    printf("\nResumo do Percurso\n");
    printf("|Total de posicoes visitadas: %d\n", tamanho);
    printf("|Pontuacao total acumulada: %d\n", pontuacao_total);
}
void mostrarporvetor(char* inventario[], int tam) {
    printf("\nInventario\n");
    for (int i = 0; i < tam; i++) {
        printf("[%d] Item: %s\n", i, inventario[i]);
    }
}

void alterarporponteiro(char* inventario[], int tam) {
    int pos;
    printf("|Digite a posicao que deseja alterar(0 a 2): ");
    scanf("%d", &pos);

    if (pos >= 0 && pos < tam) {
        printf("|Digite um novo nome para o item: ");
        scanf("%s", *(inventario + pos));
        printf("|Item alterado com sucesso!\n");
    }
     else {
        printf("|Posicao invalida!\n");
    }
}

int main() {

    int vida=100;
    int tesouro_ativo=0;
    int pontuacao_total = 0;

// Usando ponteiros do tipo int* para compatibilidade com as funções
 
    int *ptr_vida=&vida;
    int *ptr_tesouro=&tesouro_ativo;
    int *ptr_p=&pontuacao_total;

    
    float altura_total = 0.0;

    int posicao[5]={1,2,3,4,5};

    int tamanho, mapa[tm];

    char mapao[30] = "Fase 1";

    char item0[20] = "Pocao de cura ";
    char item1[20] = "Espada";
    char item2[20] = "Escudo";
    
    char* inventario[3] = { item0, item1, item2 };

    int opcao = 0;
     
    printf("Jogador\n");
    printf("| Vida inicial: %d  \n| Tesouro Ativo: %d\n| Pontuação inicial:%d \n| Endereço da vida: %p\n\n", vida, tesouro_ativo,pontuacao_total,ptr_vida);

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
    printf("Altura Total do Percurso: %.2f metros\n \n", altura_total);

    printf("|Digite um tamanho para o mapa: (1 a 10):");
    scanf("%d5", &tamanho);

    if (tamanho <1 || tamanho> tm){
         printf("Erro, o valor deve estar entre 0 e %d\n",vm);
        return 1;
    }

    if (!ler_mapa(mapa, tamanho)) {
        printf("Entrada invalida! Encerrando...\n");
        return 1;
    }
    mostrar_mapa(mapa, tamanho);
    explorar_mapa(mapa, tamanho);
    explorar_mapa_ponteiro(mapa, tamanho);

     while (opcao != 5) {
        printf("\nMenu\n");
        printf("1. Ver Status (Vida, Pontos, Mapa)\n");
        printf("2. Alterar Status\n");
        printf("3. Ver Inventario\n");
        printf("4. Alterar Item\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n|Vida: %d | Pontos: %d | Mapa: %s\n", vida, pontuacao_total, mapao);
                break;
                   
            case 2:
                printf("|Nova Vida: ");
                scanf("%d", &vida);
                printf("|Novos Pontos: ");
                scanf("%d", &pontuacao_total);
                printf("|Novo Mapa: ");
                scanf("%s", mapao);
                break;
                
            case 3:
                mostrarporvetor(inventario, 3);
                break;
                
            case 4:
                alterarporponteiro(inventario, 3);
                break;
                
            case 5:
                printf("Saindo do menu\n");
                break;
                
            default:
                printf("Ocorreu um erro! Digite novamente\n");
        }
    }

    return 0;
     
}

