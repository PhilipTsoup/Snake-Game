#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    LEFT,
    RIGHT,
    UP,
    DOWN
}Direction;

typedef struct {
    int x;
    int y;
}Position;

typedef struct {
    int size;
    Direction direction;
    Position position;
}Snake;

typedef struct {
    Position position;
} Apple;

#define SIZE 100

Apple apple;
Snake snake;

char map[SIZE];

apple_update() {
    unsigned int seed = time(NULL);
    apple.position.x = rand_r(&seed) / (double)RAND_MAX;
    apple.position.y = rand_r(&seed) / (double)RAND_MAX;
}

void update() {
    switch (snake.direction)
    {
    case LEFT:
        snake.position.x--;
        break;
    
    case RIGHT:
        snake.position.x++;
        break;

    case UP:
        snake.position.y++;
        break;

    case DOWN:
        snake.position.y--;
        break;
    }

    if (apple.position.x == snake.position.x && apple.position.y == snake.position.y)
    {
        apple_update();
        snake.size++;
    }
    
}

game_print() {
    for (int i = 0; i < SIZE; i++)
    {
        printf("%c", map[i]);
    }
    
}

void game_frame() {
    update();
    game_print();
}



int main() {
    
    snake.direction = RIGHT;
    snake.size = 1;
    game_map_init();

    game_print_start_line();

    while(snake.size != 0) {
        game_print();
        game_frame();
    }


    return 0;
}