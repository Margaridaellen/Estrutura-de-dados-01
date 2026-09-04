#include<stdio.h>
#include<string.h>

int main(void){
    char a[10],a1[30];
    char s[5],s1[5];
    char n [5][60];
    char ne[30];
    char nbusca [5][60];

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

    return 0;

}