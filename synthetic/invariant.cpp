#include "general.hpp"

const int N = 10000000;
int* l = new int[N];
int* m = new int[N];

void invariant(){
    long x = 431;
    long y = 17;
    for(int i = 1; i < N; ++i){
        m[0] = (x + y) * m[1];
        l[i] = l[i] + m[0] + 17;
    }
}

void invariant_opt(){
    int x = 431;
    int y = 17;
    m[0] = (x + y) * m[1];
    for(int i = 1; i < N; ++i){
        l[i] = l[i] + m[0] + 17;
    }
}