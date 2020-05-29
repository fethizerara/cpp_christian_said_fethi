#ifndef PERCEPTRON_CACHE_H
#define PERCEPTRON_CACHE_H

#include "Perceptron.h"
#include <vector>

class Perceptron_cache : public Perceptron {
private:
    vector<Perceptron *> sortie;
public:
    Perceptron_cache(int taille_input, Fonctionactivation *fonctionactivation, char label,vector<Perceptron *> sorties);
    double calcul_delta(Input* input);
    void backprop(Input* input, double pas);
};

#endif //PERCEPTRON_CACHE_H
