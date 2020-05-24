#ifndef INPUT_H
#define INPUT_H

#include <iostream>
using namespace std;
#include <string>   // pour std::string

class Input {

protected:
    char label;

public:
    virtual char get_label() = 0;
    virtual double operator[](int indice) = 0;
};
#endif
