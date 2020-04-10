//
// Created by Nadav Suliman on 10/4/20.
//

#include "Computer.h"

Computer::Computer(int id) : id(id) {}

int Computer::getID() const {
    return id;
}

void Computer::setID(int newID) {
    this->id = newID;
}

bool Computer::operator==(const Computer& other) {
    return this->id == other.getID();
}

//void Computer::ChangeColorTo(bool color) {
//   this->Color = color;
//}