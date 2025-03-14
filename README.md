# Projeto: Simulação de Lâmpada com Controle de Intensidade via Joystick

## Descrição
Este projeto simula uma lâmpada cuja intensidade de luz pode ser controlada utilizando um joystick analógico. A simulação é realizada em um Raspberry Pi Pico, onde um LED RGB representa a lâmpada e o joystick ajusta a intensidade da luz emitida.

## Componentes Utilizados
- Raspberry Pi Pico
- LED RGB
- Joystick analógico
- Resistores de 1kΩ

## Funcionamento
1. **Inicialização**: O Raspberry Pi Pico é configurado para utilizar PWM (Pulse Width Modulation) nos pinos conectados ao LED RGB.
2. **Leitura do Joystick**: O valor analógico do joystick é lido através do ADC (Conversor Analógico-Digital) do Pico.
3. **Ajuste da Intensidade**: O valor lido do joystick é mapeado para um ciclo de trabalho PWM, ajustando a intensidade do LED RGB.
4. **Exibição**: A intensidade do LED RGB muda conforme a posição do joystick, simulando o controle de uma lâmpada.

## Diagrama de Conexões
O diagrama de conexões pode ser encontrado no arquivo `diagram.json`, que detalha como os componentes estão conectados ao Raspberry Pi Pico.

## Código
O código fonte do projeto está no arquivo `pp.c`. Ele inclui a configuração dos pinos, leitura do joystick e ajuste da intensidade do LED RGB.

## Como Executar
1. Clone o repositório.
2. Configure o ambiente de desenvolvimento para o Raspberry Pi Pico.
3. Compile o projeto utilizando CMake.
4. Carregue o binário gerado no Raspberry Pi Pico.
5. Conecte os componentes conforme o diagrama de conexões.
6. Execute o código e utilize o joystick para controlar a intensidade do LED RGB.

## Autor
Autor: Pedro Sérgio Martins Lima 
