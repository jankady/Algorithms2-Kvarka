//
// Created by Jan Kaduch on 06.11.2026.
//

#ifndef ALG2PROJEKT_PROGRAM_H
#define ALG2PROJEKT_PROGRAM_H
#include <vector>

#include "Macro.h"


class Program {

private:

public:
    void process_deprecated(std::vector<int> &program, std::vector<Macro> &macros);
    void process_efficient(std::vector<int> &program, std::vector<Macro> &macros);
};


#endif //ALG2PROJEKT_PROGRAM_H
