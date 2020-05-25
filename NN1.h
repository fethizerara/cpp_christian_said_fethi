#ifndef NN1_H
#define NN1_H


#include <vector>
#include "Perceptron.h"
#include <list>
using namespace std;
class NN1 {
private:
    vector<Perceptron> reseau;
    int nbcategorie;
    int taille_input;
public:
    NN1(int taille_input, int nbcategorie, Fonction_activation *fonctionActivation);
    char evaluation(Input * input);
    double apprentissage (Input* input, double pas);
};


#endif NN1_H
