#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int input(char str[], int size)
{
    /*
    Função input() de exercício 1, programa 1
    */

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

int leia_reg(char str[], int size, FILE *fd)
{
    /*
    Função leia_reg() de exercício 1, programa 4
    */

    char BUFFER[100];
    short COMP_REG;

    if(fread(&COMP_REG, sizeof(short), 1, fd) == 0) {
        return 0;
    }
    if(COMP_REG < size) {
        fread(BUFFER, sizeof(char), COMP_REG, fd);
        BUFFER[COMP_REG] = '\0';
        return COMP_REG;
    }

    return 0;
}

int main()
{
    char NOME_ARQ[20], SOBRENOME_BUSCA[50], BUFFER[100], SOBRENOME[100], CAMPO[100];
    short COMP_REG;
    int i = 1;

    printf("Insira o nome do arquivo: ");
    scanf("%s", NOME_ARQ);

    FILE *ENTRADA;
    ENTRADA = fopen(NOME_ARQ, "rb");

    if(ENTRADA == NULL) {
        printf("\nArquivo não existe;");
    } else {
        printf("\nInsira o sobrenome a ser buscado: ");
        input(SOBRENOME_BUSCA,50);

        bool ACHOU = false;

        COMP_REG = leia_reg(BUFFER,100,ENTRADA);

        while(ACHOU == false && COMP_REG > 0) {
            strcpy(SOBRENOME,strtok(BUFFER,"|"));

            if(SOBRENOME == SOBRENOME_BUSCA) ACHOU = true;
            else COMP_REG = leia_reg(BUFFER,100,ENTRADA);
        }
        if(ACHOU == true) {
            printf("\nRegistro encontrado:\n");
            printf("\nCampo %d: %s", i, SOBRENOME);

            strcpy(CAMPO,strtok(NULL, "|"));
            while(CAMPO != NULL) {
                i++;
                printf("\nCampo %d: %s", i, CAMPO);
                strcpy(CAMPO,strtok(NULL, "|"));
            }
        } else printf("\nRegistro não encontrado");
    }
    fclose(ENTRADA);

    return 0;
}
