#include <cstdlib>
#include <chrono>
#include <string>
#include <iostream>

// peeling
void peeling();
void peeling_opt();

// unrolling
void unrolling();
void unrolling_opt();

// distribution
void distribution();
void distribution_opt();

// fusion
void fusion();
void fusion_opt();

// interchange
void setup_interchange();
void interchange();
void interchange_opt();

// skewing
void setup_skewing();
void skewing();
void skewing_opt();

// invariant
void invariant();
void invariant_opt();