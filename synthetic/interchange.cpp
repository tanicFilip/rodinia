#include "general.hpp"

const int M = 10;
const int N = 10;
int** f = new int*[M];
int** g = new int*[M];

void setup_interchange(){
    for(int i = 0; i < M; ++i){
        f[i] = new int[N];
        g[i] = new int[N];
    }
}

void interchange(){
    for(int j = 0; j < N - 1; ++j){
        for(int i = 0; i < M; ++i){
            f[i][j+1] = f[i][j] + g[j][i];
        }
    }
}

void interchange_opt(){
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N - 1; ++j){
            f[i][j+1] = f[i][j] + g[j][i];
        }
    }
}