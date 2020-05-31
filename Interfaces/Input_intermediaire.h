#ifndef INPUT_INTERMEDIAIRE_H
#define INPUT_INTERMEDIAIRE_H
#include "Input.h"
#include <vector>
/**
 * classe contenant les inputs intermediaires, heritant de la classe input
 */
class Input_intermediaire : public Input{
private:
    //vecteur contenant la description de la classe input intermediare
    vector<double> v_intermediare;
public:
    Input_intermediaire(char label);
    void add(double val);
    double operator[](int index);
    char get_label();
};


#endif //INPUT_INTERMEDIAIRE_H
