#ifndef CPP_APPRENTISSAGE_H
#define CPP_APPRENTISSAGE_H


#include <cstdlib>
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
        if(nb_input==150){
            Iris* iris = new Iris(rand()%150);
            reseau->apprentissage(iris, pas);
    }
        else{
            Image *image = new Image(rand()%60000);
            reseau->apprentissage(image, pas);
        }
    }
}

template<class input, int nb_input> int Apprentissage<input, nb_input>::evaluer() {
    int total;
    for(int i=0; i<nb_input; i++){
        if();
    }
}


#endif //CPP_APPRENTISSAGE_H
