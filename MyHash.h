
#ifndef ALG2PROJEKT_MYHASH_H
#define ALG2PROJEKT_MYHASH_H
#include <utility>

class MyHash {

public:
    static uint64_t getKeyFromPairs(int k1, int k2);

    static int getFirst(uint64_t hash);
    static int getSecond(uint64_t hash);
};


#endif
