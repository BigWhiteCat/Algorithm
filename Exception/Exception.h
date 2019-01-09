#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

/*!
 * \brief The Exception class
 */
class Exception {
  public:
    virtual ~Exception();

    virtual void outputMessage() const = 0;
};

/*!
 * \brief The IllegalParameterValue class
 */
class IllegalParameterValue : public Exception {
  public:
    IllegalParameterValue(const std::string theMessage = "Illegal parameter value");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

/*!
 * \brief The IllegalInputData class
 */
class IllegalInputData : public Exception {
  public:
    IllegalInputData(const std::string theMessage = "Illegal data input");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

/*!
 * \brief The IllegalIndex class
 */
class IllegalIndex : public Exception {
  public:
    IllegalIndex(std::string theMessage = "Illegal index");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

/*!
 * \brief The MatrixIndexOutofBounds class
 */
class MatrixIndexOutofBounds : public Exception {
  public:
    MatrixIndexOutofBounds(const std::string theMessage = "Matrix index out of bounds");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

/*!
 * \brief The MatrixSizeMismatch class
 */
class MatrixSizeMismatch : public Exception {
  public:
    MatrixSizeMismatch(const std::string theMessage = "The size of the two matrics doesn't match");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

/*!
 * \brief The StackEmpty class
 */
class StackEmpty : public Exception {
  public:
    StackEmpty(const std::string theMessage = "Invalid operation on empty stack");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

/*!
 * \brief The QueueEmpty class
 */
class QueueEmpty : public Exception {
  public:
    QueueEmpty(const std::string theMessage = "Invalid operation on empty queue");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

/*!
 * \brief The HashTableFull class
 */
class HashTableFull : public Exception {
  public:
    HashTableFull(const std::string theMessage = "The hash table is full");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

/*!
 * \brief The UndefinedEdgeWeight class
 */
class UndefinedEdgeWeight : public Exception {
  public:
    UndefinedEdgeWeight(const std::string theMessage = "No edge weights defined");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

/*!
 * \brief The UndefinedMethod class
 */
class UndefinedMethod : public Exception {
  public:
    UndefinedMethod(const std::string theMessage = "This method is undefined");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

#endif  // EXCEPTION_H
