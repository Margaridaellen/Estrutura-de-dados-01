#include<stdio.h>
#include<string.h>

int main(void){
    char a[10], s[5], s1[5],n[30];

    printf("Digite o seu nome:");
    scanf("%[^\n]",n);

    printf("Ola! Para prosseguir com a aventura adote um apelido:");
    scanf("%s",a);
    if(strlen(a)>10){
        printf("O apelido deve ter no maximo 10 caracteres");
        return 1;
    }

    printf("%s, por questoes de segurança,escolha uma senha:",a);
     scanf("%s",s);
    printf("Digite a senha novamente:");
    scanf("%s",s1);
    
    if (strcmp (s,s1) == 0){
        printf("Cadastro realizado com sucesso!");
    }
    else{
        printf("Erro,realize o cadastro novamente");
    }
}