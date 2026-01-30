# FishCare IoT 🐟🌡️

Protótipo **IoT** desenvolvido com **ESP32** para **monitoramento em tempo real da temperatura da água** em tanques de piscicultura.

Os dados são enviados para um **banco de dados usando Google Planilhas**, e o sistema sinaliza o estado da temperatura com LEDs, LED verde temperatura dentro do intervalo configurado e LED Vermelho temperatura fora do intervalo (abaixo ou acima do limite).

O **FishCare IoT** foi pensado para ajudar no acompanhamento da temperatura em piscicultura, permitindo registrar medições continuamente e armazenar o histórico na nuvem (Google Sheets), facilitando análise e tomada de decisão.


## Porque eu fiz esse projeto? 

A temperatura da água é um dos parâmetros mais críticos na piscicultura: ela influencia o metabolismo, o crescimento e a taxa de oxigenação da água, impactando diretamente a saúde e a mortalidade dos peixes. O monitoramento manual é intermitente e sujeito a falhas; já um sistema IoT oferece acompanhamento contínuo e remoto, permitindo respostas rápidas a variações climáticas e redução de perdas. 

Além de ser tecnicamente viável e de baixo custo (apenas um sensor principal), o protótipo é escalável para integrar futuramente outros tipos de componentes.


## Funcionalidades

- Leitura da temperatura da água via sensor DS18B20
- Envio de dados para **Google Planilhas** (em tempo real)
- Controle de LEDs de status:
  - Verde dentro do intervalo
  - Vermelho fora do intervalo
- Limites configuráveis diretamente no código (por enquanto)

## Tecnologias utilizadas

- **ESP32**
- **C++**
- **Arduino IDE**
- **Google Forms e Google Sheets** como banco de dados/histórico
- Wi-Fi

## Hardware

- 1x ESP32
- 1x Sensor de temperatura **DS18B20**
- 1x LED Verde + resistor 220Ω
- 1x LED Vermelho + resistor 220Ω
- 1x Tela LCD 20x4
- 1x Fonte de alimentação 5V / 2A
- Protoboard e Jumpers
