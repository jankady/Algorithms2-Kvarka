#include "Program.h"

#include <vector>

#include "Macro.h"

using namespace std;

void Program::process_deprecated(vector<int> &program, vector<Macro> &macros) {
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
        Macro* macro = new Macro();
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
