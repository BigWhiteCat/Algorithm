#include "../ChainWithIterator/ChainWithIterator.hpp"
#include "Declaration.h"
#include "StudentRecord.h"

void binSort(Chain<StudentRecord> &theChainWithIterator, int range) {
    Chain<StudentRecord> *bin = new Chain<StudentRecord>[range + 1];

    /// 从链表中分配元素
    int numberOfElements = theChainWithIterator.size();
    for (int i = 0; i != numberOfElements; ++i) {
        StudentRecord record = theChainWithIterator.get(0);
        theChainWithIterator.erase(0);
        bin[record.score].insert(0, record);
    }

    /// 收集箱子中的元素使之有序
    for (int i = range; i >= 0; --i) {
        while (!bin[i].empty()) {
            StudentRecord record = bin[i].get(0);
            bin[i].erase(0);
            theChainWithIterator.insert(0, record);
        }
    }

    delete[] bin;
}
