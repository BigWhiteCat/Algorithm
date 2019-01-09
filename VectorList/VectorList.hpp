#ifndef VECTORLIST_HPP
#define VECTORLIST_HPP

#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>

#include "../Exception/Exception.h"
#include "../include/LinearList.hpp"

/*!
 * \brief The VectorList class
 */
template <typename T>
class VectorList : public LinearList<T> {
  public:
    VectorList(int initialCapacity = 10);
    VectorList(const VectorList<T> &theVectorList);
    ~VectorList();

    /*! ADT */
    bool empty() const;
    int size() const;
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output(std::ostream &out) const;
    int capacity() const;

    typedef typename std::vector<T>::iterator iterator;
    iterator begin();
    iterator end();

  private:
    void checkIndex(int theIndex) const;
    std::vector<T> *element;
};

/*!
 * Constructor
 *
 * \param initialCapacity the initial capacity of VectorList
 */
template <typename T>
VectorList<T>::VectorList(int initialCapacity) {
    if (initialCapacity < 1) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " must be > 0";
        throw IllegalParameterValue(s.str());
    }

    element = new std::vector<T>;
    element->reserve(initialCapacity);
}

/*!
 * \brief VectorList<T>::VectorList Copy Constructor
 * \param theVectorList
 */
template <typename T>
VectorList<T>::VectorList(const VectorList<T> &theVectorList) {
    element = new std::vector<T>(*theVectorList.element);
}

/*!
 * \brief VectorList<T>::~VectorList
 */
template <typename T>
VectorList<T>::~VectorList() {
    delete element;
}

/*!
 * \brief VectorList<T>::empty
 * \return
 */
template <typename T>
bool VectorList<T>::empty() const {
    return element->empty();
}

/*!
 * \brief VectorList<T>::size
 * \return
 */
template <typename T>
int VectorList<T>::size() const {
    return element->size();
}

/*!
 * \brief VectorList<T>::get
 * \param theIndex
 * \return
 */
template <typename T>
T &VectorList<T>::get(int theIndex) const {
    checkIndex(theIndex);
    return element->at(theIndex);
}

/*!
 * \brief VectorList<T>::indexOf
 * \param theElement
 * \return
 */
template <typename T>
int VectorList<T>::indexOf(const T &theElement) const {
    int theIndex = static_cast<int>(find(element->begin(), element->end(), theElement) - element->begin());

    if (theIndex == size()) {
        return -1;
    } else {
        return theIndex;
    }
}

/*!
 * \brief VectorList<T>::erase
 * \param theIndex
 */
template <typename T>
void VectorList<T>::erase(int theIndex) {
    checkIndex(theIndex);
    element->erase(begin() + theIndex);
}

/*!
 * \brief VectorList<T>::insert
 * \param theIndex
 * \param theElement
 */
template <typename T>
void VectorList<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > size()) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << size();
        throw IllegalIndex(s.str());
    }

    element->insert(element->begin() + theIndex, theElement);
}

/*!
 * \brief VectorList<T>::output
 * \param out
 */
template <typename T>
void VectorList<T>::output(std::ostream &out) const {
    std::copy(element->begin(), element->end(), std::ostream_iterator<T>(out, "  "));
}

/*!
 * \brief VectorList<T>::capacity
 * \return
 */
template <typename T>
int VectorList<T>::capacity() const {
    return element->capacity();
}

/*!
 * \brief VectorList<T>::begin
 * \return
 */
template <typename T>
typename VectorList<T>::iterator VectorList<T>::begin() {
    return element->begin();
}

/*!
 * \brief VectorList<T>::end
 * \return
 */
template <typename T>
typename VectorList<T>::iterator VectorList<T>::end() {
    return element->end();
}

/*!
 * \brief VectorList<T>::checkIndex
 * \param theIndex
 * \return
 */
template <typename T>
void VectorList<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= static_cast<int>(element->size())) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << element->size();
        throw IllegalIndex(s.str());
    }
}

/*!
 * \brief operator <<
 * \param out
 * \param theVectorList
 * \return
 */
template <typename T>
std::ostream &operator<<(std::ostream &out, const VectorList<T> &theVectorList) {
    theVectorList.output(out);
    return out;
}

#endif  // VECTORLIST_HPP
