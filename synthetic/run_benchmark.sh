./cleanup.sh

./compile_$1.sh

mkdir ./results

./synthetic peeling 200 > ./results/peeling_O$1.txt
./synthetic unrolling 200 > ./results/unrolling_O$1.txt
./synthetic distribution 50 > ./results/distribution_O$1.txt
./synthetic fusion 100 > ./results/fusion_O$1.txt
./synthetic interchange 15000000 > ./results/interchange_O$1.txt
./synthetic skewing 100000 > ./results/skewing_O$1.txt
./synthetic invariant 150 > ./results/invariant_O$1.txt