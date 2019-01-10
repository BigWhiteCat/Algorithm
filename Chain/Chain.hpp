#ifndef CHAIN_HPP
#define CHAIN_HPP

#include <sstream>

#include "../Exception/Exception.h"
#include "../include/LinearList.hpp"
#include "ChainNode.hpp"

template <typename T>
class Chain : public LinearList<T> {
  public:
    Chain(int initialCapacity = 10);
    Chain(const Chain<T> &theChain);
    ~Chain();

    bool empty() const;
    int size() const;
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output(std::ostream &out) const;

  private:
    void checkIndex(int theIndex) const;
    ChainNode<T> *firstNode; /*!< first node of chain*/
    int listSize;            /*!< the size of chain*/
};

template <typename T>
Chain<T>::Chain(int initialCapacity) {
    if (initialCapacity < 1) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " must be > 0";
        throw IllegalParameterValue(s.str());
    }

    firstNode = nullptr;
    listSize = 0;
}

template <typename T>
Chain<T>::Chain(const Chain<T> &theChain) {
    listSize = theChain.listSize;

    if (listSize == 0) {
        firstNode = nullptr;
        return;
    }

    ChainNode<T> *sourceNode = theChain.firstNode;
    firstNode = new ChainNode<T>(sourceNode->element);
    ChainNode<T> *targetNode = firstNode;
    sourceNode = sourceNode->next;
    while (sourceNode != nullptr) {
        targetNode->next = new ChainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = nullptr;
}

template <typename T>
Chain<T>::~Chain() {
    while (firstNode != nullptr) {
        ChainNode<T> *nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template <typename T>
bool Chain<T>::empty() const {
    return listSize == 0;
}

template <typename T>
int Chain<T>::size() const {
    return listSize;
}

template <typename T>
T &Chain<T>::get(int theIndex) const {
    checkIndex(theIndex);

    ChainNode<T> *currentNode = firstNode;
    for (int i = 0; i < theIndex; ++i) {
        /*! currentNode point to the theIndex */
        currentNode = currentNode->next;
    }

    return currentNode->element;
}

template <typename T>
int Chain<T>::indexOf(const T &theElement) const {
    int i = 0;
    ChainNode<T> *currentNode;
    for (currentNode = firstNode; currentNode != nullptr && currentNode->element != theElement; currentNode = currentNode->next) {
        ++i;
    }

    if (currentNode == nullptr) {
        return -1;
    } else {
        return i;
    }

    return -1;
}

template <typename T>
void Chain<T>::erase(int theIndex) {
    checkIndex(theIndex);

    ChainNode<T> *deleteNode;
    if (theIndex == 0) {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {
        ChainNode<T> *currentNode = firstNode;
        for (int i = 0; i != theIndex - 1; ++i) {
            /*! the currentNode point to the theIndex -1*/
            currentNode = currentNode->next;
        }

        deleteNode = currentNode->next;
        currentNode->next = currentNode->next->next;
    }

    --listSize;
    delete deleteNode;
}

template <typename T>
void Chain<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw IllegalIndex(s.str());
    }

    if (theIndex == 0) {
        firstNode = new ChainNode<T>(theElement, firstNode);
    } else {
        ChainNode<T> *currentNode = firstNode;
        for (int i = 0; i != theIndex - 1; ++i) {
            currentNode = currentNode->next;
        }
        currentNode->next = new ChainNode<T>(theElement, currentNode->next);
    }

    ++listSize;
}

template <typename T>
void Chain<T>::output(std::ostream &out) const {
    for (ChainNode<T> *currentNode = firstNode; currentNode != nullptr; currentNode = currentNode->next) {
        out << currentNode->element << "   ";
    }
}

template <typename T>
void Chain<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw IllegalIndex(s.str());
    }
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Chain<T> &theChain) {
    theChain.output(out);
    return out;
}

#endif  // CHAIN_HPP
