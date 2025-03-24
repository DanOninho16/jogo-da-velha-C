# 👵 Jogo das Velhas 👵

### 🎮 O Jogo Simples e Divertido que Todo Mundo Ama!

Este é o **Jogo da Velha**! Um jogo clássico para dois jogadores, onde você pode desafiar seu amigo (ou amiga) para ver quem consegue alinhar três símbolos e ser o vencedor! 🙌💥

Este código foi criado como parte de um trabalho de programação em C e tem o objetivo de aprender e aplicar conceitos de estruturas de dados, controle de fluxo e manipulação de entradas e saídas. Mas também, claro, foi feito para **se divertir**! 🎉

## O que você pode fazer

- **Jogar contra outro jogador**
- **Ver o histórico de partidas**
- **Vencer e se orgulhar**

## Como Funciona: O Passo a Passo

1. **Comece o jogo**: Escolha se deseja jogar ou ver o histórico das partidas anteriores.
2. **Jogar**: Cada jogador escolhe uma linha e uma coluna (1-3) para marcar seu símbolo no tabuleiro. O primeiro jogador usa 'X' e o segundo 'O'.
3. **Acerte e vença!**: O objetivo é alinhar 3 símbolos de forma consecutiva — seja horizontal, vertical ou diagonal. Mas se o tabuleiro for preenchido sem vencedores, o jogo empata! 😬
4. **Histórico**: Após o jogo, veja como cada jogada aconteceu, reviva os momentos de tensão e risos! 😂

## Como Jogar:

1. **Iniciar o jogo**:
   - Compile o código e execute o programa.
2. **Escolher a opção "Jogar"**:
   - Você pode escolher jogar contra seu amigo, e o programa vai alternando entre os jogadores.
3. **Escolher uma posição**:
   - Escolha a linha e a coluna (de 1 a 3) e veja seu símbolo ('X' ou 'O') aparecer no tabuleiro!
4. **Vencer ou empatar**:
   - O jogo acaba quando um dos jogadores conseguir alinhar 3 símbolos ou quando o tabuleiro estiver cheio (empate!).
5. **Ver o histórico**:
   - Depois que o jogo terminar, o histórico permite ver todas as jogadas feitas em partidas passadas. Muito legal, né? 😄

## Como Funcionar o Código: 🤓

Este código foi escrito em C e estruturado de forma bem organizada! Aqui está o que acontece em cada parte do código:

- **Funções Principais**:
  - `limparTela()`: Limpa a tela para mostrar a nova rodada do jogo. Não queremos ver a bagunça das jogadas anteriores, né? 😆
  - `exibirTab()`: Mostra o tabuleiro de forma bem bonitinha para que os jogadores vejam onde estão suas jogadas.
  - `calcularVencedor()`: Essa função é responsável por verificar se alguém conseguiu alinhar 3 símbolos (e ganhar o jogo!). 🏅
  - `adicionarPartida()`: Armazena as jogadas de cada partida no histórico, para você revisitar depois.
  - `jogar()`: Onde a magia acontece! Ela gerencia o fluxo do jogo, alterna entre os jogadores e chama as funções para exibir o tabuleiro e verificar o vencedor.
  - `verHistorico()`: Mostra as jogadas anteriores, como uma máquina do tempo para o Jogo da Velha! 🕰️
  - `menu()`: Exibe o menu principal para o jogador escolher o que fazer: jogar, ver o histórico ou sair. Super simples e direto!

- **Estruturas de Dados**:
  - `Jogada`: Representa cada jogada feita no jogo, incluindo o jogador, a posição escolhida e o número da jogada.
  - `Partida`: Armazena todas as jogadas de uma partida. Esse é o nosso "livro de registros" de todas as partidas.
  - `historico`: Guarda as partidas anteriores (máximo de 5), para que você possa sempre relembrar os momentos emocionantes! 📚

## Requisitos do Sistema:

- **Compilador**: Você pode usar o GCC ou qualquer outro compilador de C que você tenha disponível.
- **Sistema Operacional**: Funciona no Windows, Linux e até no macOS. 🖥️💻

## Como Compilar e Executar: 🚀

1. **Compilar o código**:
   Abra o terminal e use o comando para compilar o programa: gcc -o jogo_da_velha jogo_da_velha.c
   
2. **Executar o Programa**:
Depois de compilar, basta rodar o programa:
- No Windows:
  ```
  jogo_da_velha.exe
  ```
- No Linux/macOS:
  ```
  ./jogo_da_velha
  ```

## Conclusão 🎉

Esse projeto foi uma forma divertida e interessante de aprender programação C. Ele permite explorar conceitos importantes, como estruturas de dados, controle de fluxo e interação com o usuário. E claro, proporciona muito **divertimento** enquanto você joga e revê suas jogadas! 😎

A ideia é que o código seja simples, mas com muitas possibilidades de melhoria. Que tal adicionar uma IA para jogar sozinho contra o computador? Ou talvez uma interface gráfica para ficar ainda mais legal? 😍

Agora, vá lá e divirta-se com o seu **Jogo da Velha**! Que vença o melhor jogador! 😄

