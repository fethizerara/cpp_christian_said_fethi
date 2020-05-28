#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H

#include <cstdlib>
#include <ctime>
#include "NN1.h"
#include "NN2.h"
#include "Iris.h"
#include "Image.h"

template <class input, int nb_input, class reseau_neurone> class Apprentissage {
private:
    reseau_neurone* reseau;
public:
    Apprentissage(reseau_neurone* res);
    void apprendre_base(int K, double pas);
    int evaluer();
};

template<class input, int nb_input, class reseau_neurone>
Apprentissage<input, nb_input, reseau_neurone>::Apprentissage(reseau_neurone* res) {
    reseau = res;
}

template<class input, int nb_input, class reseau_neurone>
void Apprentissage<input, nb_input, reseau_neurone>::apprendre_base(int K, double pas) {
    for(int k=0; k<K; k++){
            input* input1 = new Iris(rand()%nb_input);
            reseau->apprentissage(input1, pas);
    }
}

template<class input, int nb_input, class reseau_neurone> int Apprentissage<input, nb_input, reseau_neurone>::evaluer() {
    int total=0;
    for(int i=0; i<nb_input; i++) {
        Input *in = new input(i);
        char vrai_label = in->get_label();
        char label_trouve = reseau->evaluation(in);
        //cout<< static_cast<unsigned >(vrai_label)<<" "<< static_cast<unsigned>(label_trouve)<<"\n";
        if (vrai_label == label_trouve) {
        total++;
    }
        //cout<<total<<"\n";
    }

    return total;
}


#endif //APPRENTISSAGE_H
