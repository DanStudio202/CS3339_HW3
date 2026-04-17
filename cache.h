#ifndef CACHE_H
#define CACHE_H

class Entry {
public:
    Entry();
    
    void set_tag(unsigned _tag) { tag = _tag; }
    unsigned get_tag() { return tag; }

    void set_valid(bool _valid) { valid = _valid; }
    bool get_valid() { return valid; }

private:  
    bool valid;
    unsigned tag;
};

class Cache {
public:
    Cache(int entries, int associativity);
    ~Cache();

    bool hit(unsigned long addr);
    void update(unsigned long addr);

private:
    int assoc;
    unsigned num_entries;
    int num_sets;
    Entry **entries;
    
    int get_index(unsigned long addr);
    unsigned get_tag(unsigned long addr);
};

#endif
