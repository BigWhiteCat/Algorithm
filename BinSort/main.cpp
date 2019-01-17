#include <iostream>
#include <string>

#include "../ChainWithIterator/ChainWithIterator.hpp"
#include "Declaration.h"
#include "StudentRecord.h"

int main(int argc, char **argv) {
    StudentRecord s;
    Chain<StudentRecord> c;
    for (int i = 1; i <= 20; i++) {
        s.score = i / 2;
        s.name = new std::string(s.score, 'a');
        c.insert(0, s);
    }
    std::cout << "The unsorted chain is" << std::endl;
    std::cout << "  " << c << std::endl;
    binSort(c, 10);
    std::cout << "The sorted chain is" << std::endl;
    std::cout << "  " << c << std::endl;
}
