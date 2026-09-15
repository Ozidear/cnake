#include <stdio.h>

#define GREEN "\033[32m"
#define RESET "\033[0m"

void draw_line(char symbol, int length) {
    char string[length + 1];
    for (int i = 0; i < length; i++) {
        string[i] = symbol;
    }
    string[length] = '\0';
    
    printf("%s", string);
}

void draw_board(int height) {
    int width = height * 2;

    printf(" ");
    draw_line('-', width);
    printf("\n");
    for (int i = 0; i < height; i++) {
        printf("|");
        draw_line(' ', width);
        printf("|\n");
    }
    printf(" ");
    draw_line('-', width);
    printf("\n");
}


int main() {
    draw_board(10);
}