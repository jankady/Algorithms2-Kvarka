//
// Created by Jan Kaduch on 06.11.2026.
//

#ifndef ALG2PROJEKT_PROGRAM_H
#define ALG2PROJEKT_PROGRAM_H
#include <unordered_map>
#include <vector>

#include "Macro.h"


class Program {

private:
    void initProgram(std::unordered_map<size_t, int> *hashMap, std::vector<int> &program, int* nextOpCode);
    std::pair<unsigned long, int> findMax(const std::unordered_map<size_t, int> &hashmap);

public:
    void processDeprecated(std::vector<int> &program, std::vector<Macro> &macros);
    void processEfficient(std::vector<int> &program, std::vector<Macro> &macros);
};


#endif //ALG2PROJEKT_PROGRAM_H
