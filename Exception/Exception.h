#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception {
  public:
    virtual ~Exception();

    virtual void outputMessage() const = 0;
};

class IllegalParameterValue : public Exception {
  public:
    IllegalParameterValue(const std::string theMessage = "Illegal parameter value");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

class IllegalInputData : public Exception {
  public:
    IllegalInputData(const std::string theMessage = "Illegal data input");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

class IllegalIndex : public Exception {
  public:
    IllegalIndex(std::string theMessage = "Illegal index");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

class MatrixIndexOutofBounds : public Exception {
  public:
    MatrixIndexOutofBounds(const std::string theMessage = "Matrix index out of bounds");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

class MatrixSizeMismatch : public Exception {
  public:
    MatrixSizeMismatch(const std::string theMessage = "The size of the two matrics doesn't match");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

class StackEmpty : public Exception {
  public:
    StackEmpty(const std::string theMessage = "Invalid operation on empty stack");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

class QueueEmpty : public Exception {
  public:
    QueueEmpty(const std::string theMessage = "Invalid operation on empty queue");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

class HashTableFull : public Exception {
  public:
    HashTableFull(const std::string theMessage = "The hash table is full");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

class UndefinedEdgeWeight : public Exception {
  public:
    UndefinedEdgeWeight(const std::string theMessage = "No edge weights defined");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

class UndefinedMethod : public Exception {
  public:
    UndefinedMethod(const std::string theMessage = "This method is undefined");
    virtual void outputMessage() const override;

  private:
    std::string message;
};

#endif  // EXCEPTION_H
