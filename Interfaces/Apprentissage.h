#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H

#include <cstdlib>
#include <ctime>
#include "NN1.h"
#include "NN2.h"
#include "Iris.h"
#include "Image.h"

/**
 * patron de classe apprentissage
 */
template <class input, int nb_input, class reseau_neurone> class Apprentissage {
    /*champ contenant le reseau de neurone de type generique*/
private:
    reseau_neurone* reseau;
public:
    /*constructeur*/
    Apprentissage(reseau_neurone* res);
    /*classe apprentissage de la base*/
    void apprendre_base(int K, double pas);
    /*fonction pour evaluer le nombre d'inputs classés*/
    int evaluer();
};

template<class input, int nb_input, class reseau_neurone>
Apprentissage<input, nb_input, reseau_neurone>::Apprentissage(reseau_neurone* res) {
    /*affectation du reseau d'apprentissage*/
    reseau = res;
}

template<class input, int nb_input, class reseau_neurone>
void Apprentissage<input, nb_input, reseau_neurone>::apprendre_base(int K, double pas) {
    /*pour chaque iteration, prendre un input au hasard dans la base et le faire apprendre par le reseau*/
    for(int k=1; k<=K; k++){
            input* input1 = new input(rand()%nb_input);

            reseau->apprentissage(input1, pas);
    }
}

template<class input, int nb_input, class reseau_neurone> int Apprentissage<input, nb_input, reseau_neurone>::evaluer() {
    /*entier contenant le nombre d'input appris, c'est a dire bien classé*/
    int total=0;
    /*pour chaque input de la base, creer l'input, stocker son vrai label puis evaluer le label trouve par le reseau et les comparer*/
    for(int i=0; i<nb_input; i++) {
        Input *in = new input(i);
        char vrai_label = in->get_label();
        char label_trouve = reseau->evaluation(in);
//        cout<< static_cast<unsigned >(vrai_label)<<" "<< static_cast<unsigned>(label_trouve)<<"\n";
        if (vrai_label == label_trouve) {
            total++;
        }
    }

    return total;
}


#endif //APPRENTISSAGE_H
