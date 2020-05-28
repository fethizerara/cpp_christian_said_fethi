#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "Fonctionactivation.h"
#include "Input.h"
#include <vector>
class Perceptron {
protected:
    double *poids;
    int taille_poids;
    Fonctionactivation* fonctionActivation;
    double delta;
    char label;
public:
    Perceptron(int taille_input, Fonctionactivation* f, char label);
    double get_poids(int index);
    double forward(Input* input);
    double calcul_delta(Input *input);
    double get_delta();
    void backprop(Input* input, double pas);
};


#endif //PERCEPTRON_H
