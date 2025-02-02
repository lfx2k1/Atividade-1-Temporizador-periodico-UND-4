# Atividade-1-Temporizador-periodico-UND-4
Repositório para atividade de temporizador periódico do programa de Sistemas Embarcados, Embarcatech.

## Descrição: 
O projeto mostra um semáforo a partir do uso de três Leds, nas cores vermelha, amarela(somente na simulação, pois na placa BitDogLab sua cor é azul) e verde. O acionamento ocorre a cada 3 segundos, onde a cor inicial é vermelha, onde é visualizada a contagem do tempo no terminal.

## Passo-a-passo
1) O acionamento dos LEDs (sinais do semáforo) inicia na cor vermelha, alterando para azul (amarela apenas na simulação do Wokwi),e, em seguida, verde;
2) O temporizador tem um atraso de 3 segundos (3.000ms) para cada mudança de cor do semáforo;
3) A mudança de estado ocorre com uso da função de call-back do temporizador, para o mesmo exemplo da rotina trabalhada no Embarcatech, cujo nome é repeating_timer_callback();
4) A rotina principal, presente no interior da estrutura de repetição while realiza a impressão de mensagem indicando o tempo passado no decorrer de execução do código.
5) Foi utilizada a Ferramenta Educacional BitDogLab, para este pojeto utilizando o LED RGB – GPIOs 11, 12 e 13.

## Utilização do programa

## 1. Pré-requisitos
Antes de rodar o programa, certifique-se de ter os seguintes itens configurados:
Placa: Raspberry Pi Pico.
Ambiente de desenvolvimento: SDK do Raspberry Pi Pico configurado (CMake, GCC ARM, etc.).
Cabo USB: Para alimentação e comunicação serial com o Raspberry Pi Pico.

## 2. Compilação e Upload
Clone este repositório:
git clone https://github.com/lfx2k1/Atividade-1-Temporizador-periodico-UND-4.git

cd Atividade-1-Temporizador-periodico-UND-4.git

Compile o código

Após a compilação, um arquivo .uf2 será gerado. Para enviá-lo ao Raspberry Pi Pico:
Conecte o Raspberry Pi Pico ao PC segurando o botão BOOTSEL.
Ele será montado como um dispositivo de armazenamento.
Copie o arquivo .uf2 gerado para dentro do Raspberry Pi Pico.

## 3. Execução
Assim que o código for carregado, os LEDs começarão a alternar no padrão de um semáforo (vermelho, amarelo, verde).
A cada segundo, uma mensagem será impressa via porta serial indicando o tempo decorrido.

