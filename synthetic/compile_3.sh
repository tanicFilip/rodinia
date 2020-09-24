g++ -O3 -c -o peeling.o peeling.cpp
g++ -O3 -c -o unrolling.o unrolling.cpp
g++ -O3 -c -o distribution.o distribution.cpp
g++ -O3 -c -o fusion.o fusion.cpp
g++ -O3 -c -o interchange.o interchange.cpp
g++ -O3 -c -o skewing.o skewing.cpp
g++ -O3 -c -o invariant.o invariant.cpp

g++ -O0 synthetic.cpp peeling.o unrolling.o distribution.o fusion.o interchange.o skewing.o invariant.o -o synthetic