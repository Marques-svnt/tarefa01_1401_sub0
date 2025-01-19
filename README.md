# Projeto: Teclado Matricial com Raspberry Pi Pico

## Descrição

Este projeto utiliza um teclado matricial 4x4 conectado a um Raspberry Pi Pico para controlar LEDs e um buzzer. Cada tecla no teclado tem uma função específica, permitindo interações variadas com os periféricos conectados.

---

## Funcionalidades

- **Controle de LEDs:**
  - LED vermelho, azul e verde.
  - Todos os LEDs podem ser ligados e desligados simultaneamente.
- **Controle do buzzer:**
  - Emissão de som utilizando PWM.
- **Leitura do teclado matricial:**
  - Mapeamento de teclas e identificação precisa.

---

## Requisitos

- Raspberry Pi Pico
- Teclado matricial 4x4
- LEDs (vermelho, azul e verde)
- Buzzer
- Resistores para os LEDs
- Protoboard e cabos jumper

---

## Configuração

### Mapeamento de teclas

| Tecla | Função                              |
|-------|-------------------------------------|
| **A** | Liga o LED vermelho.               |
| **B** | Liga o LED azul.                   |
| **C** | Liga o LED verde.                  |
| **D** | Liga todos os LEDs simultaneamente.|
| **#** | Ativa o buzzer.                    |
---

## Compilação e Execução

1. Certifique-se de que o SDK do Raspberry Pi Pico está configurado no seu ambiente.
2. Compile o programa utilizando a extensão **Raspberry Pi Pico Project** no VS Code:
   - Abra o projeto no VS Code.
   - Vá até a extensão do **Raspberry pi pico project** e clique em **Compile Project**.
3. Coloque a placa em modo boot cel e copie o arquivo `main.uf2`, que está na pasta build, para o microcontrolador conectado via USB.

---

## Emulação com Wokwi

Para testar o programa sem hardware físico, você pode utilizar o **Wokwi** para emulação no VS Code:

1. Instale a extensão **Wokwi for VS Code**.
2. Inicie a emulação:
   - Clique no arquivo `diagram.json` e inicie a emulação.
4. Teste o funcionamento do programa diretamente no ambiente emulado.

---

## Colaboradores.

- [brunaalvescabral - Bruna Alves Cabral ](https://github.com/brunaalvescabral)
- [iagovirgilio - Iago Virgílio Lopes Macedo de Oliveira](https://github.com/iagovirgilio)
- [ribeiro51 - Lucas Borges Ribeiro](https://github.com/ribeiro51)
- [PauloCesar53 - Paulo César de Jesus Di Lauro ](https://github.com/PauloCesar53)
- [marques-svnt - Gabriel Marques de Andrade ](https://github.com/Marques-svnt)
- [ArieldosSantosdeCristo -Ariel dos Santos de Cristo Góes ](https://github.com/ArieldosSantosdeCristo)
- [Ma756-max - Marcelo Rick Almeida Santos](https://github.com/Ma756-max)
- [amandatsantos - Amanda Tavares Santos](https://github.com/amandatsantos)
---

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).