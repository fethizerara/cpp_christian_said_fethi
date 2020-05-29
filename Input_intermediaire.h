#ifndef INPUT_INTERMEDIAIRE_H
#define INPUT_INTERMEDIAIRE_H


#include "Input.h"
#include <vector>
class Input_intermediaire : public Input{
private:
    vector<double> v_intermediare;
public:
    Input_intermediaire(char label);
    void add(double val);
    double operator[](int index);
    char get_label();
};


#endif //INPUT_INTERMEDIAIRE_H
