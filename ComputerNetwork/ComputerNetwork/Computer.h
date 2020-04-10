//
// Created by Nadav Suliman on 10/4/20.
//

#ifndef PC_NETWORK_COMPUTER_H
#define PC_NETWORK_COMPUTER_H


class Computer {
private:
    int id;

public:
    Computer(int id);

    bool operator==(const Computer& other);

    int getID() const;
    void setID(int newID);

};


#endif //PC_NETWORK_COMPUTER_H
