#include<stdio.h>
#include<string.h>

    int main(void){
    char a[10],a1[30];
    char s[5],s1[5];
    char n [5][60];
    char ne[30];
    char nbusca [5][60];
    int c,l,nl,nc;
    int *pc = &c;
    int *pl = &l;
    int v;

    int total_jogadores = sizeof(n) / sizeof(n[0]);

     for (int i=0;i<5;i++){
      printf("Cadastro do jogador %d\n",i+1);
      printf("Digite o seu nome:");
      scanf("%s",n[i]);

      strcpy(nbusca[i], n[i]);

      printf("Ola! Para prosseguir com a aventura adote um apelido:");
      scanf("%s",a);
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

    for (int i = 0; i < 5; i++) {
        strcat(n[i], " - "); 
        strcat(n[i], ne);   
        printf("Integrante %d: %s\n", i + 1, n[i]);
    }

    char aa[60];
    int encontrado = 0;

    printf("\nDigite apenas o nome do jogador para pesquisar: ");
    scanf("%s", aa);

    for (int i = 0; i < 5; i++) {
    
        if (strcmp(nbusca[i], aa) == 0) {
            printf("Jogador %s enconntrado na posicao %d! (Cadastro completo: %s)\n\n", nbusca[i], i + 1, n[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Jogador nao encontrado.\n\n");
    }

    printf("Digite o valor de colunas:");
    scanf("%d",&c);
    printf("Digite o valor de linhas:");
    scanf("%d",&l);

    int m[*pl][*pc];
    int i,j;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = 0; 
        }
    }

    for(int i=0;i<*pl;i++){
        for(int j=0;j<*pc;j++){
            printf("Digite o valor da posicao [%d][%d]:",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    printf("Digite o valor que deseja achar:");
    scanf("%d",&v);
    for(int i=0;i<*pl;i++){
        for(int j=0;j<*pc;j++){
            if(m[i][j]==v){
                printf("O valor está na linha %d e coluna %d\n",i+1,j+1);
            }
        }
    }
     //Verificar se a matriz está livre ou ocupada
    printf("Posiões livres ou ocupadas:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (m[i][j] == 0) {
                printf(" Livre ");}
            else {printf(" Ocupada | %d \n", m[i][j]); }
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
        printf("Digite o novo valor da posição [%d][%d]:",nl,nc);
        scanf("%d",&m[nl-1][nc-1]);
    }

    printf("Mapa final:\n");
    for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                if (m[i][j] == 0) {
                    printf("[%d][%d]: Livre | \n", i + 1, j + 1);
                } else {
                    printf("[%d][%d]: Ocupada (Valor: %d)  | \n", i + 1, j + 1, m[i][j]);
                }
            }
        }
        
    
    return 0;

}