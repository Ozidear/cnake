#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define GREEN "\033[42m"
#define RESET "\033[0m"

typedef struct {
    int x;
    int y;
} Point;

void move_cursor(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void render_line(char symbol, int length) {
    char string[length + 1];
    for (int i = 0; i < length; i++) {
        string[i] = symbol;
    }
    string[length] = '\0';
    
    printf("%s", string);
}

void render_board(int height) {
    int width = height * 2;
    move_cursor(1, 1);

    printf(" ");
    render_line('-', width);
    printf("\n");
    for (int i = 0; i < height; i++) {
        printf("|");
        render_line(' ', width);
        printf("|\n");
    }
    printf(" ");
    render_line('-', width);
    printf("\n");
}


void render_snake(int position) {
    move_cursor((position * 2), position + 1);
    printf(GREEN "  " RESET);
}


int main() {
    int i = 1;
    while (true) {
        render_board(10);
        render_snake(i);

        i++;
        fflush(stdout);
        sleep(1);
    }
}