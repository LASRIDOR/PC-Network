//
// Created by Nadav Suliman on 10/4/20.
//

#ifndef PC_NETWORK_COLORARRAY_H
#define PC_NETWORK_COLORARRAY_H

#include <iostream>

#define BLACK   true
#define WHITE   false

class ColorArray {
private:
    bool *array;
    int size;

public:
    explicit ColorArray(int size);
    ColorArray(const ColorArray& other);
    ColorArray(ColorArray&& other);
    virtual ~ColorArray();

    void setBlack(int index);
    bool isWhite(int ComputerID);
    void printAccessibles() const;
    bool operator[](int index) const;
};


#endif //PC_NETWORK_COLORARRAY_H
