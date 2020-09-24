#include "general.hpp"

const int N = 10000000;
int* b = new int[N];

void unrolling(){
    for(int i = 0; i < N; ++i){
        b[i] += 17;
    }
}

void unrolling_opt(){
    for(int i = 0; i < N; i += 4){
        b[i] += 17;
        b[i+1] += 17;
        b[i+2] += 17;
        b[i+3] += 17;
    }
}