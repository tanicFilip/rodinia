g++ -O0 -fmove-loop-invariants -floop-interchange -floop-unroll-and-jam -fpeel-loops -ftree-loop-distribution -ftree-loop-vectorize -floop-parallelize-all -ftree-parallelize-loops=4 -c -o peeling.o peeling.cpp
g++ -O0 -fmove-loop-invariants -floop-interchange -floop-unroll-and-jam -fpeel-loops -ftree-loop-distribution -ftree-loop-vectorize -floop-parallelize-all -ftree-parallelize-loops=4 -c -o unrolling.o unrolling.cpp
g++ -O0 -fmove-loop-invariants -floop-interchange -floop-unroll-and-jam -fpeel-loops -ftree-loop-distribution -ftree-loop-vectorize -floop-parallelize-all -ftree-parallelize-loops=4 -c -o distribution.o distribution.cpp
g++ -O0 -fmove-loop-invariants -floop-interchange -floop-unroll-and-jam -fpeel-loops -ftree-loop-distribution -ftree-loop-vectorize -floop-parallelize-all -ftree-parallelize-loops=4 -c -o fusion.o fusion.cpp
g++ -O0 -fmove-loop-invariants -floop-interchange -floop-unroll-and-jam -fpeel-loops -ftree-loop-distribution -ftree-loop-vectorize -floop-parallelize-all -ftree-parallelize-loops=4 -c -o interchange.o interchange.cpp
g++ -O0 -fmove-loop-invariants -floop-interchange -floop-unroll-and-jam -fpeel-loops -ftree-loop-distribution -ftree-loop-vectorize -floop-parallelize-all -ftree-parallelize-loops=4 -c -o skewing.o skewing.cpp
g++ -O0 -fmove-loop-invariants -floop-interchange -floop-unroll-and-jam -fpeel-loops -ftree-loop-distribution -ftree-loop-vectorize -floop-parallelize-all -ftree-parallelize-loops=4 -c -o invariant.o invariant.cpp

g++ -O0 synthetic.cpp peeling.o unrolling.o distribution.o fusion.o interchange.o skewing.o invariant.o -o synthetic