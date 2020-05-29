#include "Perceptron.h"
#include "Iris.h"
#include "Image.h"
#include <ctime>
#include <cstdlib>

Perceptron::Perceptron(int taille_input, Fonctionactivation *f, char label) {
    taille_poids = taille_input+1;
    poids = new double[taille_poids];
    double random = 0;
    for (int i = 0; i < taille_poids; i++) {
        random = (rand()% 3 - 1);
        poids[i] = random ;
    }
    fonctionActivation = f;
    this->label = label;
    delta = 0.0;
}
double Perceptron::get_poids(int index) {
    return poids[index];
}

double Perceptron::forward(Input * input) {
    double res=poids[0];
    for(int i=1; i<taille_poids; i++){
        res+=poids[i]* (*input)[i-1];
    }
    res = (*fonctionActivation)(res);
}

double Perceptron::calcul_delta(Input *input) {
    double w=poids[0];
    for(int i=1; i<taille_poids; i++){
        w+=poids[i]*(*input)[i-1];
    }
    w = (*fonctionActivation).prim(w);
    double w2 = forward(input);
    double w3 = w * (w2 - (double) input->get_label());
    delta = w3;
    return w3;
}

double Perceptron::get_delta() {
    return delta;
}

void Perceptron::backprop(Input* input, double pas) {
    poids[0]= poids[0] - pas * this-> get_delta();
    for (int i = 1; i < taille_poids; i++) {
        poids[i]= poids[i] - pas * (*input)[i-1] * this-> get_delta();
    }
}


