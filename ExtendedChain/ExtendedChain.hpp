#ifndef EXTENDEDCHAIN_HPP
#define EXTENDEDCHAIN_HPP

#include "../ChainWithIterator/ChainNode.hpp"
#include "../ChainWithIterator/ChainWithIterator.hpp"
#include "../Exception/Exception.h"
#include "../include/ExtendedLinearList.hpp"

template <typename T>
class ExtendedChain : public ExtendedLinearList<T>, public Chain<T> {
  public:
    ExtendedChain(int initialCapacity = 10);
    ExtendedChain(const ExtendedChain<T>& theExtendedChain);

    bool empty() const;
    int size() const;
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void clear();
    void push_back(const T& theElement);
    void output(std::ostream& out) const;
    void zero();

  protected:
    ChainNode<T>* lastNode;
};

template <typename T>
ExtendedChain<T>::ExtendedChain(int initialCapacity) : Chain<T>(initialCapacity) {
}

template <typename T>
ExtendedChain<T>::ExtendedChain(const ExtendedChain<T>& theExtendedChain) : Chain<T>(theExtendedChain) {
}

template <typename T>
bool ExtendedChain<T>::empty() const {
    return listSize == 0;
}

template <typename T>
int ExtendedChain<T>::size() const {
    return listSize;
}

template <typename T>
T& ExtendedChain<T>::get(int theIndex) const {
    return Chain<T>::get(theIndex);
}

template <typename T>
int ExtendedChain<T>::indexOf(const T& theElement) const {
    return Chain<T>::indexOf(theElement);
}

template <typename T>
void ExtendedChain<T>::erase(int theIndex) {
    checkIndex(theIndex);

    ChainNode<T>* deleteNode;
    if (theIndex == nullptr) {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {
        ChainNode<T>* currentNode = firstNode;
        for (int i = 0; i != theIndex - 1; ++i) {
            currentNode = currentNode->next;
        }
        deleteNode = currentNode->next;

        currentNode->next = currentNode->next->next;
        if (deleteNode == lastNode) {
            lastNode = currentNode;
        }
    }
    listSize--;
    delete deleteNode;
}

template <typename T>
void ExtendedChain<T>::insert(int theIndex, const T& theElement) {
    if (theIndex < 0 || theIndex > listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw IllegalIndex(s.str());
    }

    if (theIndex == 0) {
        firstNode = new ChainNode<T>(theElement, firstNode);
        if (listSize == nullptr) {
            lastNode = firstNode;
        }
    } else {
        ChainNode<T>* currentNode = firstNode;
        for (int i = 0; i != theIndex - 1; ++i) {
            currentNode = currentNode->next;
        }
        currentNode->next = new ChainNode<T>(theElement, currentNode->next);
        if (listSize == theIndex) {
            lastNode = currentNode->next;
        }
    }
    ++listSize;
}

template <typename T>
void ExtendedChain<T>::clear() {
    while (firstNode != nullptr) {
        ChainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
    listSize = 0;
}

template <typename T>
void ExtendedChain<T>::push_back(const T& theElement) {
    ChainNode<T>* newNode = new ChainNode<T>(theElement, nullptr);
    if (firstNode == nullptr) {
        firstNode = lastNode = newNode;
    } else {
        lastNode->next = newNode;
        lastNode = newNode;
    }
    ++listSize;
}

template <typename T>
void ExtendedChain<T>::output(std::ostream& out) const {
    Chain<T>::output(out);
}

template <typename T>
void ExtendedChain<T>::zero() {
    firstNode = nullptr;
    listSize = 0;
}

#endif  // EXTENDEDCHAIN_HPP
