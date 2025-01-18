# Descrição da Tarefa 2 da Aula síncrona 14/01

Este código tem como objetivo o acionamento do LEDs por meio da comunicação Serial USB/UART utilizando a placa Bitdoglab. Para isto, foi utilizado um cabo usb e a placa Bitdoglab. Por fim, foi utilizado 5 GPIOs 11, 12 e 13 para o LED RGB e 10 e 21 para os Buzzers, e para utiliza-los basta seguir os comandos:

    printf("\t## Acionamento de LED e Buzzer pela USB ##\n");
    printf("Possui os seguintes comandos:\n");
- Aperte A para ligar o LED verde
- Aperte B para ligar o LED azul
- Aperte C para ligar o LED vermelho
- Aperte D para desligar os LEDs
- Aperte 3 para ligar todos os LEDS
- Aperte S para ativar os Buzzers por 2 segundos
- Aperte K para entrar no modo Bootloader (Função experimental: o compilador não reconhece a função de reset)

## URL do video do funcionamento do programa
