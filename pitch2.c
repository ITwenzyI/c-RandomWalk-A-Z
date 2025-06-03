#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 10
#define DOWN 0
#define UP 1
#define LEFT 2
#define RIGHT 3
#define NUM_DIRS 4

//neu

// Random Walk from A to Z on a pitch with points

void showpitch(char pitch[10][10]) {
    // show initial pitch
    printf("Pitch:\n");
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            printf("%2c", pitch[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void fillpitch_points(char pitch[10][10]) {
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            pitch[i][j] = '.';
        }
    }
}


int main() {

    srand(time(NULL));
    char pitch[MAX_SIZE][MAX_SIZE];

    // fill pitch with points
    fillpitch_points(pitch);

    // show initial pitch
    showpitch(pitch);

    /*
     * Direction flags: down, up, left, right
     *
     *  A direction flag is true if the target position is a dot '.'. If all
     *  directions are wrong, the random walker is boxed in.
     */
    bool down = true, up = true, left = true, right = true;

    // start position
    int row = 0, col = 0;
    char ch = 'A';
    pitch[row][col] = ch++;
    while (ch <= 'Z' && (down || up || left || right)) {
        int next = rand() % NUM_DIRS;
        switch (next) {
            case DOWN:
                if (row + 1 < MAX_SIZE && pitch[row + 1][col] == '.') {
                    pitch[++row][col] = ch++;
                    down = up = left = right = true;
                } else {
                    down = false;
                }
                break;
            case UP:
                if (0 < row && pitch[row - 1][col] == '.') {
                    pitch[--row][col] = ch++;
                    down = up = left = right = true;
                } else {
                    up = false;
                }
                break;
            case LEFT:
                if (0 < col && pitch[row][col - 1] == '.') {
                    pitch[row][--col] = ch++;
                    down = up = left = right = true;
                }
                else {
                    left = false;
                }
                break;
            case RIGHT:
                if (col + 1 < MAX_SIZE && pitch[row][col + 1] == '.') {
                    pitch[row][++col] = ch++;
                    down = up = left = right = true;
                } else {
                    right = false;
                }
                break;
            default:
                printf("Error! You shouldn't roam around here.\n");
                break;
        }
    }

    // show random walk pitch
    printf("Random Walk ");
    showpitch(pitch);
    printf("Done.\n");

    return 0;
}