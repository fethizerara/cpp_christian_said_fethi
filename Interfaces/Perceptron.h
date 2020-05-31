#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "Fonctionactivation.h"
#include "Input.h"
#include <vector>
/**
 * classe Perceptron
 */
class Perceptron {
protected:
    //pointeur sur des doubles, que nous allons initialiser selon le type d'input
    double *poids;
    //la taille du tableau que va contenir le pointeur dependra de la taille des inputs
    int taille_poids;
    //fonction d'activation du perceptron
    Fonctionactivation* fonctionActivation;
    //champ delta
    double delta;
    //label du perceptron
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
