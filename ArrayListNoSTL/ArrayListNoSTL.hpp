#ifndef ARRAYLISTNOSTL_HPP
#define ARRAYLISTNOSTL_HPP

#include <sstream>

#include "../Exception/Exception.h"
#include "../include/LinearList.hpp"
#include "../include/changeLength1D.hpp"

/*!
 * \brief The ArrayListNoSTL class
 */
template <class T>
class ArrayListNoSTL : public LinearList<T> {
  public:
    ArrayListNoSTL(int initialCapacity = 10);
    ArrayListNoSTL(const ArrayListNoSTL<T> &theArrayListNoSTL);
    ~ArrayListNoSTL();

    /*! ADT */
    bool empty() const;
    int size() const;
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output(std::ostream &out) const;
    int capacity() const;

  private:
    void checkIndex(int theIndex) const;
    T *element;      /*!<*/
    int arrayLength; /*!<*/
    int listSize;    /*!<*/
};

/*!
 * \brief ArrayListNoSTL<T>::ArrayListNoSTL
 * \param initialCapacity
 */
template <typename T>
ArrayListNoSTL<T>::ArrayListNoSTL(int initialCapacity) {
    if (initialCapacity < 1) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " must be > 0";
        throw IllegalParameterValue(s.str());
    }

    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

/*!
 * \brief ArrayListNoSTL<T>::ArrayListNoSTL
 * \param theArrayListNoSTL
 */
template <typename T>
ArrayListNoSTL<T>::ArrayListNoSTL(const ArrayListNoSTL<T> &theArrayListNoSTL) {
    arrayLength = theArrayListNoSTL.arrayLength;
    listSize = theArrayListNoSTL.listSize;
    element = new T[arrayLength];

    for (int i = 0; i != listSize; ++i) {
        element[i] = theArrayListNoSTL.element[i];
    }
}

/*!
 * \brief ArrayListNoSTL<T>::~ArrayListNoSTL
 */
template <typename T>
ArrayListNoSTL<T>::~ArrayListNoSTL() {
    delete[] element;
}

/*!
 * \brief ArrayListNoSTL<T>::empty
 * \return
 */
template <typename T>
bool ArrayListNoSTL<T>::empty() const {
    return listSize == 0;
}

/*!
 * \brief ArrayListNoSTL<T>::size
 * \return
 */
template <typename T>
int ArrayListNoSTL<T>::size() const {
    return listSize;
}

/*!
 * \brief ArrayListNoSTL<T>::get
 * \param theIndex
 * \return
 */
template <typename T>
T &ArrayListNoSTL<T>::get(int theIndex) const {
    checkIndex(theIndex);
    return element[theIndex];
}

/*!
 * \brief ArrayListNoSTL<T>::indexOf
 * \param theElement
 * \return
 */
template <typename T>
int ArrayListNoSTL<T>::indexOf(const T &theElement) const {
    for (int i = 0; i != listSize; ++i) {
        if (element[i] == theElement) {
            return i;
        }
    }

    return -1;
}

/*!
 * \brief ArrayListNoSTL<T>::erase
 * \param theIndex
 */
template <typename T>
void ArrayListNoSTL<T>::erase(int theIndex) {
    checkIndex(theIndex);

    for (int i = theIndex + 1; i != listSize; ++i) {
        element[i - 1] = element[i];
    }

    element[--listSize].~T();
}

/*!
 * \brief ArrayListNoSTL<T>::insert
 * \param theIndex
 * \param theElement
 */
template <typename T>
void ArrayListNoSTL<T>::insert(int theIndex, const T &theElement) {
    if (theIndex < 0 || theIndex > listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw IllegalIndex(s.str());
    }

    if (listSize == arrayLength) {
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength = arrayLength * 2;
    }

    for (int i = listSize - 1; i >= theIndex; --i) {
        element[i + 1] = element[i];
    }
    element[theIndex] = theElement;

    ++listSize;
}

/*!
 * \brief ArrayListNoSTL<T>::output
 * \param out
 */
template <typename T>
void ArrayListNoSTL<T>::output(std::ostream &out) const {
    for (int i = 0; i != listSize; ++i) {
        out << element[i] << "  ";
    }
}

/*!
 * \brief ArrayListNoSTL<T>::capacity
 * \return
 */
template <typename T>
int ArrayListNoSTL<T>::capacity() const {
    return arrayLength;
}

/*!
 * \brief ArrayListNoSTL<T>::checkIndex
 * \param theIndex
 */
template <typename T>
void ArrayListNoSTL<T>::checkIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw IllegalIndex(s.str());
    }
}

/*!
 * \brief operator <<
 * \param out
 * \param theArrayListNoSTL
 * \return
 */
template <typename T>
std::ostream &operator<<(std::ostream &out, const ArrayListNoSTL<T> &theArrayListNoSTL) {
    theArrayListNoSTL.output(out);
    return out;
}

#endif  // ARRAYLISTNOSTL_HPP
