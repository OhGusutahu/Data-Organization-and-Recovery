#include <stdio.h>
#include <string.h>

int leia_reg(char str[], int size, FILE *fd)
{
    /*
    leia COMP_REG do arquivo ENTRADA // use fread
    se fim do arquivo encontrado então retorne 0
    se COMP_REG < TAM então
        leia o registro (COMP_REG bytes) para BUFFER // use fread
        adicione ‘\0’ no final de BUFFER
        retorne COMP_REG
    senão retorne 0
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

    /*
    receba o nome do arquivo na string NOME_ARQ
    abra NOME_ARQ para leitura binária com o nome lógico ENTRADA
    COMP_REG := leia_reg(BUFFER, TAM, ENTRADA)

    *enquanto* COMP_REG > 0 *faça*
        CAMPO := strtok(BUFFER, “|”)
        *enquanto* CAMPO diferente de NULL *faça*
            escreva CAMPO na saída padrão // tela
            CAMPO := strtok(NULL, “|”)
        *fim *enquanto**
        COMP_REG := leia_reg(BUFFER, TAM, ENTRADA)
    *fim *enquanto**
    feche ENTRADA
    */

    char NOME_ARQ[20], BUFFER[100], *CAMPO;
    short COMP_REG;
    int i=1, j=1;

    printf("Insira o nome do arquivo (exemplo.txt)(max: 20 caracteres): ");
    scanf("%s", NOME_ARQ);

    FILE *ENTRADA;
    ENTRADA = fopen(NOME_ARQ, "rb");

    COMP_REG = leia_reg(BUFFER, 100, ENTRADA);

    while(COMP_REG > 0) {
        printf("Registro %d\n", i);

        CAMPO = strtok(BUFFER, "|");
        while(CAMPO != NULL) {
            printf("\tCampo #%d:%s", j, CAMPO);
            CAMPO = strtok(NULL, "|");
            j++;
        }
        COMP_REG = leia_reg(BUFFER, 100, ENTRADA);
        i++;
    }

    fclose(ENTRADA);

    return 0;
}