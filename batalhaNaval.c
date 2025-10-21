#include <stdio.h>

#define TAM_TAB 10

int main() {

    int tabuleiro[TAM_TAB][TAM_TAB] = {0};
    int ataque[TAM_TAB][TAM_TAB] = {0}; // matriz para ataques
    int navio1[3] = {3,3,3}; // Horizontal
    int navio2[3] = {3,3,3}; // Vertical
    int navio3[3] = {3,3,3}; // Diagonal 1
    int navio4[3] = {3,3,3}; // Diagonal 2
    int i, j;
    int l1=2, c1=4, l2=5, c2=1, l3=2, c3=2, l4=4, c4=7;
    char tecla;
    int escolha;
    int origem_l, origem_c;

    // Posicionar navios
    for(i=0;i<3;i++){
        tabuleiro[l1][c1+i] = navio1[i];   // Horizontal
        tabuleiro[l2+i][c2] = navio2[i];   // Vertical
        tabuleiro[l3+i][c3+i] = navio3[i]; // Diagonal 1
        tabuleiro[l4+i][c4-i] = navio4[i]; // Diagonal 2
    }

    // Tabuleiro inicial
    printf("~*~*~ T A B U L E I R O ~*~*~\n");
    printf(" 𓊈 0 = Agua | 3 = Navio 𓊉\n");
    for(i=0;i<TAM_TAB;i++){
        for(j=0;j<TAM_TAB;j++){
            if(tabuleiro[i][j]==0) printf(" 0 ");
            else printf(" 3 ");
        }
        printf("\n");
    }

    printf("\nAperte C para continuar: ");
    scanf(" %c",&tecla);

    // Loop menu
    do{
        printf("\nEscolha a habilidade:\n1 - Cone\n2 - Cruz\n3 - Octaedro\n0 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d",&escolha);

        switch(escolha){
            case 1: // Cone
                origem_l = 2; origem_c = 2;
                for(i=0;i<3;i++){
                    for(j=-i;j<=i;j++){
                        int l = origem_l + i;
                        int c = origem_c + j;
                        if(l>=0 && l<TAM_TAB && c>=0 && c<TAM_TAB)
                            ataque[l][c] = 1;
                    }
                }
                break;

            case 2: // Cruz
                origem_l = 5; origem_c = 5;
                for(i=-2;i<=2;i++){
                    int l = origem_l + i;
                    int c = origem_c + i;
                    if(origem_l>=0 && origem_l<TAM_TAB && c>=0 && c<TAM_TAB)
                        ataque[origem_l][c] = 1;
                    if(l>=0 && l<TAM_TAB && origem_c>=0 && origem_c<TAM_TAB)
                        ataque[l][origem_c] = 1;
                }
                break;

            case 3: // Octaedro
                origem_l = 7; origem_c = 7;
                for(i=-2;i<=2;i++){
                    for(j=-2;j<=2;j++){
                        if((i==0 && j>=-2 && j<=2) || (i==-1 && j>=-1 && j<=1) || (i==1 && j>=-1 && j<=1) || (i==-2 && j==0) || (i==2 && j==0)){
                            int l = origem_l + i;
                            int c = origem_c + j;
                            if(l>=0 && l<TAM_TAB && c>=0 && c<TAM_TAB)
                                ataque[l][c] = 1;
                        }
                    }
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

        //Tabuleiro atualizado
        printf("\nTabuleiro atualizado:\n");
        for(i=0;i<TAM_TAB;i++){
            for(j=0;j<TAM_TAB;j++){
                if(tabuleiro[i][j]==3 && ataque[i][j]==1) printf(" * "); 
                else if(tabuleiro[i][j]==3) printf(" 3 ");
                else if(ataque[i][j]==1) printf(" * ");  
                else printf(" 0 ");                    
            }
            printf("\n");
        }

    }while(escolha!=0);

    return 0;
}