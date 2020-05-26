#include "Apprentissage.h"

int main(){
    NN1* reseau = new NN1(4,3);
    Apprentissage<Iris, 150> apprentissage(reseau);
    apprentissage.apprendre_base(1000,0.1);
    cout << apprentissage.evaluer();
    return 0;
}