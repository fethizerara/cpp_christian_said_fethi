//
// Created by Ravoavy Christian on 22/05/2020.
//

#include <cstdlib>
#include "Perceptron.h"

//pas fini
Perceptron::Perceptron(int taille_input, Fonction_activation *f, char label) {
    
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
