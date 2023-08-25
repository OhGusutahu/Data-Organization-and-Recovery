#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

/**
 * Este é a interface (header) que descreve um TAD de uma LED
 * Essa LED utiliza a estratégia worst-fit
 * Feito por Gustavo Giozeppe Bulgarelli
**/

typedef struct reg *ponteiro; /* Tipo exportado */

typedef struct LED LED; /* Tipo exportado */

LED* cria_led();
/* Cria a LED inicializando todos os dados necessários para seu gerenciamento */

int inserir_led(LED *led, ponteiro x);
/* Insere o registro x na LED
   Retorna 1 em caso de sucesso e 0 caso contrário
*/

int remover_led(LED *led, ponteiro *x);
/* Remove a cabeça da LED para inserção no arquivo
   Retorna 1 em caso de sucesso e 0 caso contrário
*/

void imprimir_led(LED *led);
/* Imprime os offsets dos espaços disponíveis que estão encadeados na LED */

void destruir_led(LED *led);
/* Libera a memória alocada pela LED */

#endif // LED_H_INCLUDED