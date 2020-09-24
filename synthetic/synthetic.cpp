#include "general.hpp"

using namespace std;

int main(int argc, char** argv){

    string toRun = argv[1];
    int runCount = stoi(string(argv[2]));
    int toRunInt = 0;

    if(toRun.compare("peeling") == 0){
        toRunInt = 1;
    }
    else if (toRun.compare("unrolling") == 0){
        toRunInt = 2;
    }
    else if (toRun.compare("distribution") == 0){
        toRunInt = 3;
    }
    else if (toRun.compare("fusion") == 0){
        toRunInt = 4;
    }
    else if (toRun.compare("interchange") == 0){
        toRunInt = 5;
        setup_interchange();
    }
    else if (toRun.compare("skewing") == 0){
        toRunInt = 6;
        setup_skewing();
    }
    else if (toRun.compare("invariant") == 0){
        toRunInt = 7;
    }

    cout << "Running " << toRunInt << " " << toRun << "\n";

    long time_non_opt = 0.0;
    long time_opt = 0.0;

    for(int i = 0; i < runCount; ++i){
        auto time_mid = std::chrono::high_resolution_clock::now();
        auto time_start = std::chrono::high_resolution_clock::now();

        switch (toRunInt)
        {
        case 1: // peeling
            peeling();
            time_mid = std::chrono::high_resolution_clock::now();
            peeling_opt();
            break;

        case 2: // unrolling
            unrolling();
            time_mid = std::chrono::high_resolution_clock::now();
            unrolling_opt();
            break;

        case 3: // distribution
            distribution();
            time_mid = std::chrono::high_resolution_clock::now();
            distribution_opt();
            break;
        
        case 4: // fusion
            fusion();
            time_mid = std::chrono::high_resolution_clock::now();
            fusion_opt();
            break;
        
        case 5: // interchange
            interchange();
            time_mid = std::chrono::high_resolution_clock::now();
            interchange_opt();
            break;

        case 6: // skewing
            skewing();
            time_mid = std::chrono::high_resolution_clock::now();
            skewing_opt();
            break;

        case 7: // invariant
            invariant();
            time_mid = std::chrono::high_resolution_clock::now();
            invariant_opt();
            break;

        default:
            break;
        }

        auto time_end = std::chrono::high_resolution_clock::now();

        time_non_opt += (time_mid - time_start).count();
        time_opt += (time_end - time_mid).count();
    }

    cout << "Run count: " << runCount << "\n";
    cout << "Non optimized total run time: " << (double)time_non_opt / 1000000 << " ms\n";
    cout << "Optimized total run time: " << (double)time_opt / 1000000  << " ms\n";

}