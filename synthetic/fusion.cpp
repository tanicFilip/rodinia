#include "general.hpp"

const int N = 10000000;
int* d = new int[N];
int* e = new int[N];

void fusion(){
    long sum = 0;
    for(int i = 0; i < N; ++i){
        sum += d[i] + 2;
    }
    for(int i = 0; i < N; ++i){
        e[i] = d[i] + 17;
    }
}

void fusion_opt(){
    long sum = 0;
    for(int i = 0; i < N; ++i){
        sum += d[i] + 2;
        e[i] = d[i] + 17;
    }
}