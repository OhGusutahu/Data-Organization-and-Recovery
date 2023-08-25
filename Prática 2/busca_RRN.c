#include <stdio.h>
#include <string.h>

// BUSCA DIRETA EM ARQUIVOS DE REGISTRO DE TAMANHO FIXO

int input(char str[], int size);

typedef struct {
    int CONT_REG;
} CABECALHO;

int main() {
    char NOME_ARQ[20], BUFFER[65];
    int RRN, OFFSET;
    CABECALHO CAB;

    // limpando BUFFER
    for (int i = 0; i < 65; i++) {
        BUFFER[i] = '\0';
    }

    printf("Insira o nome do arquivo: ");
    input(NOME_ARQ, 20);

    FILE *ENTRADA;
    ENTRADA = fopen(NOME_ARQ, "rb");

    if(ENTRADA == NULL) {
        printf("\nArquivo não existe;");
    } else {
        // leia o cabeçalho
        fread(&CAB, sizeof(CABECALHO), 1, ENTRADA);

        // leia o RRN a ser buscado
        printf("\nInsira o RRN a ser buscado no arquivo: ");
        scanf("%d", &RRN);

        if(RRN >= CAB.CONT_REG) {
            printf("Ocorreu um erro. Encerrando...");
        } else {
            // calcule o OFFSET de leitura // RRN * 64 + sizeof(CABEÇALHO)
            OFFSET = RRN * 64 + sizeof(CABECALHO);

            // faça seek para OFFSET
            fseek(ENTRADA, OFFSET, SEEK_SET);

            // leia o registro para a string BUFFER e mostre-o na tela
            fread(BUFFER, 64, 1, ENTRADA);
            printf("Registro encontrado:\n%s", BUFFER);
        }
    }
    
    fclose(ENTRADA);

    return 0;
}

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