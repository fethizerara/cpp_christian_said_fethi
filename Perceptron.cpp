#include <cstdlib>
#include "Perceptron.h"
#include "Iris.h"
#include "Image.h"

Perceptron::Perceptron(int taille_input, Fonction_activation *f, char label) {
    if (taille_input == 4) {
        poids = new double[151];
        taille_poids = 151;
    } else {
        poids = new double[60001];
        taille_poids = 60001;
    }

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

double Perceptron::forward(Input *input) {
    double res=poids[0];
    for(int i=1; i<taille_poids; i++){
        if(taille_poids==151){
            Iris iris = Iris(i);
            res+=poids[i]*iris.operator[](i);
        }
        else{
            Image image = Image(i);
            res+=poids[i]*image.operator[](i);
        }
    }
    res = fonctionActivation->operator()(res);
    return res;
}

double Perceptron::calcul_delta(Input *input) {
    double w = forward(input);
    double w2 = fonctionActivation->prim(w);
    double w3 = w2 * (forward(input)-input->get_label());
    delta = w3;
    return w3;
}

double Perceptron::get_delta() {
    return delta;
}

void Perceptron::backprop(Input* input, double pas) {
    poids[0] = poids[0] - pas * calcul_delta(input);
    for (int i = 1; i < taille_poids; i++) {
            poids[i] = poids[i] - pas * input->operator[](i) * calcul_delta(input);
    }
}


