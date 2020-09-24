#include "general.hpp"

const int N = 10000000;
int* l = new int[N];
int* m = new int[N];

void invariant(){
    long x = 431;
    long y = 17;
    for(int i = 1; i < N; ++i){
        l[i] = (x + y) * m[i-1];
        l[i] = l[i] + m[i] + 17;
    }
}

void invariant_opt(){
    int x = 431;
    int y = 17;
    int sum = x + y;
    for(int i = 1; i < N; ++i){
        l[i] = sum * m[i-1];
        l[i] = l[i] + m[i] + 17;
    }
}