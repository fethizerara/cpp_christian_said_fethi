#include "..\Interfaces\NN2.h"
#include "..\Interfaces\Sigmoide.h"
#include "..\Interfaces\Perceptron_cache.h"
#include "..\Interfaces\Input_intermediaire.h"
#include "..\Interfaces\Tanh.h"
/**
 * constructeur d'un reseau de neurone de type multicouche avec couche cachee
 * @param taille_input taille de l'input
 * @param nb_categorie nombre de categories
 * @param nb_perceptron_cache nombre de perceptrons cachees
 */
NN2::NN2(int taille_input, int nb_categorie, int nb_perceptron_cache) {
    Sigmoide* fonctionActivation = new Sigmoide;
    for(int j=0; j<nb_categorie; j++){
        Perceptron * p = new Perceptron(nb_perceptron_cache, fonctionActivation, j);
        couche_sortie.push_back(p);
    }
    for(int i=0; i<nb_perceptron_cache; i++){
        Perceptron_cache p1 = Perceptron_cache(taille_input, fonctionActivation, i, couche_sortie);
        couche_cachee.push_back(p1);
    }
}
/**
 * classe evaluation pour evaluer la categorie de notre input
 * @param input image ou iris
 * @return label de l'input trouver
 */
char NN2::evaluation(Input *input) {
    char label=0;
    double maxi=0;
    //input intemediaire contenant le resultat de la couche cachee
    Input_intermediaire *im = new Input_intermediaire((*input).get_label());
    //on ajoute a l'input intermediaire le resultat retournee par chaque perceptron cachee
    for(int i=0; i<couche_cachee.size();i++){
        (*im).add(couche_cachee.at(i).forward(input));
    }
    //evaluation de l'input intermediaire par la couche de sortie, pour chaque couche, on ccherche le maximum retournee et celui ci correspondra au label de notre input
    for(int j=0; j<couche_sortie.size();j++){
        double calc = (*(couche_sortie).at(j)).forward(im);
        if(maxi<calc){
            maxi=calc;
            label=j;
        }
    }
    return label;
}
/**
 * classe apprentissage pour notre reseau de neurone de type multicouche avec couche cachee
 * @param input input a faire apprendre
 * @param pas pas du gradient
 */
void NN2::apprentissage(Input *input, double pas) {
    //creation de l'input intermediare avec un label correspondant a celui de l'input
    Input_intermediaire* im1 = new Input_intermediaire((*input).get_label());
    //ajout de chaque valeur de la couche cachee dans l'input intermediaire
    for(int i=0; i<couche_cachee.size();i++){
        (*im1).add(couche_cachee.at(i).forward(input));
    }
    //calcul des delta l 2 de chaque perceptron de la couche cachee
    for(int j=0; j<couche_sortie.size(); j++){
        (*(couche_sortie).at(j)).calcul_delta(im1);
    }
    //calcul des delta l 1 de chaque perceptron de la couche de sortie
    for(int k=0; k<couche_cachee.size(); k++){
        (couche_cachee.at(k)).calcul_delta(input);
    }
    //mise a jour des poids de chaque perceptron de la couche cachee
    for(int l = 0; l<couche_cachee.size(); l++){
        (couche_cachee).at(l).backprop(input, pas);
    }
    //mise a jour des poids de chaque perceptron de la couche de sortie
    for(int m = 0; m<couche_sortie.size(); m++){
        (*(couche_sortie).at(m)).backprop(im1, pas);
    }

}
