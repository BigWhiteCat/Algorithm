#ifndef CHAINWITHBINSORT_H
#define CHAINWITHBINSORT_H

#include <iostream>
#include <string>

#include "../include/LinearList.hpp"
#include "ChainNode.hpp"

template <typename T>
class ChainWithBinSort : public LinearList<T> {
  public:
    ChainWithBinSort(int initialCapacity = 10);
    ChainWithBinSort(const ChainWithBinSort<T>& theChainWithBinSort);
    virtual ~ChainWithBinSort();

    bool empty() const;
    int size() const;
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(std::ostream& out) const;

  protected:
    void checkIndex(int theIndex) const;
    ChainNode<T>* firstNode;
    int listSize;
};

#endif  // CHAINWITHBINSORT_H
