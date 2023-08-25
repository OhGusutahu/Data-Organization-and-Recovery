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
    calcule o comprimento da string BUFFER e atribua a COMP_REG //use strlen
    escreva a variável COMP_REG no arquivo SAIDA //use fwrite
    escreva a string BUFFER no arquivo SAIDA
    */

    char NOME_ARQ[20], CAMPO[50], BUFFER[100];
    int COMPRIMENTO, i;
    short COMP_REG;

    printf("Insira o nome do arquivo (exemplo.txt)(max: 20 caracteres): ");
    scanf("%s", NOME_ARQ);

    FILE *SAIDA;
    SAIDA = fopen(NOME_ARQ, "wb");
    
    printf("Insira seu sobrenome (max: 20): ");
    fflush(stdin);
    COMPRIMENTO = input(CAMPO, 50);

    while(COMPRIMENTO > 0) {

        /*
        limpe a string BUFFER //BUFFER[0] = ‘\0’
        concatene as strings BUFFER e CAMPO //use strcat
        concatene as strings BUFFER e “|”
        */

        BUFFER[0] = '\0';

        strcat(BUFFER,CAMPO);
        strcat(BUFFER,"|");

        for(i=0; i < 5; i++) {

            /*
            receba o campo na string CAMPO
            concatene as strings BUFFER e CAMPO
            concatene as strings BUFFER e “|”
            */

            printf("Insira a informacao no campo: ");
            fflush(stdin);
            input(CAMPO,50);

            strcat(BUFFER,CAMPO);
            strcat(BUFFER,"|");
        }

        /*
        calcule o comprimento da string BUFFER e atribua a COMP_REG //use strlen
        escreva a variável COMP_REG no arquivo SAIDA //use fwrite
        escreva a string BUFFER no arquivo SAIDA
        receba o próximo sobrenome na string CAMPO e calcule o COMPRIMENTO da string
        */

        COMP_REG = strlen(BUFFER);
        fwrite(&COMP_REG, sizeof(int), 1, SAIDA);
        fwrite(BUFFER, sizeof(char), strlen(BUFFER), SAIDA);

        printf("Insira seu sobrenome (max: 20): ");
        fflush(stdin);
        COMPRIMENTO = input(CAMPO, 20);
    }

    return 0;
}