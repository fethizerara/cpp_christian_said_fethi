//
// Created by Ravoavy Christian on 22/05/2020.
//

#include <cstdlib>
#include "Perceptron.h"

//pas fini
Perceptron::Perceptron(int taille_input, Fonction_activation *f, char label) {
    fonctionActivation = f;
    this->label = label;
    for(int i=0; i<taille_input; i++){
        poids[i]=0;
    }
}

double Perceptron::get_poids(int index) {
    return poids[index];
}

double Perceptron::forward(Input *input) {

}

double Perceptron::calcul_delta(Input *input) {
   
}

double Perceptron::get_delta() {
    return delta;
}

void Perceptron::backprop(Input input, double pas) {

}
