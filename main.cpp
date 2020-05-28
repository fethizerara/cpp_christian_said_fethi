#include "Apprentissage.h"
#include <ctime>
int main(){
    srand(time(NULL));
    NN1* reseau = new NN1(4,3);
    Apprentissage<Iris, 150, NN1> apprentissage(reseau);
    apprentissage.apprendre_base(15000,0.1);
    cout << apprentissage.evaluer();
    return 0;
}