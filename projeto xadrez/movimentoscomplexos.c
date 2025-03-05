#include <stdio.h>

// Função recursiva para o movimento da Torre (5 casas para a direita)
void moverTorre(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Função recursiva para o movimento do Bispo (5 casas na diagonal para cima e à direita)
void moverBispoRec(int casas) {
    if (casas == 0) return;
    printf("Cima, Direita\n");
    moverBispoRec(casas - 1);
}

// Função recursiva para o movimento da Rainha (8 casas para a esquerda)
void moverRainha(int casas) {
    if (casas == 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

int main() {
    // Movimento da Torre
    printf("Movimento da Torre:\n");
    moverTorre(5);
    printf("\n");

    // Movimento do Bispo com recursividade e loops aninhados
    printf("Movimento do Bispo:\n");
    for (int i = 0; i < 5; i++) {
        printf("Cima, ");
        for (int j = 0; j < 1; j++) {
            printf("Direita\n");
        }
    }
    printf("\n");

    // Movimento da Rainha
    printf("Movimento da Rainha:\n");
    moverRainha(8);
    printf("\n");

    // Movimento do Cavalo (2 casas para cima, 1 para a direita) com loops aninhados
    printf("Movimento do Cavalo:\n");
    int mov1 = 2, mov2 = 1;
    for (int a = 0; a < mov1; a++) {
        printf("Cima\n");
    }
    for (int b = 0; b < mov2; b++) {
        printf("Direita\n");
    }
    
    return 0;
}
