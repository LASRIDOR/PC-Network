//
// Created by Nadav Suliman on 10/4/20.
//

#ifndef PC_NETWORK_COMPUTER_H
#define PC_NETWORK_COMPUTER_H

//#define WHITE false;
//#define BLACK true;

class Computer {
private:
    int id;
    bool Color; //black or white
public:
    Computer(int id);

    bool operator==(const Computer& other);

    int getID() const;
    void setID(int newID);
 //   void ChangeColorTo(bool color);

};


#endif //PC_NETWORK_COMPUTER_H
