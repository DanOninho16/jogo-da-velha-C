#include <stdio.h>
#include <stdlib.h>

#define MAX_JOGADAS 9
#define MAX_PARTIDAS 5
#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

void limparTela() {
    system(LIMPAR_TELA);
}

typedef struct {
    int jogada;
    int posicao;
    char jogador;
} Jogada;

typedef struct {
    Jogada jogadas[MAX_JOGADAS];
    int num_jogadas;
} Partida;

Partida historico[MAX_PARTIDAS];
int num_partidas = 0;

char tab[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

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
void limparTabuleiro() {
    for (int i = 0; i < 9; i++) {
        tab[i] = ' ';
    }
}

char calcularVencedor()
{
    int linhas[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (int i = 0; i < 8; i++)
    {
        int a = linhas[i][0], b = linhas[i][1], c = linhas[i][2];
        if (tab[a] != ' ' && tab[a] == tab[b] && tab[a] == tab[c])
        {
            return tab[a];
        }
    }
    return ' ';
}

void adicionarPartida(Partida partida) {
    if (num_partidas < MAX_PARTIDAS) {
        historico[num_partidas] = partida;
        num_partidas++;
    } else{ 
        for (int i = 0; i < MAX_PARTIDAS; i++)
        {
            historico[i] = historico[i + 1];
        }
        historico[MAX_PARTIDAS - 1] = partida;
    }
    
}

void jogar()
{
    int jogadorAtual = 1;
    char simbolo;
    int linha, coluna, posicao, turno = 0;
    Partida partida;
    partida.num_jogadas = 0;
    limparTabuleiro();
    while (turno < 9)
    {
        limparTela();
        exibirTab();
        simbolo = (jogadorAtual == 1) ? 'X' : 'O';
        printf("Jogador %d (%c), escolha coluna e linha (1-3 1-3):", jogadorAtual, simbolo);
        scanf("%d %d", &coluna, &linha);
        posicao = (linha - 1) * 3 + (coluna - 1);
        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tab[posicao] != ' ')
        {
            printf("Jogada Inválida! Tente Novamente.\n");
            continue;
        }
        tab[posicao] = simbolo;
        partida.jogadas[turno].jogada = turno + 1;
        partida.jogadas[turno].posicao = posicao;
        partida.jogadas[turno].jogador = simbolo;
        partida.num_jogadas++;
        turno++;
        char vencedor = calcularVencedor();
        if (vencedor != ' ')
        {
            limparTela();
            exibirTab();
            printf("Jogador %d (%c) venceu!\n", jogadorAtual, vencedor);
            break;
        }else if (turno == 9)
        {
            limparTela();
            exibirTab();
            printf("Empatou\n");
            break;
        } 
        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
    }
    adicionarPartida(partida);
    system("pause");
}

void verHistorico() {
    limparTela();
    if (num_partidas == 0) {
        printf("Nenhuma partida no histórico.\n");
        return;
    }
    int partida_index, jogada_index = 0;
    printf("Escolha uma partida (1-%d): ", num_partidas);
    scanf("%d", &partida_index);
    if (partida_index < 1 || partida_index > num_partidas) {
        printf("Partida inválida!\n");
        return;
    }
    Partida partida = historico[partida_index - 1];
    while (1) {
        limparTela();
        limparTabuleiro();
        for (int i = 0; i <= jogada_index; i++) {
            tab[partida.jogadas[i].posicao] = partida.jogadas[i].jogador;
        }
        exibirTab();
        printf("Jogada %d de %d\n", jogada_index + 1, partida.num_jogadas);
        printf("1 - Próxima jogada\n");
        printf("2 - Jogada anterior\n");
        printf("3 - Sair\n");
        int opcao;
        scanf("%d", &opcao);
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

void menu(){
    int opcao;
    do
    {
        limparTela();
        printf("\n===== JOGO DA VELHA =====\n");
        printf("1 - Jogar contra outro jogador\n");
        printf("2 - Ver histórico\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1: jogar(); break;
            case 2: verHistorico(); break;
            case 3: printf("saindo...\n"); break;    
            default: printf("Opção inválida!\n"); break;
        }
    } while (opcao != 3);
    

}

int main(void){
    menu();
    return 0;
}