#include "NN1.h"
#include "Tanh.h"
#include "Sigmoide.h"

NN1::NN1(int taille_input, int nbcategorie) {
    Sigmoide *fonctionActivation = new Sigmoide;
    this->nbcategorie = nbcategorie;
    this->taille_input = taille_input;
    for(int i=0; i<nbcategorie; i++){
        Perceptron p = Perceptron(taille_input,fonctionActivation,i);
        reseau.push_back(p);
    }
}

char NN1::evaluation(Input *input) {
    char label;
    double maxi;
    for(int i=0; i< reseau.size(); i++){
        double calc = reseau.at(i).forward(input);
        if(maxi<=calc){
            maxi = calc;
            label = i;
        }
    }
    cout<< static_cast<unsigned>(label);
    return label;
}

void NN1::apprentissage(Input *input, double pas) {
    for(int i=0; i<nbcategorie; i++){
        reseau.at(i).backprop(input, pas);
    }
}
