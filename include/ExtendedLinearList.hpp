#ifndef EXTENDEDLINEARLIST_HPP
#define EXTENDEDLINEARLIST_HPP

#include "LinearList.hpp"

template <typename T>
class ExtendedLinearList : public LinearList<T> {
  public:
    virtual ~ExtendedLinearList() {
    }

    virtual void clear() = 0;
    virtual void push_back(const T& theElement) = 0;
};

#endif  // EXTENDEDLINEARLIST_HPP
