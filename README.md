# Atividade 2: Temporizador de um Disparo (One Shot)

Este projeto implementa um sistema de temporização para acionamento de LEDs utilizando a função `add_alarm_in_ms()` do Pico SDK. O acionamento ocorre a partir do clique em um botão (pushbutton), seguindo os requisitos especificados na atividade.

## Componentes Utilizados

1. Microcontrolador Raspberry Pi Pico W
2. 03 LEDs (azul, vermelho e verde)
3. 03 Resistores de 330 Ω
4. Botão (Pushbutton)

## Funcionamento

- Ao pressionar o botão, todos os LEDs são ligados simultaneamente.
- Após 3 segundos, um LED é apagado.
- Após mais 3 segundos, o segundo LED é apagado.
- Após mais 3 segundos, o último LED é apagado.
- O botão só pode ser pressionado novamente após todos os LEDs serem desligados.
- Foi implementado um mecanismo de debounce por software para evitar múltiplos acionamentos involuntários do botão.

## Requisitos Atendidos

1. O botão inicia a sequência de acionamento dos LEDs.
2. O temporizador do alarme é ajustado para um atraso de 3 segundos entre as mudanças de estado dos LEDs.
3. A mudança de estado dos LEDs foi implementada em funções de call-back do temporizador.
4. O botão só pode ser acionado novamente após a conclusão total da sequência de desligamento dos LEDs.
5. Foi realizado um experimento utilizando a Ferramenta Educacional BitDogLab com os GPIOs:
   - LED Azul: GPIO 13
   - LED Vermelho: GPIO 12
   - LED Verde: GPIO 11
   - Botão A: GPIO 5
6. (Opcional) Implementado debounce por software para mitigar o efeito bouncing no botão.

## Como Compilar e Executar

1. Clone ou baixe este repositório.
2. Configure o ambiente de desenvolvimento do Raspberry Pi Pico W com CMake e o SDK.
3. Compile o código usando os seguintes comandos (ou através da extensão do VS Code):
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```
4. Carregue o arquivo `.uf2` gerado no Raspberry Pi Pico W.
5. Utilize o terminal serial do VS Code para visualizar as mensagens de depuração.

## Testes e Validação

- Teste de acionamento dos LEDs em sequência.
- Teste do tempo de atraso entre as mudanças de estado.
- Teste do debounce do botão.
- Teste de bloqueio do botão durante a execução do temporizador.
- Teste com a Ferramenta BitDogLab.

## Autor

Leonardo Luz - Aluno do Embarcatech
