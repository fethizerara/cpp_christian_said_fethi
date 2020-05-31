#include <cstdlib>
#include "..\Interfaces\NN1.h"
#include "..\Interfaces\Tanh.h"
#include "..\Interfaces\Sigmoide.h"
#include <ctime>
/**
 * constructeur d'un reseau de neurose de type perceptron multicouche sans couche cachee
 * @param taille_input: taille d'un input
 * @param nbcategorie : nombre de categorie (nombre de label)
 */
NN1::NN1(int taille_input, int nbcategorie) {
    //choix d'une fonction d'activation
    Sigmoide *fonctionActivation = new Sigmoide;
    this->nbcategorie = nbcategorie;
    this->taille_input = taille_input;
    //creation d'un perception par categorie et ajout de chaque perceptron dans le reseau
    for (int i = 0; i < nbcategorie; i++) {
        Perceptron p = Perceptron(taille_input, fonctionActivation,i);
        reseau.push_back(p);
    }
}
/**
 * fonction evaluation evalue le perceptron correspondant a notre input
 * */
char NN1::evaluation(Input *input) {
    char label=0;
    double maxi=0;
    //parcours de chaque perceptron pour trouver celui qui retourne la plus grande valeur
    for(int i=0; i< reseau.size(); i++){
        double calc = reseau.at(i).forward(input);
        if(maxi<calc){
            maxi = calc;
            //si le perceptron i retourne la plus grande valeur, alors l'input appartient a ce perceptron, son label correpond donc a ce perceptron i
            label = i;
        }
    }
    return label;
}
/**
 * fonction d'apprentissage pour le reseau pour chauque perceptron le composant, correspondant au calcul de delta puis mise a jour des poids par la fonction backprop de la classe perceptron
 */
void NN1::apprentissage(Input *input, double pas) {
    for(int i=0; i<nbcategorie; i++){
        reseau.at(i).calcul_delta(input);
        reseau.at(i).backprop(input,pas);
    }
}