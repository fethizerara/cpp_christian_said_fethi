#include "NN2.h"
#include "Sigmoide.h"
#include "Perceptron_cache.h"
#include "Input_intermediaire.h"
#include "Tanh.h"

NN2::NN2(int taille_input, int nb_categorie, int nb_perceptron_cache) {
    Tanh* fonctionActivation = new Tanh;
    for(int j=0; j<nb_categorie; j++){
        Perceptron * p = new Perceptron(taille_input, fonctionActivation, j);
        couche_sortie.push_back(p);
    }
    for(int i=0; i<nb_perceptron_cache; i++){
        Perceptron_cache p = Perceptron_cache(taille_input, fonctionActivation, i, couche_sortie);
        couche_cachee.push_back(p);
    }
}

char NN2::evaluation(Input *input) {
    char label=0;
    double maxi=0;

    Input_intermediaire *im = new Input_intermediaire((*input).get_label());

    for(int i=0; i<couche_cachee.size();i++){
        (*im).add(couche_cachee.at(i).forward(input));
    }

    for(int j=0; j<couche_sortie.size();j++){
        double calc = (*(couche_sortie).at(j)).forward(im);
        if(maxi<calc){
            maxi=calc;
            label=j;
        }
    }
    return label;
}
void NN2::apprentissage(Input *input, double pas) {
    Input_intermediaire* im1 = new Input_intermediaire((*input).get_label());
    for(int i=0; i<couche_cachee.size();i++){
        (*im1).add(couche_cachee.at(i).forward(input));
    }
    for(int j=0; j<couche_sortie.size(); j++){
        (*(couche_sortie).at(j)).calcul_delta(im1);
    }
    for(int k=0; k<couche_cachee.size(); k++){
        couche_cachee.at(k).calcul_delta(input);
    }
    for(int m = 0; m<couche_sortie.size(); m++){
        (*(couche_sortie).at(m)).backprop(im1, pas);
    }

}
