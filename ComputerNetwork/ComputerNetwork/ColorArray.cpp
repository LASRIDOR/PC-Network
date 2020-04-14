//
// Created by Nadav Suliman on 10/4/20.
//

#include "ColorArray.h"
using namespace std;

//-----------------------------------------------------------------------------
ColorArray::ColorArray(int size) : size(size) {
    array = new bool[size + 1];

    for (int i = 0; i <= size; i ++) {
        array[i] = WHITE;
    }
}
//-----------------------------------------------------------------------------
ColorArray::ColorArray(const ColorArray& other) {
    this->array = new bool[other.size];
    this->size = other.size;
    for (int i = 0; i < this->size;i++) {
        this->array[i] = other.array[i];
    }
}
//-----------------------------------------------------------------------------
ColorArray::ColorArray(ColorArray&& other) {
    this->array = other.array;
    this->size = other.size;

    other.array = nullptr;
    other.size = -1;
}
//-----------------------------------------------------------------------------
ColorArray::~ColorArray() {
    delete array;
}

void ColorArray::setBlack(int index) {
    array[index] = BLACK;
}

void ColorArray::printAccessibles() const {
    cout << "{ ";
    for (int i = 1; i <= size; i++) {
        if (array[i] == BLACK) {
            cout << i << " ";
        }
    }
    cout << "}" << endl;
}

bool ColorArray::isWhite(int ComputerID) {
    if (this->array[ComputerID] == WHITE) {
        return true;
    }
    else {
        return false;
    }
}

bool ColorArray::operator[](int index) const {
    if (index <= size && index >= 0) {
        return this->array[index];
    } else {
        cout << "Index out of bounds!";
        exit(1);
    }
}
