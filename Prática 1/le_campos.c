#include <stdio.h>
#include <string.h>

int leia_campo(char *str, int size, FILE *fd)
{

    /*
    inicialize I com 0
    leia um caractere de ENTRADA e armazene em CH
    */

    int i = 0;
    char CH;

    CH = fgetc(fd);
    while(CH != EOF && CH != '|') {
        if(i < size-1) {

            /*
            adicione CH a string STR
            incremente I
            */

            str[i] = CH;
            i++;
        }

        /*
        leia um caractere de ENTRADA e armazene em CH
        */

        CH = fgetc(fd);
    }

    /*
    adicione ‘\0’ no final de STR // finalização de string em C
    retorne I // I armazena o comprimento do campo lido
    */

    str[i] = '\0';
    return i;
}

int main()
{
    /*
    receba o nome do arquivo na string NOME_ARQ
    abra o arquivo NOME_ARQ para leitura com o nome lógico ENTRADA
    COMP_CAMPO := leia_campo(CAMPO, TAM, ENTRADA)
    */

    char NOME_ARQ[20], CAMPO[100];
    int COMP_CAMPO, count = 1;

    printf("Insira o nome do arquivo (exemplo.txt)(max: 20 caracteres): ");
    scanf("%s", NOME_ARQ);

    FILE *ENTRADA;
    ENTRADA = fopen(NOME_ARQ, "r");

    if(ENTRADA == NULL) {
        printf("Erro ao abrir o arquivo.\n");

        return 1;
    }

    COMP_CAMPO = leia_campo(CAMPO, 100, ENTRADA);
    while(COMP_CAMPO > 0) {

        /*
        escreva a string CAMPO na saída padrão // tela
        COMP_CAMPO := leia_campo(CAMPO, TAM, ENTRADA)
        */

        printf("Campo #%d: %s\n", count, CAMPO);
        count++;
        COMP_CAMPO = leia_campo(CAMPO, 100, ENTRADA);
    }

    fclose(ENTRADA);

    return 0;
}