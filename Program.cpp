#include "Program.h"

#include <iostream>
#include <unordered_map>
#include <vector>

#include "Macro.h"
#include "MyHash.h"

using namespace std;

void Program::processDeprecated(vector<int> &program, vector<Macro> &macros) {
    if (program.empty()) return;
    // Najdi nejvyssi pouzity kod instrukce v programu
    int nextOpcode = program[0];
    for (int i = 1; i < (int) program.size(); i++) {
        if (program[i] > nextOpcode) nextOpcode = program[i];
    }
    // Predpoklad vstupu: je mozne pridelovat dalsi kody bez preteceni int.
    nextOpcode++;
    while (program.size() >= 2) {
        // 1. Spocitani cetnosti vsech dvojic po sobe jdoucich instrukci
        vector<vector<int> > counts(nextOpcode + 1, vector<int>(nextOpcode + 1, 0));
        for (int i = 0; i + 1 < (int) program.size(); i++) {
            counts[program[i]][program[i + 1]]++;
        }

        // 2. Vyber nejcastejsi dvojice
        int bestCount = 0;
        int bestOpcode = 0;
        int bestOpcode2 = 0;
        for (int i = 0; i <= nextOpcode; i++) {
            for (int j = 0; j <= nextOpcode; j++) {
                if (counts[i][j] > bestCount) {
                    bestCount = counts[i][j];
                    bestOpcode = i;
                    bestOpcode2 = j;
                }
            }
        }
        if (bestCount < 2) break;

        // 3. Ulozeni definice nove makroinstrukce
        Macro *macro = new Macro();
        macro->opcode = nextOpcode;
        macro->first = bestOpcode;
        macro->second = bestOpcode2;
        macros.push_back(*macro);

        // 4. Vytvoreni noveho programu
        vector<int> result;
        for (int i = 0; i < (int) program.size();) {
            if (i + 1 < (int) program.size() && program[i] == bestOpcode && program[i + 1] == bestOpcode2) {
                result.push_back(nextOpcode);
                i += 2;
            } else {
                result.push_back(program[i]);
                i++;
            }
        }
        program = result; // puvodni program se zahodi
        nextOpcode++;
    }
}

// Time complexity O(n) depends on program length
void Program::initProgram(unordered_map<size_t, int> *hashMap, vector<int> &program, int *biggestOpCode) {
    for (int i = 0; i < program.size() - 1; i++) {
        int firstNum = program[i];
        int secondNum = program[i + 1];
        if (firstNum > *biggestOpCode) *biggestOpCode = firstNum;
        if (secondNum > *biggestOpCode) *biggestOpCode = secondNum;
        const uint64_t neighboursHash = MyHash::getKeyFromPairs(firstNum, secondNum);
        (*hashMap)[neighboursHash]++;
    }
}

void testPrint(unordered_map<size_t, int> hashmap, int nextOpCode) {
    std::cout << "nextOpCode: " << nextOpCode << std::endl;
    for (const auto &entry: hashmap) {
        int k1 = MyHash::getFirst(entry.first);
        int k2 = MyHash::getSecond(entry.first);
        std::cout << "key=(" << k1 << "," << k2 << ") count=" << entry.second << std::endl;
    }
}

void Program::processEfficient(vector<int> &program, vector<Macro> &macros) {
    if (program.size() < 2) return;
    int nextOpCode = 0;
    unordered_map<size_t, int> hashmap;
    initProgram(&hashmap, program, &nextOpCode); // O(n)
    testPrint(hashmap, nextOpCode);


}
