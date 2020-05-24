#include <cstdlib>
#include "Perceptron.h"

Perceptron::Perceptron(int taille_input, Fonction_activation *f, char label) {
    poids = new double[taille_input];
    taille_poids = taille_input;
    for(int i =0; i<taille_input; i++){
        poids[i]=(rand()/(double)RAND_MAX)*2-1;
    }
    fonctionActivation = f;
    this->label = label;
    delta=0;
  
double Perceptron::get_poids(int index) {
    return poids[index];
}

double Perceptron::forward(Input *input) {
    double res=poids[0];
    for(int i=1; i<taille_poids; i++){
        res+=poids[i]*input->operator[](i);
    }
    return fonctionActivation->operator()(res);
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
    for(int i=0; i<taille_poids; i++){
        if(i==0){
            poids[i]=poids[i] - pas*calcul_delta(input);
        } else{
            poids[i]=poids[i] -pas*input->operator[](i)*calcul_delta(input);
        }
    }


