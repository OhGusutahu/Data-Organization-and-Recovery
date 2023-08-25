#include <stdio.h>
#include <string.h>

int input(char str[], int size);

typedef struct {
    int CONT_REG;
} CABECALHO;

int main() {
    char NOME_ARQ[50], CAMPO[20], BUFFER[65], ALTERAR;
    int OPCAO, OFFSET, RRN;
    CABECALHO CAB;

    printf("Insira o nome do arquivo: ");
    scanf("%s", NOME_ARQ);

    FILE *ARQ;
    ARQ = fopen(NOME_ARQ, "r+");
    if(ARQ == NULL) {
        ARQ = fopen(NOME_ARQ, "w+");
        // faça CAB.CONT_REG = 0 e escreva-o em ARQ
        CAB.CONT_REG = 0;
        fwrite(CAB.CONT_REG, sizeof(CABECALHO), 1, ARQ);

    } else {
        // leia o cabeçalho de ARQ e armazene-o em CAB
        fread(&CAB, sizeof(CABECALHO), 1, ARQ);
    }
    printf("O que deseja fazer?\n(1)inserir\n(2)buscar/atualizar\n(3)sair\n");
    printf("Digite sua escolha: ");
    scanf("%d", OPCAO);

    while(OPCAO < 3) {
        switch(OPCAO) {
            case 1:
                // limpando BUFFER
                for (int i = 0; i < 65; i++) {
                    BUFFER[i] = '\0';
                }

                // leia os campos do registro // sobrenome, nome, etc
                printf("Insira os dados para o novo registro (max total: 64):\n1. Sobrenome\n2.Nome\n3.Endereco\n4.Cidade\n5.Estado\n6.CEP\n\n");
                for(int i=0; i < 6; i++) {
                printf("Insira a informacao %d no campo: ", i+1);
                fflush(stdin);
                input(CAMPO,20);

                // concatene os campos e delimitadores na string BUFFER
                strcat(BUFFER,CAMPO);
                strcat(BUFFER,"|");
                }
                
                // calcule o OFFSET de gravação
                OFFSET = CAB.CONT_REG * 64 + sizeof(CABECALHO);

                // faça seek para OFFSET e escreva BUFFER em ARQ
                fseek(ARQ, OFFSET, SEEK_SET);
                fwrite(BUFFER, sizeof(char), strlen(BUFFER), ARQ);

                // incremente CAB.CONT_REG
                CAB.CONT_REG++;
            break;
            case 2:
                // calcule o OFFSET de leitura // RRN * 64 + sizeof(CABEÇALHO)
                OFFSET = RRN * 64 + sizeof(CABECALHO);
                // faça seek para OFFSET
                fseek(ARQ, OFFSET, SEEK_SET);
                // leia o registro para a string BUFFER e mostre-o na tela
                fread(BUFFER, 64, 1, ARQ);
                printf("Registro encontrado:\n%s", BUFFER);

                // leia a opção ALTERAR
                printf("Deseja modificar esse registro? (S = sim, N = não): ");
                scanf("%c", ALTERAR);
                if((ALTERAR == 'S') || (ALTERAR == 's')) {
                    // limpando BUFFER
                    for (int i = 0; i < 65; i++) {
                        BUFFER[i] = '\0';
                    }

                    // leia os campos do registro // sobrenome, nome, etc
                    printf("Insira os dados para o novo registro (max total: 64):\n1. Sobrenome\n2.Nome\n3.Endereco\n4.Cidade\n5.Estado\n6.CEP\n\n");
                    for(int i=0; i < 6; i++) {
                    printf("Insira a informacao %d no campo: ", i+1);
                    fflush(stdin);
                    input(CAMPO,20);

                    // concatene os campos e delimitadores na string BUFFER
                    strcat(BUFFER,CAMPO);
                    strcat(BUFFER,"|");

                    // faça seek para OFFSET e escreva BUFFER em ARQ
                    fseek(ARQ, OFFSET, SEEK_SET);
                    fwrite(BUFFER, sizeof(char), strlen(BUFFER), ARQ);
                    }
                }
            break;
        }
        printf("O que deseja fazer?\n(1)inserir\n(2)buscar/atualizar\n(3)sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", OPCAO);
    }

    // faça seek para o início de ARQ
    fseek(ARQ, 0, SEEK_SET);

    // escreva CAB em ARQ
    fseek(ARQ, 0, SEEK_SET);
    fwrite(CAB.CONT_REG, sizeof(CABECALHO), 1, ARQ);

    fclose(ARQ);

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