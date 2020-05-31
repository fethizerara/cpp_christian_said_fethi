#ifndef NN1_H
#define NN1_H

#include <vector>
#include "Perceptron.h"
/**
 * classe contenant le reseau de neurone de type perceptron multicouche sans couche cachee
 */

class NN1 {
private:
    //vecteur de perceptrons
    vector<Perceptron> reseau;
    //categorie des inputs
    int nbcategorie;
    //taille de l'input a traiter
    int taille_input;
public:
    NN1(int taille_input, int nbcategorie);
    char evaluation(Input * input);
    void apprentissage (Input* input, double pas);
};


#endif //NN1_H
