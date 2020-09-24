#include "general.hpp"

const int N = 10000000;
int* c = new int[N];
int* x = new int[N];
int* y = new int[N];
int* z = new int[N];

void distribution(){
    for (int i = 0; i < N; ++i) {
        x[i] = y[i] + z[i];
        c[i+1] = (c[i-1] + c[i] + c[i+1]) / 3;
        y[i] = z[i] - x[i];
    }
}

void distribution_opt(){
    for (int i = 0; i < N; ++i) {
        x[i] = y[i] + z[i];
        y[i] = z[i] - x[i];
    }

    for (int i = 0; i < N; ++i) {
        c[i+1] = (c[i-1] + c[i] + c[i+1]) / 3;
    }
}