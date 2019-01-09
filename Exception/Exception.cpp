#include <iostream>

#include "Exception.h"

Exception::~Exception() {
}

IllegalParameterValue::IllegalParameterValue(const std::string theMessage) {
    message = theMessage;
}

void IllegalParameterValue::outputMessage() const {
    std::cout << message << std::endl;
}

IllegalInputData::IllegalInputData(const std::string theMessage) {
    message = theMessage;
}

void IllegalInputData::outputMessage() const {
    std::cout << message << std::endl;
}

IllegalIndex::IllegalIndex(std::string theMessage) {
    message = theMessage;
}

void IllegalIndex::outputMessage() const {
    std::cout << message << std::endl;
}

MatrixIndexOutofBounds::MatrixIndexOutofBounds(const std::string theMessage) {
    message = theMessage;
}

void MatrixIndexOutofBounds::outputMessage() const {
    std::cout << message << std::endl;
}

MatrixSizeMismatch::MatrixSizeMismatch(const std::string theMessage) {
    message = theMessage;
}

void MatrixSizeMismatch::outputMessage() const {
    std::cout << message << std::endl;
}

StackEmpty::StackEmpty(const std::string theMessage) {
    message = theMessage;
}

void StackEmpty::outputMessage() const {
    std::cout << message << std::endl;
}

QueueEmpty::QueueEmpty(const std::string theMessage) {
    message = theMessage;
}

void QueueEmpty::outputMessage() const {
    std::cout << message << std::endl;
}

HashTableFull::HashTableFull(const std::string theMessage) {
    message = theMessage;
}

void HashTableFull::outputMessage() const {
    std::cout << message << std::endl;
}

UndefinedEdgeWeight::UndefinedEdgeWeight(const std::string theMessage) {
    message = theMessage;
}

void UndefinedEdgeWeight::outputMessage() const {
    std::cout << message << std::endl;
}

UndefinedMethod::UndefinedMethod(const std::string theMessage) {
    message = theMessage;
}

void UndefinedMethod::outputMessage() const {
    std::cout << message << std::endl;
}
