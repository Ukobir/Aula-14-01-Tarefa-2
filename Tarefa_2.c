#include "pico/stdlib.h"
#include <stdio.h>
#include "features/LED_Buzz.c"
#include "hardware/resets.h" // Necessário para usar reset_usb_boot

#define BOOT_PIN 0 // O pino GPIO 0 é utilizado para habilitar o modo de gravação

void enter_bootloader()
{
    // Coloca o pino GPIO 0 em LOW para sinalizar o modo de gravação
    gpio_init(BOOT_PIN);
    gpio_set_dir(BOOT_PIN, GPIO_OUT);
    gpio_put(BOOT_PIN, 0); // Coloca GPIO 0 em LOW
    
}

const uint gpio[3] = {11, 12, 13}; // LEDs
const uint buzz[2] = {10, 21};     // Buzzers


const int melody[] = {
    262, 294, 330, 349, 392, 440, 494, 523, 494, 440, 392, 349, 330, 294, 262, 294, 330, 349, 392, 440, 494, 523, 494, 440, 392
};

const int noteDurations[] = {
    200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200
};


int main()
{
    initLed(gpio, buzz);  // Inicializa o LED como saída
    stdio_init_all();
    waitUSB(); // Função que espera a conexão USB
    menu();

    while (true)
    {
        char input;
        scanf("%c", &input);

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
        case 'M': 
        case 'm':
            printf("Tocando a música...\n");
            playMelodyPWM(melody, noteDurations, sizeof(melody) / sizeof(melody[0]), buzz[1]);
            break;
        case 'K':
        case 'k':
            printf("Iniciando o modo de gravação...\n");
            sleep_ms(2000);
            enter_bootloader();
            while (true)
            {
                printf("\tEsperando apertar o reset\n");
                sleep_ms(5e3);
            }
            break;
        default:
            break;
        }
        sleep_ms(100);
    }
    return 0;
}
