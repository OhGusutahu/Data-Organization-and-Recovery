#include <stdio.h>
#include <string.h>

int input(char str[], int size)
{
    int i = 0;
    char c = getchar();
    while (c != '\n') {
        if (i < size-1) {
            str[i] = c;
            i++;
        }
        c = getchar();
    }
    str[i] = '\0';
    return i;
}

int main()
{
    /*
    receba o nome do arquivo a ser criado na string NOME_ARQ
    abra o arquivo NOME_ARQ para escrita com o nome lógico SAIDA
    receba o sobrenome na string SOBRENOME e calcule o seu COMPRIMENTO
    */

    char NOME_ARQ[20]; char sobrenome[20]; char nome[20]; char endereco[50]; char cidade[20]; char estado[5]; char cep[10];
    int COMPRIMENTO;

    printf("Insira o nome do arquivo (exemplo.txt)(max: 20 caracteres): ");
    scanf("%s", NOME_ARQ);

    FILE *SAIDA;
    SAIDA = fopen(NOME_ARQ, "w");

    printf("Insira seu sobrenome (max: 20): ");
    fflush(stdin);
    COMPRIMENTO = input(sobrenome, 20);

    while(COMPRIMENTO > 0) {

        /*
        receba nome, endereço, cidade, estado e cep nas strings NOME, ENDERECO, CIDADE, ESTADO e CEP, respectivamente
        escreva a string SOBRENOME no arquivo SAIDA
        escreva “|” no arquivo SAIDA
        escreva a string NOME no arquivo SAIDA
        escreva “|” no arquivo SAIDA
        escreva a string ENDERECO no arquivo SAIDA
        escreva “|” no arquivo SAIDA
        escreva a string CIDADE no arquivo SAIDA
        escreva “|” no arquivo SAIDA
        escreva a string ESTADO no arquivo SAIDA
        escreva “|” no arquivo SAIDA
        escreva a string CEP no arquivo SAIDA
        escreva “|” no arquivo SAIDA
        receba o próximo sobrenome na string SOBRENOME e calcule o COMPRIMENTO
        */
        printf("Insira seu nome (max: 20): ");
        fflush(stdin);
        //fgets(nome,20,stdin);
        //nome[strlen(nome)-1]='\0';
        input(nome,20);

        printf("Insira seu endereco (max: 30): ");
        fflush(stdin);
        //fgets(endereco,50,stdin);
        //endereco[strlen(endereco)-1]='\0';
        input(endereco,50);

        printf("Insira sua cidade (max: 10): ");
        fflush(stdin);
        //fgets(cidade,20,stdin);
        //cidade[strlen(cidade)-1]='\0';
        input(cidade,20);

        printf("Insira seu Estado (sigla) (max: 2): ");
        fflush(stdin);
        //fgets(estado,5,stdin);
        //estado[strlen(estado)-1]='\0';
        input(estado,5);

        printf("Insira seu CEP (max: 10): ");
        fflush(stdin);
        //fgets(cep,20,stdin);
        //cep[strlen(cep)-1]='\0';
        input(cep,20);

        fprintf(SAIDA, "%s|%s|%s|%s|%s|%s\n", sobrenome, nome, endereco, cidade, estado, cep);
        // Por algum motivo, fprintf nem printf, nessa situação, não printa a string cidade
        // Tentei mudar de posição, nome, de um fprintf para vários e a situação consiste

        printf("Insira seu sobrenome: ");
        fflush(stdin);
        COMPRIMENTO = input(sobrenome, 20);
    }

    fclose(SAIDA);

    return 0;
}
