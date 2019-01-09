#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <algorithm>
#include <iterator>
#include <sstream>

#include "../Exception/Exception.h"
#include "../include/LinearList.hpp"
#include "../include/changeLength1D.hpp"

/*!
 * \brief The ArrayList class
 */
template <typename T>
class ArrayList : public LinearList<T> {
  public:
    ArrayList(int initialCapacity = 10);
    ArrayList(const ArrayList<T> &theArrayList);
    ~ArrayList();

    bool empty() const;
    int size() const;
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output(std::ostream &out) const;

    int capacity() const;

  protected:
    void checkIndex(int theIndex) const;
    T *element;      /*!< pointer*/
    int arrayLength; /*!< array length*/
    int listSize;    /*!< the size of array list*/
};

/*!
 * \brief ArrayList<T>::ArrayList
 * \param initialCapacity
 */
template <typename T>
ArrayList<T>::ArrayList(int initialCapacity) : listSize(0) {
    if (initialCapacity < 1) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " must be > 0";
        throw IllegalParameterValue(s.str());
    }

    arrayLength = initialCapacity;
    element = new T[arrayLength];
}

/*!
 * \brief ArrayList<T>::ArrayList
 * \param theArrayList
 */
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &theArrayList) {
    arrayLength = theArrayList.arrayLength;
    listSize = theArrayList.listSize;
    element = new T[arrayLength];

    std::copy(theArrayList.element, theArrayList.element + listSize, element);
}

/*!
 * \brief ArrayList<T>::~ArrayList
 */
template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] element;
}

/*!
 * \brief ArrayList<T>::empty
 * \return
 */
template <typename T>
bool ArrayList<T>::empty() const {
    return listSize == 0;
}

/*!
 * \brief ArrayList<T>::size
 * \return
 */
template <typename T>
int ArrayList<T>::size() const {
    return listSize;
}

/*!
 * \brief ArrayList<T>::get
 * \param theIndex
 * \return
 */
template <typename T>
T &ArrayList<T>::get(int theIndex) const {
    checkIndex(theIndex);
    return element[theIndex];
}

/*!
 * \brief ArrayList<T>::indexOf
 * \param theElement
 * \return
 */
template <typename T>
int ArrayList<T>::indexOf(const T &theElement) const {
    int theIndex = static_cast<int>(std::find(element, element + listSize, theElement) - element);

    if (theIndex == listSize) {
        return -1;
    } else {
        return theIndex;
    }
}

/*!
 * \brief ArrayList<T>::erase
 * \param theIndex
 */
template <typename T>
void ArrayList<T>::erase(int theIndex) {
    checkIndex(theIndex);

    std::copy(element + theIndex + 1, element + listSize, element + theIndex);
    element[--listSize].~T();
}

/*!
 * \brief ArrayList<T>::insert
 * \param theIndex
 * \param theElement
 */
template <typename T>
void ArrayList<T>::insert(int theIndex, const T &theElement) {
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
 * \brief ArrayList<T>::output
 * \param out
 */
template <typename T>
void ArrayList<T>::output(std::ostream &out) const {
    std::copy(element, element + listSize, std::ostream_iterator<T>(std::cout, " "));
}

/*!
 * \brief ArrayList<T>::capacity
 * \return
 */
template <typename T>
int ArrayList<T>::capacity() const {
    return arrayLength;
}

/*!
 * \brief ArrayList<T>::checkIndex
 * \param theIndex
 */
template <typename T>
void ArrayList<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw IllegalIndex(s.str());
    }
}

/*!
 * \brief operator <<
 * \param out
 * \param theArrayList
 * \return
 */
template <typename T>
std::ostream &operator<<(std::ostream &out, const ArrayList<T> &theArrayList) {
    theArrayList.output(out);
    return out;
}

#endif  // ARRAYLIST_H
