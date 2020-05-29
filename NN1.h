#ifndef NN1_H
#define NN1_H

#include <vector>
#include "Perceptron.h"

using namespace std;
class NN1 {
private:
    vector<Perceptron> reseau;
    vector<char> listelabel;
    int nbcategorie;
    int taille_input;
public:
    NN1(int taille_input, int nbcategorie);
    char evaluation(Input * input);
    void apprentissage (Input* input, double pas);
};


#endif //NN1_H
