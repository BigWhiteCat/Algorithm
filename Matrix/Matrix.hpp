#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include "../Exception/Exception.h"

template <typename T>
class Matrix {
    template <typename U>
    friend std::ostream &operator<<(std::ostream &out, const Matrix<U> &theMatrix);

  public:
    Matrix(int theRows = 0, int theColumns = 0);
    Matrix(const Matrix &matrix);
    virtual ~Matrix();
    int rows() const;
    int columns() const;
    T &operator()(const int i, const int j) const;
    Matrix<T> &operator=(const Matrix<T> &theMatrix);
    Matrix<T> operator+() const;
    Matrix<T> operator+(const Matrix<T> &theMatrix) const;
    Matrix<T> operator-() const;
    Matrix<T> operator-(const Matrix<T> &theMatrix) const;
    Matrix<T> operator*(const Matrix<T> &theMatrix) const;
    Matrix<T> &operator+=(const T &theElement);

  private:
    int theRows;
    int theColumns;
    T *element;
};

template <typename U>
std::ostream &operator<<(std::ostream &out, const Matrix<U> &theMatrix) {
    for (int i = 0; i != theMatrix.theRows; ++i) {
        for (int j = 0; j != theMatrix.theColumns; ++j) {
            out << theMatrix.element[i * theMatrix.theColumns + j] << "  ";
        }
        out << std::endl;
    }
    return out;
}

template <typename T>
Matrix<T>::Matrix(int theRows, int theColumns) {
    if (theRows < 0 || theColumns < 0) {
        throw IllegalParameterValue("Rows and columns must be >= 0");
    }
    if ((theRows == 0 || theColumns == 0) && (theRows != 0 || theColumns != 0)) {
        throw IllegalInputData("Either both or neither rows and columns should be zero");
    }

    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T[theRows * theColumns];
}

template <typename T>
Matrix<T>::Matrix(const Matrix &matrix) {
    theRows = matrix.theRows;
    theColumns = matrix.theColumns;
    element = new T[theRows * theColumns];

    for (int i = 0; i != theRows * theColumns; ++i) {
        element[i] = matrix.element[i];
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    delete[] element;
}

template <typename T>
int Matrix<T>::rows() const {
    return this->theRows;
}

template <typename T>
int Matrix<T>::columns() const {
    return this->columns;
}

template <typename T>
T &Matrix<T>::operator()(const int i, const int j) const {
    if (i < 1 || i > theRows || j < 1 || j > theColumns) {
        throw MatrixIndexOutofBounds();
    }
    return element[(i - 1) * theColumns + j - 1];
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &theMatrix) {
    if (this != &theMatrix) {
        delete[] this->element;
        theRows = theMatrix.theRows;
        theColumns = theMatrix.theColumns;
        element = new T[theRows * theColumns];

        std::copy(theMatrix.element, theMatrix.element + theRows * theColumns, element);
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+() const {
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &theMatrix) const {
    if (theRows != theMatrix.theRows || theColumns != theMatrix.theColumns) {
        throw MatrixSizeMismatch();
    }

    Matrix<T> sum(theRows, theColumns);
    for (int i = 0; i != theRows * theColumns; ++i) {
        sum.element[i] = element[i] + theMatrix.element[i];
    }

    return sum;
}

template <typename T>
Matrix<T> Matrix<T>::operator-() const {
    Matrix<T> minusMatrix(theRows, theColumns);

    for (int i = 0; i != theRows * theColumns; ++i) {
        minusMatrix.element[i] = -(this->element[i]);
    }

    return minusMatrix;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &theMatrix) const {
    return *this + (-theMatrix);
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &theMatrix) const {
    if (theColumns != theMatrix.theRows) {
        throw MatrixSizeMismatch();
    }

    Matrix<T> productMatrix(theRows, theMatrix.theColumns);

    for (int i = 0; i != theRows; ++i) {
        for (int k = 0; k != theMatrix.theColumns; ++k) {
            productMatrix.element[i * theMatrix.theColumns + k] = T{};
            for (int j = 0; j != theColumns; ++j) {
                productMatrix.element[i * theMatrix.theColumns + k] += (*this)(i + 1, j + 1) * theMatrix(j + 1, k + 1);
            }
        }
    }

    return productMatrix;
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const T &theElement) {
    for (int i = 0; i != theRows * theColumns; ++i) {
        element[i] += theElement;
    }

    return *this;
}

#endif  // MATRIX_HPP
