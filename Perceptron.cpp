#include <cstdlib>
#include "Perceptron.h"
#include "Iris.h"
#include "Image.h"

Perceptron::Perceptron(int taille_input, Fonctionactivation *f, char label) {
    poids=new double[taille_input];
    taille_poids=taille_input;
    for (int i = 0; i < taille_poids; i++) {
        poids[i] = rand() % 2 - 1;
    }
    fonctionActivation = f;
    this->label = label;
    delta = 0;
}
double Perceptron::get_poids(int index) {
    return poids[index];
}

double Perceptron::forward(Input* input) {
    double res=poids[0];
    for(int i=1; i<taille_poids; i++){
        res+=poids[i]*input->operator[](i);
    }
    res = fonctionActivation->operator()(res);
    return res;
}

double Perceptron::calcul_delta(Input *input) {
    double w=poids[0];
    for(int i=1; i<taille_poids; i++){
        w+=poids[i]*input->operator[](i);
    }
    w = fonctionActivation->prim(w);
    double w2 = forward(input);
    double w3 = w * (w2 - input->get_label());
    delta = w3;
    return w3;
}

double Perceptron::get_delta() {
    return delta;
}

void Perceptron::backprop(Input* input, double pas) {
    poids[0] = poids[0] - pas * get_delta();
    for (int i = 1; i < taille_poids; i++) {
        poids[i] = poids[i] - pas * input->operator[](i) * get_delta();
    }
}


