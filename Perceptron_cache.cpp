//
// Created by Ravoavy Christian on 27/05/2020.
//

#include "Perceptron_cache.h"

Perceptron_cache::Perceptron_cache(int taille_input, Fonctionactivation * fonctionactivation, char label, vector<Perceptron *> sorties)
        : Perceptron(taille_input, fonctionactivation, label) {
    this->sortie = sorties;
};

double Perceptron_cache::calcul_delta(Input *input) {
    double w=poids[0];
    for(int i=1; i<taille_poids; i++){
        w+=poids[i]*(*input)[i-1];
    }
    w = (*fonctionActivation).prim(w);

    double w2=0;
    for(int j = 1; j<sortie.size(); j++){
        w2+=(*sortie.at(j)).get_delta()*(*sortie.at(j)).get_poids(j);
    }

    delta = w*w2;
    return w*w2;

}

void Perceptron_cache::backprop(Input *input, double pas) {
    calcul_delta(input);
    poids[0] = poids[0] - pas * get_delta();
    for(int i=1; i<taille_poids; i++){
        poids[i] = poids[i] - pas * (*input)[i-1];
    }
}


