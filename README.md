CS3339 Hw 3: Cache Simulator
Daniel Saieh

Description

This is the design of a programmable CPU Cache Simulator written in C++. The program works just like a CPU Cache simulator where it functions depending on the word address that is provided by the memory.

Features

Supports different total number of cache entries and set associativity.

Follows a Random Replacement Algorithm when blocks have to be removed from a set due to space constraints.

Memory management is done dynamically.

Results are displayed accurately in cache_sim_output.

How to Build

To compile the code, use the following command to go to the code directory and execute:

g++ main.cpp cache.cpp -o cache_sim


How to Run

Execute the program with the parameters cache size, cache associativity, and memory address file.

./cache_sim <num_entries> <associativity> <memory_reference_file>


Example:

./cache_sim 4 2 my_input.txt


Output

An output file called "cache_sim_output" will be generated in the same directory where the executable (.exe) file is stored. The format of each entry in the output file is:
ADDR: HIT or ADDR: MISS for each memory access performed by the program on the input file.

Problems/Limitations

Replacement Policies: It is impossible for us to use any replacement policy other than random because no replacement policies have been programmed.

Multi-word block: Multi-word block is yet to be done.

All data must be numeric.
