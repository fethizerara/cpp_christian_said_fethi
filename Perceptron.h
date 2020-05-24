#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "Fonction_activation.h"
#include "Input.h"
class Perceptron {
private:
    double* poids;
    int taille_poids;
    Fonction_activation* fonctionActivation;
    double delta;
    char label;
public:
    Perceptron(int taille_input, Fonction_activation* f, char label);
    double get_poids(int index);
    double forward(Input* input);
    double calcul_delta(Input *input);
    double get_delta();
    void backprop(Input* input, double pas);
};


#endif //PERCEPTRON_H
