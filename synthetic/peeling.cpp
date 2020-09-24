#include "general.hpp"

const int N = 10000000;
int* a = new int[N];

void peeling(){
    for(int i = 0; i < N; ++i){
        a[i] = a[i] + a[0];
    }
}

void peeling_opt(){
    a[0] = a[0] + a[0];

    for(int i = 1; i < N; ++i){
        a[i] = a[i] + a[0];
    }
}