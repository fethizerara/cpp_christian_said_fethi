#include "Apprentissage.h"
#include <ctime>
#include <iostream>

int main(){
    srand(time(NULL));

    NN1* reseau1 = new NN1(4,3);
    Apprentissage<Iris, 150, NN1> apprentissage1(reseau1);
    apprentissage1.apprendre_base(15000,0.1);
    cout << apprentissage1.evaluer()<<"\n";

    NN2* reseau2 = new NN2(4,3, 3);
    Apprentissage<Iris, 150, NN2> apprentissage2(reseau2);
    apprentissage2.apprendre_base(10000,0.01);
    cout << apprentissage2.evaluer()<<"\n";

    return 0;
}