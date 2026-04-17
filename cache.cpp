#include "cache.h"
#include <cstdlib> // required for rand()

// the entry class implementation
Entry::Entry() {
    valid = false;
    tag = 0;
}

// the cache system class implementation
Cache::Cache(int entries, int associativity) {
    num_entries = entries;
    assoc = associativity;
    num_sets = num_entries / assoc; // calculates sets

    // dynamically allocate based on a 2d array
    this->entries = new Entry*[num_sets];
    for (int i = 0; i < num_sets; i++) {
        this->entries[i] = new Entry[assoc];
    }
}

Cache::~Cache() {
    // allocating free for memory
    for (int i = 0; i < num_sets; i++) {
        delete[] entries[i];
    }
    delete[] entries;
}

int Cache::get_index(unsigned long addr) {
    // input index for the simply address number of sets
    return addr % num_sets;
}

unsigned Cache::get_tag(unsigned long addr) {
    // tags the remaining bits from extracted index
    return addr / num_sets;
}

bool Cache::hit(unsigned long addr) {
    int index = get_index(addr);
    unsigned tag = get_tag(addr);

    // searchs the whole map set
    for (int i = 0; i < assoc; i++) {
        if (entries[index][i].get_valid() && entries[index][i].get_tag() == tag) {
            return true; // cache hit
        }
    }
    return false; // cache missed
}

void Cache::update(unsigned long addr) {
    int index = get_index(addr);
    unsigned tag = get_tag(addr);

    // 1. empties invalid slots first
    for (int i = 0; i < assoc; i++) {
        if (!entries[index][i].get_valid()) {
            entries[index][i].set_valid(true);
            entries[index][i].set_tag(tag);
            return; // Placed successfully
        }
    }

    // 2. if a set is full, evict random placement
    int way_to_evict = rand() % assoc;
    entries[index][way_to_evict].set_tag(tag);
    entries[index][way_to_evict].set_valid(true);
}
