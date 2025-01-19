Controle Interativo de LEDs e Buzzer com Raspberry Pi Pico
Este projeto foi desenvolvido para o Raspberry Pi Pico, utilizando LEDs e um buzzer. A ideia principal é controlar os LEDs (verde, azul e vermelho) e o buzzer de forma simples, através de comandos no terminal serial. O código foi projetado para ser fácil de entender e expandir, enquanto oferece uma interface intuitiva para interação.

Com esse projeto, você aprenderá como usar os GPIOs do Raspberry Pi Pico para controlar LEDs e um buzzer, além de criar uma maneira simples de interagir com o hardware por meio de um terminal serial.

🚀 Funcionalidades
Controle de LEDs: Acenda e apague individualmente os LEDs (verde, azul e vermelho).
Controle Simples: A interação acontece via comandos digitados no terminal serial.
Feedback Sonoro: Acione o buzzer para fornecer um som de confirmação.
Comandos de Controle: Menu interativo para controlar todos os dispositivos.
Simulação: Teste o código no Wokwi ou em hardware real.
📦 Requisitos
Hardware
Raspberry Pi Pico
LEDs (verde, azul e vermelho)
Resistor de 1kΩ (para cada LED)
Buzzer
Software
Arduino IDE ou VS Code com a extensão Pico SDK configurada.
Simulador de Circuitos (opcional, recomendado usar Wokwi para testar sem hardware real).
Dependências
O projeto utiliza o Pico SDK para compilar o código para o Raspberry Pi Pico. O SDK pode ser instalado diretamente no seu ambiente de desenvolvimento (veja documentação do Raspberry Pi Pico).

⚙️ Como Usar
Passo 1: Configuração do Ambiente de Desenvolvimento
Instale o Arduino IDE ou VS Code com a extensão Pico SDK.

Para configurar o ambiente de desenvolvimento, siga os passos descritos na documentação oficial do Raspberry Pi Pico.
Clone este repositório ou baixe os arquivos.

Abra o projeto no seu editor de código (Arduino IDE ou VS Code).

Passo 2: Carregar o Código
Conecte o seu Raspberry Pi Pico ao computador.
Compile o código e faça o upload para o Pico.
O código começará a rodar automaticamente no seu Raspberry Pi Pico.
Passo 3: Simulação (Opcional)
Se não tiver o hardware disponível, você pode simular o projeto no Wokwi.

Acesse o link da simulação no Wokwi.
Importe o arquivo .uf2 ou o código diretamente na plataforma.
Teste os comandos no simulador para ver os LEDs e o buzzer em ação.
Passo 4: Comandos no Terminal Serial
Após carregar o código no Raspberry Pi Pico, abra o terminal serial. Você verá um menu interativo onde poderá digitar os comandos para controlar os LEDs e o buzzer.

📋 Comandos Disponíveis
Aqui estão os comandos que você pode usar para controlar os LEDs e o buzzer através do terminal serial. Cada comando foi projetado para ser simples e direto, permitindo uma interação fácil com o seu Raspberry Pi Pico.

Comando	Descrição
LED_GREEN	Liga o LED verde. 🌿
LED_BLUE	Liga o LED azul. 🌊
LED_RED	Liga o LED vermelho. 🔴
ALL_ON	Liga todos os LEDs ao mesmo tempo (cor branca). 💡
ALL_OFF	Desliga todos os LEDs. ❌
BUZZER	Aciona o buzzer por 2 segundos para um feedback sonoro. 🎶
REBOOT	Reinicia o Raspberry Pi Pico, reiniciando todo o sistema. 🔄
HELP	Exibe a lista de todos os comandos disponíveis. 📜
Como Funciona?
Comandos de Controle:

LED_GREEN: Quando você digita esse comando, o LED verde acende, como uma luz de confirmação verde para mostrar que seu comando foi reconhecido! 🌿
LED_BLUE: Para um toque refrescante, o LED azul se acende com o comando LED_BLUE. 🌊
LED_RED: Precisa de um alerta? O LED vermelho vai ser o seu aviso! 🔴
Acione Todos ao Mesmo Tempo:

ALL_ON faz todos os LEDs acenderem juntos, criando uma luz branca. Uma ótima forma de iluminar a área ao mesmo tempo! 💡
ALL_OFF desliga todos os LEDs quando você precisar de um descanso.
Feedback Sonoro:

BUZZER aciona o buzzer por 2 segundos, permitindo que você ouça um som como confirmação ou alarme sonoro. 🎶
Reinicie o Sistema:

Caso precise reiniciar, é só usar REBOOT. Esse comando reinicia o Raspberry Pi Pico, e o código vai começar do zero! 🔄
Ajuda:

Se você esquecer algum comando ou não souber o que fazer, use o comando HELP. Ele vai exibir todos os comandos disponíveis para você!
Exemplo de Uso
Passo 1: Conecte seu Raspberry Pi Pico e abra o terminal serial.
Passo 2: Digite HELP para ver a lista de comandos.
Passo 3: Experimente acionar LED_GREEN, depois tente BUZZER para um som de confirmação!
🧑‍💻 Estrutura do Código
O código foi organizado de forma modular, permitindo fácil entendimento e expansão. As principais funções incluem:

Lig_Led_Green(): Acende o LED verde e desliga os outros.
Lig_Led_B(): Acende o LED azul e desliga os outros.
Função main(): Onde a interação com o usuário acontece, permitindo o controle dos LEDs e buzzer através de comandos no terminal.
🔧 Como Contribuir
Contribuições são bem-vindas! Se você encontrar bugs, tiver sugestões de melhorias ou quiser adicionar novas funcionalidades, fique à vontade para fazer um fork deste repositório e abrir um pull request.

