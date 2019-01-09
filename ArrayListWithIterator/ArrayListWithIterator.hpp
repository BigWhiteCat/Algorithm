#ifndef ArrayListWithIterator_H
#define ArrayListWithIterator_H

#include <algorithm>
#include <iterator>
#include <sstream>

#include "../Exception/Exception.h"
#include "../include/LinearList.hpp"
#include "../include/changeLength1D.hpp"

template <typename T>
class ArrayListWithIterator : public LinearList<T> {
  public:
    ArrayListWithIterator(int initialCapacity = 10);
    ArrayListWithIterator(const ArrayListWithIterator<T> &theArrayListWithIterator);
    ~ArrayListWithIterator();

    bool empty() const;
    int size() const;
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output(std::ostream &out) const;

    int capacity() const;

    class Iterator;
    Iterator begin();
    Iterator end();

    class Iterator {
      public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        Iterator(T *thePosition = nullptr);

        T &operator*() const;
        T *operator->() const;

        Iterator &operator++();
        Iterator operator++(int);

        Iterator &operator--();
        Iterator operator--(int);

        bool operator==(const Iterator rh) const;
        bool operator!=(const Iterator rh) const;

      protected:
        T *position;
    };

  protected:
    void checkIndex(int theIndex) const;
    T *element;
    int arrayLength;
    int listSize;
};

/*!
 * \brief ArrayListWithIterator<T>::ArrayListWithIterator
 * \param initialCapacity
 */
template <typename T>
ArrayListWithIterator<T>::ArrayListWithIterator(int initialCapacity) : listSize(0) {
    if (initialCapacity < 1) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " must be > 0";
        throw IllegalParameterValue(s.str());
    }

    arrayLength = initialCapacity;
    element = new T[arrayLength];
}

/*!
 * \brief ArrayListWithIterator<T>::ArrayListWithIterator
 * \param theArrayListWithIterator
 */
template <typename T>
ArrayListWithIterator<T>::ArrayListWithIterator(const ArrayListWithIterator<T> &theArrayListWithIterator) {
    arrayLength = theArrayListWithIterator.arrayLength;
    listSize = theArrayListWithIterator.listSize;
    element = new T[arrayLength];

    std::copy(theArrayListWithIterator.element, theArrayListWithIterator.element + listSize, element);
}

/*!
 * \brief ArrayListWithIterator<T>::~ArrayListWithIterator
 */
template <typename T>
ArrayListWithIterator<T>::~ArrayListWithIterator() {
    delete[] element;
}

/*!
 * \brief ArrayListWithIterator<T>::empty
 * \return
 */
template <typename T>
bool ArrayListWithIterator<T>::empty() const {
    return listSize == 0;
}

/*!
 * \brief ArrayListWithIterator<T>::size
 * \return
 */
template <typename T>
int ArrayListWithIterator<T>::size() const {
    return listSize;
}

/*!
 * \brief ArrayListWithIterator<T>::get
 * \param theIndex
 * \return
 */
template <typename T>
T &ArrayListWithIterator<T>::get(int theIndex) const {
    checkIndex(theIndex);
    return element[theIndex];
}

/*!
 * \brief ArrayListWithIterator<T>::indexOf
 * \param theElement
 * \return
 */
template <typename T>
int ArrayListWithIterator<T>::indexOf(const T &theElement) const {
    int theIndex = static_cast<int>(std::find(element, element + listSize, theElement) - element);

    if (theIndex == listSize) {
        return -1;
    } else {
        return theIndex;
    }
}

/*!
 * \brief ArrayListWithIterator<T>::erase
 * \param theIndex
 */
template <typename T>
void ArrayListWithIterator<T>::erase(int theIndex) {
    checkIndex(theIndex);

    std::copy(element + theIndex + 1, element + listSize, element + theIndex);
    element[--listSize].~T();
}

/*!
 * \brief ArrayListWithIterator<T>::insert
 * \param theIndex
 * \param theElement
 */
template <typename T>
void ArrayListWithIterator<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw IllegalIndex(s.str());
    }

    if (listSize == arrayLength) {
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength = 2 * arrayLength;
    }

    std::copy_backward(element + theIndex, element + listSize, element + listSize + 1);
    element[theIndex] = theElement;
    ++listSize;
}

/*!
 * \brief ArrayListWithIterator<T>::output
 * \param out
 */
template <typename T>
void ArrayListWithIterator<T>::output(std::ostream &out) const {
    std::copy(element, element + listSize, std::ostream_iterator<T>(std::cout, " "));
}

/*!
 * \brief ArrayListWithIterator<T>::capacity
 * \return
 */
template <typename T>
int ArrayListWithIterator<T>::capacity() const {
    return arrayLength;
}

/*!
 * \brief ArrayListWithIterator<T>::begin
 * \return
 */
template <typename T>
typename ArrayListWithIterator<T>::Iterator ArrayListWithIterator<T>::begin() {
    return Iterator(element);
}

/*!
 * \brief ArrayListWithIterator<T>::end
 * \return
 */
template <typename T>
typename ArrayListWithIterator<T>::Iterator ArrayListWithIterator<T>::end() {
    return Iterator(element + listSize);
}

/*!
 * \brief ArrayListWithIterator<T>::checkIndex
 * \param theIndex
 */
template <typename T>
void ArrayListWithIterator<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw IllegalIndex(s.str());
    }
}

/*!
 * \brief ArrayListWithIterator<T>::Iterator::Iterator
 * \param thePosition
 */
template <typename T>
ArrayListWithIterator<T>::Iterator::Iterator(T *thePosition) {
    position = thePosition;
}

/*!
 * \brief ArrayListWithIterator<T>::Iterator::operator *
 * \return
 */
template <typename T>
T &ArrayListWithIterator<T>::Iterator::operator*() const {
    return *position;
}

/*!
 * \brief ArrayListWithIterator<T>::Iterator::operator ->
 * \return
 */
template <typename T>
T *ArrayListWithIterator<T>::Iterator::operator->() const {
    return &(*position);
}

/*!
 * \brief ArrayListWithIterator<T>::Iterator::operator ++
 * \return
 */
template <typename T>
typename ArrayListWithIterator<T>::Iterator &ArrayListWithIterator<T>::Iterator::operator++() {
    ++position;
    return *this;
}

/*!
 * \brief ArrayListWithIterator<T>::Iterator::operator ++
 * \return
 */
template <typename T>
typename ArrayListWithIterator<T>::Iterator ArrayListWithIterator<T>::Iterator::operator++(int) {
    Iterator old = *this;
    ++position;
    return old;
}

/*!
 * \brief ArrayListWithIterator<T>::Iterator::operator --
 * \return
 */
template <typename T>
typename ArrayListWithIterator<T>::Iterator &ArrayListWithIterator<T>::Iterator::operator--() {
    --position;
    return *this;
}

/*!
 * \brief ArrayListWithIterator<T>::Iterator::operator --
 * \return
 */
template <typename T>
typename ArrayListWithIterator<T>::Iterator ArrayListWithIterator<T>::Iterator::operator--(int) {
    Iterator old = *this;
    --position;
    return old;
}

/*!
 * \brief ArrayListWithIterator<T>::Iterator::operator ==
 * \param rh
 * \return
 */
template <typename T>
bool ArrayListWithIterator<T>::Iterator::operator==(const Iterator rh) const {
    return position != rh.position;
}

/*!
 * \brief ArrayListWithIterator<T>::Iterator::operator !=
 * \param rh
 * \return
 */
template <typename T>
bool ArrayListWithIterator<T>::Iterator::operator!=(const Iterator rh) const {
    return !(*this == rh);
}

/*!
 * \brief operator <<
 * \param out
 * \param theArrayListWithIterator
 * \return
 */
template <typename T>
std::ostream &operator<<(std::ostream &out, const ArrayListWithIterator<T> &theArrayListWithIterator) {
    theArrayListWithIterator.output(out);
    return out;
}

#endif  // ArrayListWithIterator_H
