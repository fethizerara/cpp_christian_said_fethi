#ifndef APPRENTISSAGE_H
#define APPRENTISSAGE_H


#include <cstdlib>
#include <ctime>
#include "NN1.h"
#include "Iris.h"
#include "Image.h"

template <class input, int nb_input> class Apprentissage {
private:
    NN1 *reseau;
public:
    Apprentissage(NN1* res);
    void apprendre_base(int K, double pas);
    int evaluer();
};

template<class input, int nb_input>
Apprentissage<input, nb_input>::Apprentissage(NN1 *res) {
    reseau = res;
}

template<class input, int nb_input>
void Apprentissage<input, nb_input>::apprendre_base(int K, double pas) {
    for(int k=0; k<K; k++){
        int indi;
        if(nb_input==150){
            indi = rand()%150;
            Iris* iris = new Iris(indi);
            reseau->apprentissage(iris, pas);
    }

        else{
            indi = rand()%60000;
            Image *image = new Image(indi);
            reseau->apprentissage(image, pas);
        }
    }
}

template<class input, int nb_input> int Apprentissage<input, nb_input>::evaluer() {
    int total;
    for(int i=0; i<nb_input; i++){
        Input *in;
        if(nb_input==150){
            in = new Iris(i);
        }
        else{
            in = new Image(i);
        }
        char vrai_label = in->get_label();
        char label_trouve = reseau->evaluation(in);
        if ( vrai_label == label_trouve)
                total++;

    }
}


#endif //APPRENTISSAGE_H
