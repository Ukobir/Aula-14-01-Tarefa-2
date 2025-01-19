#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Função para iniciar os LEDS e Buzzer
void initLed(const uint gpio[3], const uint buzz[2])
{
    for (uint i = 0; i < 3; i++)
    {
        gpio_init(gpio[i]);
        gpio_set_dir(gpio[i], GPIO_OUT);
        gpio_put(gpio[i], 0);
    }
    for (uint i = 0; i < 2; i++)
    {
        gpio_init(buzz[i]);
        gpio_set_dir(buzz[i], GPIO_OUT);
        gpio_put(buzz[i], 0);
    }
}

// Função para ligar os LEDS e Buzzer
void ligaGPIO(uint gpio)
{
    gpio_put(gpio, 1);
}

void desligaGPIO(uint gpio)
{
    gpio_put(gpio, 0);
}

void Bip(const uint gpio[2]) {
    for (uint i = 0; i < 10; i++)
    {
        ligaGPIO(gpio[0]);
        ligaGPIO(gpio[1]);
        sleep_ms(100);
        desligaGPIO(gpio[0]);
        desligaGPIO(gpio[1]);
        sleep_ms(100);
    }
    
}

// função para inicializar o pwm 
void initPWM(uint pin)
{
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f); 
    pwm_init(slice_num, &config, true);
}

// aqui e para tocar uma nota em uma frequência específica
void playTone(uint pin, int freq, int duration_ms)
{
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_gpio_level(pin, 32768);               
    pwm_set_wrap(slice_num, 125000000 / freq);   // aqui eh pra configurar a frequencia
    sleep_ms(duration_ms);
    pwm_set_gpio_level(pin, 0);                
}


void playMelodyPWM(const int *melody, const int *durations, int length, uint buzzerPin)
{
    initPWM(buzzerPin);
    for (int i = 0; i < length; i++)
    {
        if (melody[i] > 0)
        {
            playTone(buzzerPin, melody[i], durations[i]);
        }
        sleep_ms(100); 
    }
}


void waitUSB() {
     printf("Aguardando a comunicação USB...\n");

    // Espera até que a comunicação USB esteja conectada
    while (!stdio_usb_connected())
    {
        // O dispositivo USB ainda não foi conectado
        sleep_ms(100); // Espera 100ms antes de checar novamente
    }

    // Quando a comunicação USB for detectada, a execução continua
    printf("Comunicação USB detectada!\n");
}

void menu()
{
    // Exibe uma mensagem inicial no terminal
    printf("\t## Acionamento de LED e Buzzer pela USB ##\n");
    printf("Possui os seguintes comandos:\n");
    printf("1 - Aperte A para ligar o LED verde\n");
    printf("2 - Aperte B para ligar o LED azul\n");
    printf("3 - Aperte C para ligar o LED vermelho\n");
    printf("4 - Aperte D para desligar os LEDs\n");
    printf("5 - Aperte 3 para ligar todos os LEDS\n");
    printf("6 - Aperte S para ativar os Buzzers por 2 segundos\n");
    printf("7 - Aperte K para entrar no modo Bootloader\n");
    printf("8 - Aperte M para tocar uma música\n");
}