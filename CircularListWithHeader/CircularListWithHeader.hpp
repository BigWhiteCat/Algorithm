#ifndef CIRCULARLISTWITHHEADER_H
#define CIRCULARLISTWITHHEADER_H

#include <iostream>
#include <sstream>
#include <string>

#include "../Chain/ChainNode.hpp"
#include "../Exception/Exception.h"

template <typename T>
class CircularListWithHeader {
  public:
    CircularListWithHeader();
    virtual ~CircularListWithHeader();

    virtual int size() const;
    virtual int indexOf(const T& theElement) const;
    virtual void insert(int theIndex, const T& theElement);
    virtual void output(std::ostream& out) const;

  protected:
    void checkIndex(int theIndex) const;
    ChainNode<T>* headerNode;
    int listSize;
};

template <typename T>
void CircularListWithHeader<T>::output(std::ostream& out) const {
    for (ChainNode<T>* currentNode = headerNode->next; currentNode != headerNode; currentNode = currentNode->next) {
        out << currentNode->element << "   ";
    }
}

template <typename T>
void CircularListWithHeader<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw IllegalIndex(s.str());
    }
}

template <typename T>
void CircularListWithHeader<T>::insert(int theIndex, const T& theElement) {
    if (theIndex < 0 || theIndex > listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw IllegalIndex(s.str());
    }

    ChainNode<T>* currentNode = headerNode;
    for (int i = 0; i != theIndex; ++i) {
        currentNode = currentNode->next;
    }
    currentNode->next = new ChainNode<T>(theElement, currentNode->next);
    ++listSize;
}

template <typename T>
int CircularListWithHeader<T>::indexOf(const T& theElement) const {
    headerNode->element = theElement;

    ChainNode<T>* currentNode = headerNode->next;
    int index = 0;
    while (currentNode->element != theElement) {
        currentNode = currentNode->next;
        ++index;
    }

    if (currentNode == headerNode) {
        return -1;
    }
    return index;
}

template <typename T>
int CircularListWithHeader<T>::size() const {
    return listSize;
}

template <typename T>
CircularListWithHeader<T>::~CircularListWithHeader() {
}

template <typename T>
CircularListWithHeader<T>::CircularListWithHeader() {
    headerNode = new ChainNode<T>();
    headerNode->next = headerNode;
    listSize = 0;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const CircularListWithHeader<T>& rh) {
    rh.output(out);
    return out;
}

#endif  // CIRCULARLISTWITHHEADER_H
