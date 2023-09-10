//passeio do cavalo num tabuleiro NxN - usando backtracking
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define TAM 5
#define TAM2 TAM*TAM
#define UNVIS -1

char tabuleiro[TAM][TAM];
char moves[8][2] = {{1, 2},
                    {-1, 2},
                    {1, -2},
                    {-1, -2},
                    {2, 1}, 
                    {2, -1},
                    {-2, 1},
                    {-2, -1}
};

void passeio(int i, int j, int count);
char valido(int i, int j);
void imprime_tab(void);

int main(void){

    memset(tabuleiro, UNVIS, sizeof(tabuleiro));

    int i = TAM/2;
    int j = TAM/2;
    tabuleiro[i][j] = 0;
    int count = 1;

    passeio(i, j, count);

    return 0;
}

void imprime_tab(void){
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++)
            printf("%02d ", tabuleiro[i][j]);
        printf("\n");
    }
    printf("\n\n");    
}

char valido(int i, int j){
    return(i >=0 && j >=0 && i < TAM && j < TAM && tabuleiro[i][j] == UNVIS);
}

void passeio(int i, int j, int count){

    if(count == TAM*TAM){
        printf("xeguei\n");
        imprime_tab();       
        return;
    }
    for(int k = 0; k < 8; k++){ //o cavalo tem 8 movimentos possíveis
        int novo_i = i + moves[k][0];
        int novo_j = j + moves[k][1];

        if(valido(novo_i, novo_j)){
            tabuleiro[novo_i][novo_j] = count;
            passeio(novo_i, novo_j, count+1);
            tabuleiro[novo_i][novo_j] = UNVIS;
        }
    }
}