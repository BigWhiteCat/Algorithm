#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

/*!
 * \brief The Exception class
 */
class Exception {
  public:
    /*!
     * \brief ~Exception
     */
    virtual ~Exception();

    /*!
     * \brief outputMessage
     */
    virtual void outputMessage() const = 0;
};

/*!
 * \brief The IllegalParameterValue class
 */
class IllegalParameterValue : public Exception {
  public:
    /*!
     * \brief IllegalParameterValue
     * \param theMessage
     */
    IllegalParameterValue(const std::string theMessage = "Illegal parameter value");
    /*!
     * \brief outputMessage
     */
    virtual void outputMessage() const override;

  private:
    std::string message; /*!<*/
};

/*!
 * \brief The IllegalInputData class
 */
class IllegalInputData : public Exception {
  public:
    /*!
     * \brief IllegalInputData
     * \param theMessage
     */
    IllegalInputData(const std::string theMessage = "Illegal data input");
    /*!
     * \brief outputMessage
     */
    virtual void outputMessage() const override;

  private:
    std::string message; /*!<*/
};

/*!
 * \brief The IllegalIndex class
 */
class IllegalIndex : public Exception {
  public:
    /*!
     * \brief IllegalIndex
     * \param theMessage
     */
    IllegalIndex(std::string theMessage = "Illegal index");
    /*!
     * \brief outputMessage
     */
    virtual void outputMessage() const override;

  private:
    std::string message; /*!<*/
};

/*!
 * \brief The MatrixIndexOutofBounds class
 */
class MatrixIndexOutofBounds : public Exception {
  public:
    /*!
     * \brief MatrixIndexOutofBounds
     * \param theMessage
     */
    MatrixIndexOutofBounds(const std::string theMessage = "Matrix index out of bounds");
    /*!
     * \brief outputMessage
     */
    virtual void outputMessage() const override;

  private:
    std::string message; /*!<*/
};

/*!
 * \brief The MatrixSizeMismatch class
 */
class MatrixSizeMismatch : public Exception {
  public:
    /*!
     * \brief MatrixSizeMismatch
     * \param theMessage
     */
    MatrixSizeMismatch(const std::string theMessage = "The size of the two matrics doesn't match");
    /*!
     * \brief outputMessage
     */
    virtual void outputMessage() const override;

  private:
    std::string message; /*!<*/
};

/*!
 * \brief The StackEmpty class
 */
class StackEmpty : public Exception {
  public:
    /*!
     * \brief StackEmpty
     * \param theMessage
     */
    StackEmpty(const std::string theMessage = "Invalid operation on empty stack");
    /*!
     * \brief outputMessage
     */
    virtual void outputMessage() const override;

  private:
    std::string message; /*!<*/
};

/*!
 * \brief The QueueEmpty class
 */
class QueueEmpty : public Exception {
  public:
    /*!
     * \brief QueueEmpty
     * \param theMessage
     */
    QueueEmpty(const std::string theMessage = "Invalid operation on empty queue");
    /*!
     * \brief outputMessage
     */
    virtual void outputMessage() const override;

  private:
    std::string message; /*!<*/
};

/*!
 * \brief The HashTableFull class
 */
class HashTableFull : public Exception {
  public:
    /*!
     * \brief HashTableFull
     * \param theMessage
     */
    HashTableFull(const std::string theMessage = "The hash table is full");
    /*!
     * \brief outputMessage
     */
    virtual void outputMessage() const override;

  private:
    std::string message; /*!<*/
};

/*!
 * \brief The UndefinedEdgeWeight class
 */
class UndefinedEdgeWeight : public Exception {
  public:
    /*!
     * \brief UndefinedEdgeWeight
     * \param theMessage
     */
    UndefinedEdgeWeight(const std::string theMessage = "No edge weights defined");
    /*!
     * \brief outputMessage
     */
    virtual void outputMessage() const override;

  private:
    std::string message; /*!<*/
};

/*!
 * \brief The UndefinedMethod class
 */
class UndefinedMethod : public Exception {
  public:
    /*!
     * \brief UndefinedMethod
     * \param theMessage
     */
    UndefinedMethod(const std::string theMessage = "This method is undefined");
    /*!
     * \brief outputMessage
     */
    virtual void outputMessage() const override;

  private:
    std::string message; /*!<*/
};

#endif  // EXCEPTION_H
