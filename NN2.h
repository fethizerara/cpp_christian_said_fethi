#ifndef NN2_H
#define NN2_H

#include <vector>
#include "Perceptron.h"

class NN2 {
private:
    vector<Perceptron> couche_cachee;
    vector<Perceptron *> couche_sortie;
public:
    NN2(int taille_input, int nb_categorie, int nb_perceptron);
    char evaluation(Input *input);
    void apprentissage(Input *input, double pas);
};


#endif //NN2_H
