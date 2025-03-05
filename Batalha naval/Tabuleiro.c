#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontal ou verticalmente
int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, int direcao) {
    if ((direcao == 0 && coluna + tamanho > TAMANHO) || (direcao == 1 && linha + tamanho > TAMANHO)) {
        return 0;
    }
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 0 && tabuleiro[linha][coluna + i] == NAVIO) return 0;
        if (direcao == 1 && tabuleiro[linha + i][coluna] == NAVIO) return 0;
    }
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 0) tabuleiro[linha][coluna + i] = NAVIO;
        else tabuleiro[linha + i][coluna] = NAVIO;
    }
    return 1;
}

// Função para posicionar um navio diagonalmente
int posicionarNavioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, int direcao) {
    if ((direcao == 0 && (linha + tamanho > TAMANHO || coluna + tamanho > TAMANHO)) || 
        (direcao == 1 && (linha + tamanho > TAMANHO || coluna - tamanho < 0))) {
        return 0;
    }
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 0 && tabuleiro[linha + i][coluna + i] == NAVIO) return 0;
        if (direcao == 1 && tabuleiro[linha + i][coluna - i] == NAVIO) return 0;
    }
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 0) tabuleiro[linha + i][coluna + i] = NAVIO;
        else tabuleiro[linha + i][coluna - i] = NAVIO;
    }
    return 1;
}

// Função para aplicar habilidade em formato de cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO; i++) {
        tabuleiro[i][coluna] = HABILIDADE;
        tabuleiro[linha][i] = HABILIDADE;
    }
}

// Função para aplicar habilidade em formato de cone
void aplicarHabilidadeCone(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            if (linha + i < TAMANHO && coluna + j >= 0 && coluna + j < TAMANHO) {
                tabuleiro[linha + i][coluna + j] = HABILIDADE;
            }
        }
    }
}

// Função para aplicar habilidade em formato de octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = -2; i <= 2; i++) {
        for (int j = -2 + abs(i); j <= 2 - abs(i); j++) {
            if (linha + i >= 0 && linha + i < TAMANHO && coluna + j >= 0 && coluna + j < TAMANHO) {
                tabuleiro[linha + i][coluna + j] = HABILIDADE;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    // Posicionando navios
    posicionarNavio(tabuleiro, 2, 3, 3, 0);
    posicionarNavio(tabuleiro, 5, 1, 3, 1);
    posicionarNavioDiagonal(tabuleiro, 0, 0, 3, 0);
    posicionarNavioDiagonal(tabuleiro, 3, 9, 3, 1);
    
    // Aplicando habilidades
    aplicarHabilidadeCruz(tabuleiro, 4, 4);
    aplicarHabilidadeCone(tabuleiro, 2, 6);
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7);
    
    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
