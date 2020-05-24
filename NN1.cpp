#include "NN1.h"

NN1::NN1(int taille_input, int nbcategorie) {
    this->nbcategorie = nbcategorie;
    this->taille_input = taille_input;
}

char NN1::evaluation(Input *input) {
    char maxi=0;
    for(int i=0; i< reseau.size(); i++){
        double calc = reseau.at(i).calcul_delta(input);
        if(maxi<=calc)
            maxi = calc;
    }
    return maxi;
}

double NN1::apprentissage(Input *input, double pas) {

}
