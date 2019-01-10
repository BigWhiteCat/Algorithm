#ifndef CHAINNODE_H
#define CHAINNODE_H

template <typename T>
struct ChainNode {
    ChainNode();
    ChainNode(const T& element);
    ChainNode(const T& element, ChainNode<T>* nextChainNode);

    T element;
    ChainNode<T>* next;
};

template <typename T>
ChainNode<T>::ChainNode() {
}

template <typename T>
ChainNode<T>::ChainNode(const T& element) {
    this->element = element;
}

template <typename T>
ChainNode<T>::ChainNode(const T& element, ChainNode<T>* next) {
    this->element = element;
    this->next = next;
}

#endif  // CHAINNODE_H
