#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "timer.h"

void run(int argc, char **argv);

/* define timer macros */
#define pin_stats_reset() startCycle()
#define pin_stats_pause(cycles) stopCycle(cycles)
#define pin_stats_dump(cycles) printf("timer: %Lu\n", cycles)

int rows, cols;
int *data;
int **wall;
int *result;

void init(int argc, char **argv) {
    if (argc == 3) {
        cols = atoi(argv[1]);
        rows = atoi(argv[2]);
    } else {
        printf("Usage: pathfiner width num_of_steps\n");
        exit(0);
    }
    data = new int[rows * cols];
    wall = new int *[rows];
    for (int n = 0; n < rows; n++)
        wall[n] = data + cols * n;
    result = new int[cols];

    srand(7);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            wall[i][j] = rand() % 10;
        }
    }
    for (int j = 0; j < cols; j++)
        result[j] = wall[0][j];

    if (getenv("OUTPUT")) {
        FILE *file = fopen("output.txt", "w");

        fprintf(file, "wall:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                fprintf(file, "%d ", wall[i][j]);
            }
            fprintf(file, "\n");
        }

        fclose(file);
    }
}

#define IN_RANGE(x, min, max) ((x) >= (min) && (x) <= (max))
#define CLAMP_RANGE(x, min, max) x = (x < (min)) ? min : ((x > (max)) ? max : x)
#define MIN(a, b) ((a) <= (b) ? (a) : (b))

int main(int argc, char **argv) {
    run(argc, argv);

    return EXIT_SUCCESS;
}

void run(int argc, char **argv) {
    init(argc, argv);

    unsigned long long cycles;

    int *src, *dst, *temp;
    int min;

    dst = result;
    src = new int[cols];

    pin_stats_reset();
    for (int t = 0; t < rows - 1; t++) {
        temp = src;
        src = dst;
        dst = temp;

        int n = 0;
        
        if(n < cols - 1){
            min = src[0];
            min = MIN(min, src[0 + 1]);
            dst[0] = wall[t + 1][0] + min;
        }

        for (n = 1; n < cols - 1; n++) {
            min = src[n];
            min = MIN(min, src[n - 1]);
            min = MIN(min, src[n + 1]);
            dst[n] = wall[t + 1][n] + min;
        }

        if(n < cols){
            min = src[cols - 1];
            min = MIN(min, src[cols - 1 - 1]);
            dst[cols - 1] = wall[t + 1][cols - 1] + min;
        }

    }

    pin_stats_pause(cycles);
    pin_stats_dump(cycles);

    if (getenv("OUTPUT")) {
        FILE *file = fopen("output.txt", "a");

        fprintf(file, "data:\n");
        for (int i = 0; i < cols; i++)
            fprintf(file, "%d ", data[i]);
        fprintf(file, "\n");

        fprintf(file, "result:\n");
        for (int i = 0; i < cols; i++)
            fprintf(file, "%d ", dst[i]);
        fprintf(file, "\n");

        fclose(file);
    }

    delete[] data;
    delete[] wall;
    delete[] dst;
    delete[] src;
}
