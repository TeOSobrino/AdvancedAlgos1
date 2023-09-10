#include <stdio.h>

#define swap(a, b) {int temp; temp = a; a = b; b = temp;} 
#define TAM 3

void permuta(char pal[TAM], int count);

int main(void){

    char pal[TAM] = {'a', 'b', 'c'};

    permuta(pal, 0);

    return 0;
}

void permuta(char pal[TAM], int count){

    if(count == TAM){
        for(int i = 0; i < TAM; i++){
            printf("%c ", pal[i]);
        }
        printf("\n");
        return;
    }

    printf("f1: %d ** %d\n\n", count, count);

    for(int i = count; i < TAM; i++){
        printf("for: %d ** %d\n", i, count);
        swap(pal[i], pal[count]);
        permuta(pal, count+1);
        swap(pal[i], pal[count]);
        printf("back: %d ** %d\n", i, count);
    }
}