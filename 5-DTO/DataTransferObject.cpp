#include <iostream>
#include "../headers/DataTransferObject.h"

// Construct

DataTransferObject::DataTransferObject() {}

DataTransferObject::DataTransferObject(std::string text, char * & array, int size) {
    setSize(size);
    setText(text);
    textToChar(array);
}

DataTransferObject::~DataTransferObject() {
    if (_array == NULL) {
        delete [] _array;
    }
}

// Public Methods

void DataTransferObject::setSize(int size) {
    _size = size;
}

int DataTransferObject::getSize() {
    return _size;
}

void DataTransferObject::setText(std::string text) {
    _array = nullptr;
    _array = new char[getSize()];
    
    if (getLenght(text) == 0) {
        _array = nullptr;
    }

    if (_array != nullptr) {
        for (int i = 0; i < getLenght(text); i ++) {
            _array[i] = text[i];
        }

        _array[getSize() - 1] = '\0';
        _array[getLenght(text)] = '\0';
    }
}

void DataTransferObject::textToChar(char * & array) {
    array = _array;
}

// Private Methods

int DataTransferObject::getLenght(std::string text) {
    int lenght = 0;
    int & i = lenght;

    while (text[i] != '\0') {
        lenght ++;
    }

    return lenght;
}