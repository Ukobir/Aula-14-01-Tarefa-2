<h1 align="center">
  <br>
    <img width="400px" src="https://github.com/user-attachments/assets/a2da68bf-9b98-4650-9953-7358a5a1bf18">
  <br>
  Microcontroladores – GPIO
  <br>
</h1>
<div align="center">
</div>

<div align="center"> 

Este código tem como objetivo o acionamento de LEDs e Buzzers através da comunicação serial USB/UART utilizando a placa **BitDogLab**. Para isso, foi utilizado um cabo USB e a placa **BitDogLab** para controlar LEDs e buzzer através de comandos enviados via terminal serial. Os pinos **GPIOs 11, 12 e 13** foram usados para os LEDs RGB, e os pinos **GPIOs 10 e 21** para os buzzers.

</div>

<details open="open">
<summary>Sumário</summary>
  
- [Componentes e Tecnologias Utilizadas](#componentes-e-tecnologias)
- [Comandos Utilizados no Terminal Serial](#comandos-e-funções)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Como Executar](#como-executar)
  - [Pré-requisitos](#pré-requisitos)
  - [Passos para Execução](#passos-para-execução)
- [Testes Realizados](#testes-realizados)
- [Vídeo Demonstração](#url-do-vídeo-demonstração)
- [Autores](#autores-do-subgrupo-3)

</details>

## Componentes e Tecnologias 

1. **LED RGB (3 LEDs – Verde, Azul e Vermelho)**: LEDs usados para indicar o estado do sistema.
2. **Componente Buzzer**: Utilizado para emitir um som quando acionado.
3. **Placa BitDogLab (versão 6.3)**
4. **Microcontrolador Raspberry Pi RP2040**: Microcontrolador que gerencia a comunicação e controle dos periféricos.
   
## Comandos e Funções

A comunicação com o sistema é feita via UART, e o código interpreta os seguintes comandos:

- Aperte A para ligar o LED verde
- Aperte B para ligar o LED azul
- Aperte C para ligar o LED vermelho
- Aperte D para desligar os LEDs
- Aperte 3 para ligar todos os LEDS
- Aperte S para ativar os Buzzers por 2 segundos
- Aperte K para entrar no modo Bootloader (Função experimental: o compilador não reconhece a função de reset)
- Aperte M para tocar uma música


## Estrutura do Projeto

- **Tarefa_2.c**: Contém a lógica principal do programa, incluindo o controle dos LEDs e do buzzer.
- **LED_Buzz.c**: Implementação das funções de controle de LEDs e buzzer.
- **features/LED_Buzz.c**: Funções para controle dos LEDs e do buzzer.

## Como Executar

### Pré-requisitos

- **VS Code** instalado.
- **Pico SDK** configurado no ambiente de desenvolvimento.
- **PuTTY** ou outro emulador de terminal para a comunicação serial.

### Passos para Execução

1. Clone este repositório para o seu ambiente local:

   ```bash
   git clone https://github.com/seu-usuario/repository.git
    ```
2. Abra o projeto no VS Code e configure o ambiente de desenvolvimento para o RP2040.
3. Compile o código e carregue na placa.
4. Utilize o PuTTY para se conectar à interface serial do microcontrolador e envie os comandos para controlar os LEDs e o buzzer.


## URL do Vídeo Demonstração
[Video demonstrativo](https://www.dropbox.com/scl/fi/2s5nzq2388ghskz4rvs7r/2025-01-19-22-59-33.mkv?rlkey=4h04r9c31ugrsk06yi9r5lnqy&st=tpek3fx8&dl=0)

## Autores do Subgrupo 3
- Naila Suele
- Leonardo Romão
- Silas Kenji de Souza
- João Vitor Moreira
- Isaias Rodrigues Mendes
