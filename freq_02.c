#include <stdio.h>
#include "pico/stdlib.h" // Biblioteca padrão para funcionalidades básicas como GPIO, temporização e E/S.
#include "pico/time.h"   // Biblioteca para gerenciamento de tempo, como manipulação de temporizadores e atrasos.

#define LED_PIN_RED 13 //Definição da GPIO de saída para o led vermelho
#define LED_PIN_GREEN 11 // Definição da GPIO de saída para o led verde
#define LED_PIN_YELLOW 12 //Definição da GPIO de saída para o led amarelo

// Variável para rastrear o estado atual do semáforo
int estado_atual = 0;
int conta_tempo = 0; // Variável para contar os segundos

bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna o estado do semáforo a cada 3 segundos
    estado_atual = (estado_atual + 1) % 3;
    
    switch (estado_atual) {
        case 0:
            // Liga LED vermelho, desliga LEDs amarelo e verde
            gpio_put(LED_PIN_RED, true);
            gpio_put(LED_PIN_YELLOW, false);
            gpio_put(LED_PIN_GREEN, false);
            printf("LED vermelho ligado - %d segundos se passaram\n", conta_tempo);
            break;
        case 1:
            // Liga LED amarelo, desliga LEDs vermelho e verde
            gpio_put(LED_PIN_RED, false);
            gpio_put(LED_PIN_YELLOW, true);
            gpio_put(LED_PIN_GREEN, false);
            printf("LED amarelo ligado - %d segundos se passaram\n", conta_tempo);
            break;
        case 2:
            // Liga LED verde, desliga LEDs vermelho e amarelo
            gpio_put(LED_PIN_RED, false);
            gpio_put(LED_PIN_YELLOW, false);
            gpio_put(LED_PIN_GREEN, true);
            printf("LED verde ligado - %d segundos se passaram\n", conta_tempo);
            break;
    }
    
    return true; // Retorna true para manter o temporizador ativo
}

// Função de callback para contar segundos continuamente
bool second_timer_callback(struct repeating_timer *t) {
    conta_tempo ++; // Acrescenta o contador
    printf("Se passaram %d segundos \n", conta_tempo); // Mostra quantos segundos se passaram
    return true; // Mantém o temporizador ativo
}

int main() {

    stdio_init_all(); // Inicializa a comunicação serial

    // Inicializar os pinos GPIO
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, true);

    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, true);

    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, true);

    // Inicialmente liga o LED vermelho, desliga LEDs amarelo e verde
    gpio_put(LED_PIN_RED, true);
    gpio_put(LED_PIN_YELLOW, false);
    gpio_put(LED_PIN_GREEN, false);

    // Define um intervalo de tempo em milissegundos
    uint32_t interval = 3000;

    // Inicializa o temporizador com a função repeating_timer_callback para o semáforo
    struct repeating_timer timer1;
    add_repeating_timer_ms(interval, repeating_timer_callback, NULL, &timer1);

    // Inicializa o temporizador com a função second_timer_callback para contar segundos
    struct repeating_timer timer2;
    add_repeating_timer_ms(1000, second_timer_callback, NULL, &timer2);

    // Loop infinito que mantém o programa em execução contínua
    while (true) {
    }
}