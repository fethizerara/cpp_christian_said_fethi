#include "NN1.h"

NN1::NN1(int taille_input, int nbcategorie, Fonction_activation* fonctionActivation) {
    this->nbcategorie = nbcategorie;
    this->taille_input = taille_input;
    for(int i=1; i<=nbcategorie; i++){
        Perceptron p = Perceptron(taille_input,fonctionActivation,i);
        reseau.push_back(p);
    }
}

char NN1::evaluation(Input *input) {
    char maxi=0;
    for(int i=0; i< reseau.size(); i++){
        double calc = reseau.at(i).get_delta();
        if(maxi<=calc)
            maxi = calc;
    }
    return maxi;
}

double NN1::apprentissage(Input *input, double pas) {
    for(int i=0; i<nbcategorie; i++){
        reseau.at(i).backprop(input, pas);
    }
}
