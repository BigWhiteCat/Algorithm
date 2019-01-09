#ifndef LINEARLIST_HPP
#define LINEARLIST_HPP

#include <iostream>

/*!
 * \brief The LinearList class
 */
template <typename T>
class LinearList {
  public:
    /*!
     * \brief ~LinearList
     */
    virtual ~LinearList() {
    }

    /*!
     * \brief empty
     * \return
     */
    virtual bool empty() const = 0;
    /*!
     * \brief size
     * \return
     */
    virtual int size() const = 0;
    /*!
     * \brief get
     * \param theIndex
     * \return
     */
    virtual T& get(int theIndex) const = 0;
    /*!
     * \brief indexOf
     * \param theElement
     * \return
     */
    virtual int indexOf(const T& theElement) const = 0;
    /*!
     * \brief erase
     * \param theIndex
     */
    virtual void erase(int theIndex) = 0;
    /*!
     * \brief insert
     * \param theIndex
     * \param theElement
     */
    virtual void insert(int theIndex, const T& theElement) = 0;
    /*!
     * \brief output
     * \param out
     */
    virtual void output(std::ostream& out) const = 0;
};

#endif
