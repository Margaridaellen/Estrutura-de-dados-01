#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

typedef enum {
    ti,
    ts
} Tdado;

void mostrar (const void *ptr, Tdado tipo) {
    if (ptr == NULL) {
        printf("Ponteiro nulo.\n");
        return;
    }

switch (tipo) {
        case ti: {
            const int *p_int = (const int *)ptr;
            printf("Valor int: %d\n", *p_int);
            break;
        }
        case ts: {
            const char *p_char = (const char *)ptr;
            printf("Valor char: %c\n", *p_char);
            break;
        }
    }
}


void liberar(void **ptr_lugar) {
    if (ptr_lugar == NULL || *ptr_lugar == NULL) {
        return; }
    free(*ptr_lugar);  
    *ptr_lugar = NULL; 
}

float pontuacao (int *n, int *p){
    printf("Sua equipe participou de quantas partidas:");
    scanf("%d",p);

    if (*p > 10 || *p <= 0) {
        printf("Número de partidas inválido! Informe um valor entre 1 e 10.\n");
        return 0.0;
    }

    int * partida= (int*) malloc(*p*sizeof(*partida));
    if (partida == NULL) {
        printf("Erro \n");
        return 0;
    }

    int soma=0, maior=0, np=0;
    for(int i=0;i<*p;i++){
     partida[i]=(i+1);
   } 

    int i;
    for(i=0;i<*p;i++){
        printf("Digite a pontuação obtida na partida %d:",partida[i]);
        scanf("%d",&n[i]);
        soma += n[i];

        if(i==0|| n[i]> maior){
        maior = n[i]; 
        np=partida[i];
        }
    }
    printf("\nA média de pontução por partida: %.2f\n", (float)soma / *p);

    printf ("A maior pontuação foi: %d na posição %d",maior,np);

    free(partida);
    partida = NULL;

    return 0;
}

int main(void){ 
    char a[10],a1[30];
    char s[5],s1[5];
    char n [5][60];
    char ne[30];
    char nbusca [5][60];
    int c,l,nl,nc;
    int *pc = &c;
    int *pl = &l;
    int na,i,v;
    int x[10], p=0;; 

    printf("Digite a quantidade de jogadores:");
    scanf("%d",&na); 
    if (na <= 0 || na > 5) {
        printf("Quantidade inválida de jogadores.\n");
        return 1;
    }

    // O sizeof é utilizado para determinar o tamanho em byts que um dado ou variável ocupa na memória do computador, e evitar bugs futuros.
    int * quantidade = (int*) malloc(na*sizeof(*quantidade));

    if(quantidade==NULL){
        printf("Erro");
        exit(1);
    }
    for(int p=0;p<na;p++){
     quantidade[p]=(p+1);
   } 

    free(quantidade);
    quantidade = NULL;

    int total_jogadores = sizeof(n) / sizeof(n[0]);

     for (int i=0;i<na;i++){
      printf("Cadastro do jogador %d\n",i+1);
      printf("Digite o seu nome:");
      scanf("%s",n[i]);

      strcpy(nbusca[i], n[i]);

      printf("Ola! Para prosseguir com a aventura adote um apelido:");
      scanf("%9s",a);
      strcpy(a1,a);
      if(strlen(a)>10){
        printf("O apelido deve ter no maximo 10 caracteres");
        return 1;
    }

    printf("%s, por questoes de segurança,escolha uma senha:",a1);
    scanf("%s",s);
    printf("Digite a senha novamente:");
    scanf("%s",s1);
    
    if (strcmp (s,s1) == 0){
        printf("Cadastro realizado com sucesso!\n"); }
    else{
        printf("Erro,realize o cadastro novamente"); }
    }

    printf("Digite o nome da sua equipe:");
    scanf("%s",ne);

    for (int i = 0; i < na; i++) {
        strcat(n[i], " - "); 
        strcat(n[i], ne);   
        printf("Integrante %d: %s\n", i + 1, n[i]);
    }


    char aa[60];
    int encontrado = 0;

    printf("\nDigite apenas o nome do jogador para pesquisar: ");
    scanf("%s", aa);

    for (int i = 0; i < na; i++) {
    
        if (strcmp(nbusca[i], aa) == 0) {
            printf("Jogador %s enconntrado na posicao %d! (Cadastro completo: %s)\n\n", nbusca[i], i + 1, n[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Jogador nao encontrado.\n\n");
    }
    printf("Construindo o mapa!\n");
    printf("Digite o valor de colunas:");
    scanf("%d",&c);
    printf("Digite o valor de linhas:");
    scanf("%d",&l);

    if (l <= 0 || c <= 0) {
        printf("Dimensões inválidas.\n");
        return 1;
    }

    int m[*pl][*pc];
    int i0,j;
    for (int i0 = 0; i0 < l; i0++) {
        for (int j = 0; j < c; j++) {
            m[i0][j] = 0; 
        }
    }

    for(int i0=0;i0<*pl;i0++){
        for(int j=0;j<*pc;j++){
            printf("Digite o valor da posicao [%d][%d]:",i0,j);
            scanf("%d",&m[i0][j]);
        }
    }
    printf("Digite o valor que deseja achar:");
    scanf("%d",&v);
    for(int i0=0;i0<*pl;i0++){
        for(int j=0;j<*pc;j++){
            if(m[i0][j]==v){
                printf("O valor está na linha %d e coluna %d\n",i0+1,j+1);
            }
        }
    }
     //Verificar se a matriz está livre ou ocupada
    printf("Posiões livres ou ocupadas:\n");
    for (int i0 = 0; i0 < l; i0++) {
        for (int j = 0; j < c; j++) {
            if (m[i0][j] == 0) {
                printf(" Livre ");}
            else {printf(" Ocupada | %d \n", m[i0][j]); }
        }
    }
    char r;
    printf("Deseja altear a posição de algum jogador?(s/n):");
    scanf("%s",&r);
    if(r=='s'){
        printf("Digite a linha que deseja alterar:");
        scanf("%d",&nl);
        printf("Digite a coluna que deseja alterar:");
        scanf("%d",&nc);

        if (nl >= 1 && nl <= l && nc >= 1 && nc <= c) {
            printf("Digite o novo valor da posição [%d][%d]: ", nl, nc);
            scanf("%d", &m[nl - 1][nc - 1]);
        } else {
            printf("Posição inválida no mapa!\n");
        }
    }

    printf("Mapa final:\n");
    for (int i0 = 0; i0 < l; i0++) {
            for (int j = 0; j < c; j++) {
                if (m[i0][j] == 0) {
                    printf("[%d][%d]: Livre | \n", i0 + 1, j + 1);
                } else {
                    printf("[%d][%d]: Ocupada (Valor: %d)  | \n", i0 + 1, j + 1, m[i0][j]);
                }
            }
        }
        
        // Alocação dinâmica de memória para inteiro e char
    int *p1 = (int *)malloc(sizeof(int));
    char *p2 = (char *)malloc(sizeof(char));

    if (p1 == NULL || p2 == NULL) {
        liberar((void **)&p1);
        liberar((void **)&p2);
        return EXIT_FAILURE;
    }

    *p1 = 42;
    *p2 = 'A';

    mostrar(p1, ti);
    mostrar(p2, ts);

    liberar((void **)&p1);
    liberar((void **)&p2);

    mostrar(p1, ti); 
    liberar((void **)&p1);


    pontuacao(x,&p);
    printf("\n-Tabela de pontuação\n");
    for(int i = 0; i < p; i++) {
        printf("Partida %d: %d pontos\n", i + 1, x[i]);
    }

    return 0;
}