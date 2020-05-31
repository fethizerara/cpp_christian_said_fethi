#ifndef NN2_H
#define NN2_H

#include <vector>
#include "Perceptron.h"
#include "Perceptron_cache.h"
/**
 * classe contenant le reseau de neurone de type perceptron multicouche avec couche cachee
 */
class NN2 {
private:
    //vecteur de perceptron cachee
    vector<Perceptron_cache> couche_cachee;
    //vecteur de perception sortie
    vector<Perceptron *> couche_sortie;
public:
    NN2(int taille_input, int nb_categorie, int nb_perceptron);
    char evaluation(Input *input);
    void apprentissage(Input *input, double pas);
};


#endif //NN2_H
