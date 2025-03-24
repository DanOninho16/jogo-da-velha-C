#include <stdio.h>
#include <stdlib.h>

// Definindo o número máximo de jogadas e partidas
#define MAX_JOGADAS 9
#define MAX_PARTIDAS 5

// Definindo o comando para limpar a tela de acordo com o sistema operacional
#ifdef _WIN32
    #define LIMPAR_TELA "cls" 
// Para sistemas Windows
#else
    #define LIMPAR_TELA "clear" 
// Para sistemas Unix-like (Linux, macOS)
#endif

// Declarando uma função para limpar a tela do console
void limparTela() {
    system(LIMPAR_TELA);
}

// Estrutura para armazenar informações sobre uma jogada
typedef struct {
    int jogada;    // Número da jogada (1 a 9)
    int posicao;   // Posição no tabuleiro (0 a 8)
    char jogador;  // Identificação do jogador ('X' ou 'O')
} Jogada;

// Estrutura para armazenar informações sobre uma partida
typedef struct {
    Jogada jogadas[MAX_JOGADAS]; // Vetor de jogadas realizadas na partida
    int num_jogadas;             // Número de jogadas realizadas
} Partida;

// Histórico de partidas jogadas, com limite de 5 partidas
Partida historico[MAX_PARTIDAS];
int num_partidas = 0; // Contador de partidas jogadas

// Tabuleiro do jogo (com 9 posições: 3x3)
char tab[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

// Declarando uma função para exibir o tabuleiro na tela
void exibirTab()
{
    printf("\n");
    printf("  1   2   3 \n");
    printf("1 %c | %c | %c \n", tab[0], tab[1], tab[2]);
    printf(" ---+---+---\n");
    printf("2 %c | %c | %c \n", tab[3], tab[4], tab[5]);
    printf(" ---+---+---\n");
    printf("3 %c | %c | %c \n", tab[6], tab[7], tab[8]);
}

// Declarando uma função para limpar o tabuleiro, reiniciando todas as posições para ' '
void limparTabuleiro() {
    for (int i = 0; i < 9; i++) {
        tab[i] = ' ';
    }
}

// Declarando uma função para calcular se existe um vencedor no jogo
char calcularVencedor()
{
    // Definição das combinações vencedoras (linhas, colunas e diagonais)
    int linhas[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    
    // Verificando as combinações vencedoras
    for (int i = 0; i < 8; i++)
    {
        int a = linhas[i][0], b = linhas[i][1], c = linhas[i][2];
        if (tab[a] != ' ' && tab[a] == tab[b] && tab[a] == tab[c])
        {
            return tab[a]; // Retorna o símbolo do vencedor ('X' ou 'O')
        }
    }
    return ' '; // Retorna ' ' se não houver vencedor
}

// Declarando uma função para adicionar uma partida ao histórico de partidas
void adicionarPartida(Partida partida) {
    // Se o histórico de partidas não estiver cheio, adiciona a nova partida
    if (num_partidas < MAX_PARTIDAS) {
        historico[num_partidas] = partida;
        num_partidas++;
    } else {
        // Se o histórico estiver cheio, remove a primeira partida e adiciona a nova no final
        for (int i = 0; i < MAX_PARTIDAS - 1; i++) {
            historico[i] = historico[i + 1];
        }
        historico[MAX_PARTIDAS - 1] = partida;
    }
}

// Função principal do jogo
void jogar()
{
    int jogadorAtual = 1; // Jogador 1 inicia
    char simbolo; // Variável para armazenar o símbolo do jogador ('X' ou 'O')
    int linha, coluna, posicao, turno = 0; // Variáveis para coordenadas e controle de turno
    Partida partida; // Estrutura para armazenar as jogadas da partida
    partida.num_jogadas = 0; // Inicializa o contador de jogadas

    limparTabuleiro(); // Limpa o tabuleiro antes de iniciar a partida

    // Loop principal do jogo (máximo de 9 turnos)
    while (turno < 9)
    {
        limparTela(); // Limpa a tela a cada turno
        exibirTab(); // Exibe o tabuleiro atualizado

        // Define o símbolo do jogador atual
        simbolo = (jogadorAtual == 1) ? 'X' : 'O';
        printf("Jogador %d (%c), escolha coluna e linha (1-3 1-3):", jogadorAtual, simbolo);

        // Lê a coluna e linha escolhidas pelo jogador
        scanf("%d %d", &coluna, &linha);

        // Calcula a posição no tabuleiro (transforma a coordenada 2D em índice 1D)
        posicao = (linha - 1) * 3 + (coluna - 1);

        // Verifica se a jogada é válida
        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tab[posicao] != ' ')
        {
            printf("Jogada Inválida! Tente Novamente.\n");
            continue; // Se inválida, o jogador repete a jogada
        }

        // Realiza a jogada no tabuleiro
        tab[posicao] = simbolo;

        // Registra a jogada na partida
        partida.jogadas[turno].jogada = turno + 1;
        partida.jogadas[turno].posicao = posicao;
        partida.jogadas[turno].jogador = simbolo;
        partida.num_jogadas++;

        turno++; // Incrementa o turno

        // Verifica se algum jogador venceu
        char vencedor = calcularVencedor();
        if (vencedor != ' ') // Se houver vencedor, encerra o jogo
        {
            limparTela();
            exibirTab();
            printf("Jogador %d (%c) venceu!\n", jogadorAtual, vencedor);
            break;
        } else if (turno == 9) // Se o tabuleiro for preenchido e não houver vencedor, é empate
        {
            limparTela();
            exibirTab();
            printf("Empatou\n");
            break;
        } 

        // Alterna o jogador
        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
    }

    // Adiciona a partida ao histórico
    adicionarPartida(partida);

    // Pausa o jogo até o jogador pressionar uma tecla
    system("pause");
}

// Declarando uma função para visualizar o histórico de partidas
void verHistorico() {
    limparTela();
    if (num_partidas == 0) {
        printf("Nenhuma partida no histórico.\n");
        return;
    }

    // Solicitando ao usuário qual partida deseja ver
    int partida_index, jogada_index = 0;
    printf("Escolha uma partida (1-%d): ", num_partidas);
    scanf("%d", &partida_index);

    // Verifica se a partida escolhida é válida
    if (partida_index < 1 || partida_index > num_partidas) {
        printf("Partida inválida!\n");
        return;
    }

    // Obtém a partida escolhida
    Partida partida = historico[partida_index - 1];

    // Exibe as jogadas da partida, permitindo navegar entre as jogadas
    while (1) {
        limparTela(); // Limpa a tela
        limparTabuleiro(); // Limpa o tabuleiro

        // Exibe as jogadas até a jogada atual
        for (int i = 0; i <= jogada_index; i++) {
            tab[partida.jogadas[i].posicao] = partida.jogadas[i].jogador;
        }
        exibirTab();

        // Exibe o número da jogada e as opções de navegação
        printf("Jogada %d de %d\n", jogada_index + 1, partida.num_jogadas);
        printf("1 - Próxima jogada\n");
        printf("2 - Jogada anterior\n");
        printf("3 - Sair\n");
        
        int opcao;
        scanf("%d", &opcao);

        // Lógica para navegar pelas jogadas
        if (opcao == 1 && jogada_index < partida.num_jogadas - 1) {
            jogada_index++;
        } else if (opcao == 2 && jogada_index > 0) {
            jogada_index--;
        } else if (opcao == 3) {
            break;
        } else {
            printf("Opção inválida!\n");
        }
    }
}

// Declarando função para exibir o menu principal do jogo
void menu(){
    int opcao;
    do
    {
        limparTela(); // Limpa a tela a cada exibição do menu
        printf("\n===== JOGO DA VELHA =====\n");
        printf("1 - Jogar contra outro jogador\n");
        printf("2 - Ver histórico\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Executa a opção escolhida pelo usuário
        switch(opcao)
        {
            case 1: jogar(); break;     // Inicia uma nova partida
            case 2: verHistorico(); break; // Exibe o histórico de partidas
            case 3: printf("saindo...\n"); break; // Encerra o programa
            default: printf("Opção inválida!\n"); break; // Se opção inválida
        }
    } while (opcao != 3); // Repete o menu até a opção 3 ser escolhida
}

// Função principal do programa
int main(void){
    menu(); // Chama o menu para iniciar o jogo
    return 0;
}