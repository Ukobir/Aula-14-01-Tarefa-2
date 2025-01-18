#include "pico/stdlib.h"
#include <stdio.h>
#include "features/LED_Buzz.c"
#include "hardware/resets.h" // Incluir o cabeçalho necessário para usar reset_usb_boot

#define BOOT_PIN 0 // O pino GPIO 0 é utilizado para habilitar o modo de gravação

void enter_bootloader()
{
    // Coloca o pino GPIO 0 em LOW para sinalizar o modo de gravação
    gpio_init(BOOT_PIN);
    gpio_set_dir(BOOT_PIN, GPIO_OUT);
    gpio_put(BOOT_PIN, 0); // Coloca GPIO 0 em LOW
    
}

const uint gpio[3] = {11, 12, 13}; // Pino do LED integrado no Raspberry Pi Pico
const uint buzz[2] = {10, 21};


int main()
{
    initLed(gpio, buzz); // Inicializa o LED como saída
    // Garante que o LED comece apagado

    // Inicializa a comunicação serial USB
    stdio_init_all();
    waitUSB(); // Função que espera a conexão USB
    menu();

    // Loop principal
    while (true)
    {
        char input;
        // Lê um caractere digitado no terminal usando scanf
        scanf("%c", &input); // Usa scanf para capturar o caractere

        switch (input)
        {
        case 'A':
        case 'a':
            ligaGPIO(gpio[0]);
            break;
        case 'B':
        case 'b':
            ligaGPIO(gpio[1]);

            break;
        case 'C':
        case 'c':
            ligaGPIO(gpio[2]);

            break;
        case 'D':
        case 'd':
            for (uint i = 0; i < 3; i++)
            {
                desligaGPIO(gpio[i]);
            }
            break;
        case '3':
            for (uint i = 0; i < 3; i++)
            {
                ligaGPIO(gpio[i]);
            }
            break;
        case 'S':
        case 's':
            Bip(buzz);
            break;
        case 'K':
        case 'k':
            printf("Iniciando o modo de gravação...\n");

            // Aguarda 2 segundos para a mensagem ser visível
            sleep_ms(2000);

            // Entra no modo de gravação
            enter_bootloader();

            // O código não deve continuar daqui, pois o RP2040 será reiniciado no modo de bootloader
            while (true)
            {
                printf("\tEsperando apertar o reset\n"); // Loop infinito para garantir que o código não continue após o reset
                sleep_ms(5e3);
            }
            break;

        default:
            break;
        }
        // Pequeno delay para evitar loop rápido sem necessidade
        sleep_ms(100);
    }

    return 0;
}
