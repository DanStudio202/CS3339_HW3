#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "cache.h"

using namespace std;

int main(int argc, char* argv[]) {
    // 1. checks command arguements
    if (argc < 4) {
        cout << "Usage: ./cache_sim num_entries associativity memory_reference_file\n";
        return 1;
    }

    // 2. parse each argument
    unsigned entries = atoi(argv[1]);
    unsigned assoc = atoi(argv[2]);
    string input_filename = argv[3];

    // 3 initialize Cache
    Cache simulator(entries, assoc);

    // 4 opens the input and output files
    ifstream input(input_filename);
    if (!input.is_open()) {
        cerr << "Error: Could not open input file " << input_filename << endl;
        return 1;
    }

    ofstream output("cache_sim_output");
    if (!output.is_open()) {
        cerr << "Error: Could not create output file cache_sim_output" << endl;
        return 1;
    }

    // 5. reads the memory referenes
    unsigned long addr;
    while (input >> addr) {
        if (simulator.hit(addr)) {
            output << addr << ": HIT\n";
        } else {
            output << addr << ": MISS\n";
            simulator.update(addr); // fetch cache
        }
    }

    // 6 clean up
    input.close();
    output.close();

    cout << "Simulation complete. Results written to 'cache_sim_output'." << endl;
    return 0;
}
