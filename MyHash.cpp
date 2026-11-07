//
// Created by Jan Kaduch on 07.11.2026.
//

#include "MyHash.h"

#include <string>

uint64_t MyHash::getKeyFromPairs(int k1, int k2) {
    uint64_t hash = (uint64_t) k1 << 32;
    hash |= (uint32_t) k2;
    return hash;


}

int MyHash::getFirst(uint64_t hash) {
    return (int) (hash >> 32);
}

int MyHash::getSecond(uint64_t hash) {
    return (int) hash;
}
