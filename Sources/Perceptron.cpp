#include "..\Interfaces\Perceptron.h"
#include "..\Interfaces\Iris.h"
#include "..\Interfaces\Image.h"
#include <ctime>
#include <cstdlib>
/**
 * classe perceptron representant un perceptron
 * @param taille_input taille d'un input
 * @param f fonction d'activation du perceptron
 * @param label label du perceptron
 */
Perceptron::Perceptron(int taille_input, Fonctionactivation *f, char label) {
    //l'ensmble des poids est dans Rn+1 donc de la taille des inputs + 1
    taille_poids = taille_input+1;
    //creation du tableau des poids
    poids = new double[taille_poids];
    double random = 0;
    //remplissage du poids par des valeurs entre -1 et 1
    for (int i = 0; i < taille_poids; i++) {
        random = (rand()% 2 - 1);
        poids[i] = random ;
    }
    fonctionActivation = f;
    this->label = label;
    delta = 0.0;
}
/**
 * fonction getpoids retournant le poids correspondant a l'indice
 * @param index indice
 * @return de type double correspondant aau poids
 */
double Perceptron::get_poids(int index) {
    return poids[index];
}
/**
 * fonction forward correspondant a A(x)=y et donc le label d'un input
 * @param input de type image ou iris
 * @return la valeur de A(x)
 */
double Perceptron::forward(Input * input) {
    double res=poids[0];
    //A(x) qu'on va stocker dans res
    for(int i=1; i<taille_poids; i++){
        res+=poids[i]* (*input)[i-1];
    }
    res = (*fonctionActivation)(res);
    return res;
}
/**
 * fonction correspondant au calcul de delta
 * @param input de type iris ou image
 * @return le delta
 */
double Perceptron::calcul_delta(Input *input) {
    double w=poids[0];
    //application de la formule de delta
    for(int i=1; i<taille_poids; i++){
        w+=poids[i]*(*input)[i-1];
    }
    w = (*fonctionActivation).prim(w);
    double w2 = forward(input);
    double w3 = w * (w2 - (double) input->get_label());
    delta = w3;
    return w3;
}
/**
 * fonction retournant le delta
 * @return double du delta
 */
double Perceptron::get_delta() {
    return delta;
}
/**
 * fonction de mise a jour des poids du perceptron
 * @param input iris ou image
 * @param pas pas du gradient
 */
void Perceptron::backprop(Input* input, double pas) {
    //application de la formule pour i=0 et i#0
    poids[0]= poids[0] - pas * this-> get_delta();
    for (int i = 1; i < taille_poids; i++) {
        poids[i]= poids[i] - pas * (*input)[i-1] * this-> get_delta();
    }
}


