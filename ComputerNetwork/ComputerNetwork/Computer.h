//
// Created by Nadav Suliman on 10/4/20.
//

#ifndef PC_NETWORK_COMPUTER_H
#define PC_NETWORK_COMPUTER_H

#include <ostream>

class Computer {

private:
    int id;

public:
    Computer() = default;
    Computer(int id);

    bool operator>(const Computer &other);
    bool operator<(const Computer &other);
    bool operator==(const Computer &other);

    int getID() const;
    void setID(int newID);

    friend std::ostream &operator<<(std::ostream &os, const Computer &computer);
};


#endif //PC_NETWORK_COMPUTER_H
