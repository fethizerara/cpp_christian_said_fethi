#ifndef NN1_H
#define NN1_H


#include <c++/4.8.3/vector>
#include "Perceptron.h"
using namespace std;
class NN1 {
private:
    std::vector<Perceptron> reseau;
    int nbcategorie;
    int taille_input;
public:
    NN1(int taille_input, int nbcategorie);
    char evaluation(Input * input);
    double apprentissage (Input* input, double pas);
};


#endif NN1_H
