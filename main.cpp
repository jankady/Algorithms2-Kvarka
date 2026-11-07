#include <iostream>

#include "Program.h"


using namespace std;


// Generuje testovaci program s nahodnymi instrukcemi v rozsahu minOpcode a maxOpcode
vector<int> generateTestInstructions(int minOpcode, int maxOpcode, int programSize) {
    vector<int> program;
    for (int i = 0; i < programSize; i++) {
        program.push_back(rand() % (maxOpcode - minOpcode + 1) + minOpcode);
    }
    return program;
}

void printInstructions(const vector<int> &program, const vector<Macro> &macros) {
    cout << "Makroinstrukce:\n";
    for (int i = 0; i < (int) macros.size(); i++) {
        cout << macros[i].opcode << "-> " << macros[i].first << " " << macros[i].second << std::endl;
    }
    cout << "Program:\n";
    for (int i = 0; i < (int) program.size(); i++) { cout << program[i] << " "; }
    cout << std::endl;
}

int main() {
    vector<int> myLittleProgram = generateTestInstructions(1, 5, 15);
    vector<Macro> myMacros;
    Program *myProgram = new Program();
    printInstructions(myLittleProgram, myMacros);
    // myProgram->processDeprecated(myLittleProgram, myMacros);
    // printInstructions(myLittleProgram, myMacros);

    myProgram->processEfficient(myLittleProgram, myMacros);

}
