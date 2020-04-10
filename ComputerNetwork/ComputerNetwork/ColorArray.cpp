//
// Created by Nadav Suliman on 10/4/20.
//

#include "ColorArray.h"
using namespace std;

ColorArray::ColorArray(int size) : size(size) {
    array = new bool[size + 1];

    for (int i = 0; i <= size; i ++) {
        array[i] = WHITE;
    }
}

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
    cout << "}";
}

bool ColorArray::operator[](int index) const {
    if (index <= size && index >= 0) {
        return this->array[index];
    } else {
        cout << "Index out of bounds!";
        exit(1);
    }
}
