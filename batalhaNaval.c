#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Mariane de Oliveira Kronemberger

int main() {

    // Variáveis

    int tabuleiro[10][10] = {0};
    int navio1[3] = {3, 3, 3}; //Navio Horizontal
    int navio2[3] = {3, 3, 3}; //Navio Vertical
    int navio3[3] = {3, 3, 3}; //Navio Diagonal 1
    int navio4[3] = {3, 3, 3}; //Navio Diagonal 2
    int i, j;
    int l1 = 2, c1 = 4; //Navio Horizontal
    int l2 = 5, c2 = 1; //Navio vertical
    int l3 = 6, c3 = 5; //Navio Diagonal 1
    int l4 = 4, c4 = 7; //Navio Diagonal 2

    // Posicionar navios

    // Navio 1 Horizontal
    for (i = 0; i < 3; i++){
        tabuleiro[l1][c1 + i] = navio1[i];
    };

    //Navio 2 Vertical
    for (i = 0; i < 3; i ++){
        tabuleiro[l2 + i][c2] = navio2[i];
    };

    //Navio 3 Diagonal 1
    for (i = 0; i < 3; i++){
        tabuleiro[l3 + i][c3 + i] = navio3[i];
    };

    //Navio 3 Diagonal 2
    for (i = 0; i < 3; i++){
        tabuleiro[l4 + i][c4 + i] = navio4[i];
    };

    // Tabuleiro e navios

    printf("~*~*~ T A B U L E I R O ~*~*~\n");
    printf(" 𓊈 0 = Água | 0 = Navio 𓊉 \n \n");

    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j ++){
            if (tabuleiro[i][j] == 0){
                printf(" 0 ");
            } else if(tabuleiro[i][j] == 3) {
                printf (" 3 ");
            }
        }

        printf(" \n");
    }

   
    return 0;
}


 // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

