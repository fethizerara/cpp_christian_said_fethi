#include "..\Interfaces\Perceptron_cache.h"
/**
 * constructeur d'un perceptron de la couche cachee
 * @param taille_input taille de l'input
 * @param fonctionactivation fonction d'activation
 * @param label label du perceptron
 * @param sorties couche de sorite
 */
Perceptron_cache::Perceptron_cache(int taille_input, Fonctionactivation * fonctionactivation, char label, vector<Perceptron *> sorties)
        : Perceptron(taille_input, fonctionactivation, label) {
    this->sortie = sorties;
};
/**
 * fonction calcul delta pour calculer le delta
 * @param input iris ou image
 * @return le delta correspondant au perceptron
 */
double Perceptron_cache::calcul_delta(Input *input) {
    //application de la formule de delta
    double w=poids[0];
    for(int i=1; i<taille_poids; i++){
        w+=poids[i]*(*input)[i-1];
    }
    w = (*fonctionActivation).prim(w);

    double w2=0;
    for(int j = 0; j<sortie.size(); j++){
        w2+=(*sortie.at(j)).get_delta()*(*sortie.at(j)).get_poids(j);
    }

    delta = w*w2;
    return w*w2;

}
/**
 * fonction de mise a jour des poids des perceptrons cachee
 * @param input iris ou image
 * @param pas pas du gradient
 */
void Perceptron_cache::backprop(Input *input, double pas) {
    //application de la formule pour i=0 et i#0
    poids[0] = poids[0] - pas * get_delta();
    for(int i=1; i<taille_poids; i++){
        poids[i] = poids[i] - pas * get_delta() * (*input)[i-1];
    }
}


