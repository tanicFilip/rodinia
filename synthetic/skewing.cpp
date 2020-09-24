#include "general.hpp"

const int M = 100;
const int N = 100;
int** q = new int*[M];


void setup_skewing(){
    for(int i = 0; i < M; ++i){
        q[i] = new int[N];
    }
}

void skewing(){
    for(int j = 1; j < N; ++j){
        for(int i = 1; i < M; ++i){
            q[i][j] = q[i-1][j] + q[i][j-1];
        }
    }
}

void skewing_opt(){
    for(int t = 1; t < M + 2*N; ++t){        
        int pmin = std::max(t%2 + 1, t-2*N+2);
        int pmax = std::min(t, M-1);
        for(int p = pmin; p < pmax; p += 2){
            int i = p;
            int j = (t-p)/2;
            q[i][j] = q[i-1][j] + q[i][j-1];
        }
    }
}

/*void setup_skewing(){
    for(int i = 0; i < N; ++i){
        p[i] = new int[N];
    }
}

void skewing(){
    for(int i = 1; i < N; ++i){
        for(int j = 1; j < N; ++j){
            p[i][j] = p[i-1][j] + p[i][j-1];
        }
    }
}

void skewing_opt(){
    for(int j = 1; j < N+N - 1; ++j){
        for(int I = std::max(1, j-N); I < std::min(N, j-1); ++I){
            p[I][j-I] = p[I-1][j-I] + p[I][j-I-1];
        }
    }
}*/