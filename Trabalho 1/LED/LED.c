#include <stdio.h>
#include <stdlib.h>
#include "LED.h"

typedef struct reg *ponteiro;

struct reg{
    int offset; // offset do registro inserido
    int tam_reg; // tamanho do registro
    ponteiro prox; // próximo registro na LED
};

struct LED {
    ponteiro cabeca; // cabeça da LED
    int tam; // tamanho da LED
};

LED* cria_led()
{
    LED *led = (LED *) malloc(sizeof(LED));
    led->cabeca = NULL;
    led->tam = 0;
    return led;
}

int inserir_led(LED *led, ponteiro x)
{
    if(led == NULL) {
        printf("LED não existe!");
        return 0;
    } else {
        if(led->tam == 0 || x->tam_reg > led->cabeca->tam_reg) {
            // inserção em LED vazia ou se tam_reg for maior que a cabeça
            x->prox = led->cabeca;
            led->cabeca = x;
        }
        else {
            // inserção em LED não vazia com tam_reg menor que a cabeça
            ponteiro pos, antes;
            antes = led->cabeca;
            while(pos!=NULL && pos->tam_reg > x->tam_reg) {
                pos = antes;
                antes = antes->prox;
            }
            x->prox = pos;
            antes->prox = x;
        }
        return 1;
    }
}

int remover_led(LED *led, ponteiro *x)
{
    if(led->cabeca == NULL) return 0; // LED está vazia
    else {
        // remove a cabeça da LED
        ponteiro aux = led->cabeca;
        *x = led->cabeca;
        led->cabeca = aux->prox;
        led->tam--;
        return 1;
    }
}

void imprimir_led(LED *led)
{
    printf("\n\n LED -> ");
    ponteiro pos = led->cabeca;
    while(pos != NULL) {
        printf("[offset: %d, tam: %d] ->", pos->offset, pos->tam_reg);
        pos = pos->prox;
    }
    printf("[offset: -1]");
    printf("\nTotal: %d espacos disponiveis", led->tam);
}

void destruir_led(LED *led)
{
    ponteiro pos = led->cabeca;
    while(pos != NULL) {
        led->cabeca = pos->prox;
        free(pos);
        pos = led->cabeca;
    }
    free(led);
}