#include "Interfaces\Apprentissage.h"
#include <ctime>
#include <iostream>

int main(){
    /*initialisation du random*/
    srand(time(NULL));

    /*
     * test du reseau de neurone NN1 avec les inputs iris
     */
    //creation du reseau de neurone
    NN1* reseau1 = new NN1(4,3);
    //assignation du reseau a l'apprentissage
    Apprentissage<Iris, 150, NN1> apprentissage1(reseau1);
    //apprentissage de la base
    apprentissage1.apprendre_base(15000,0.1);
    //evaluation de la base
    cout << "nombre de fleurs iris correctement classees par NN1 : "<<apprentissage1.evaluer()<<"/150\n";

    /*
     * test du reseau de neurone NN1 avec les inputs Images
     */
    NN1* reseau2 = new NN1(784,10);
    Apprentissage<Image, 60000, NN1> apprentissage2(reseau2);
    apprentissage2.apprendre_base(100000,1);
    cout << "nombre d'images correctement classees par NN1 : "<<apprentissage2.evaluer()<<"/60000\n";

    /*
     * test du reseau de neurone NN2 avec les inputs iris
     */
    NN2* reseau3 = new NN2(4,3,3);
    Apprentissage<Iris, 150, NN2> apprentissage3(reseau3);
    apprentissage3.apprendre_base(10000,0.01);
    cout << "nombre de fleurs iris correctement classees par NN2 : "<<apprentissage3.evaluer()<<"/150\n";
    /*
     * test du reseau de neurone NN2 avec les inputs images
     */
    NN2* reseau4 = new NN2(784,10, 10);
    Apprentissage<Image, 60000, NN2> apprentissage4(reseau4);
    apprentissage4.apprendre_base(100000,0.1);
    cout << "nombre d'images correctement classees par NN2 : "<<apprentissage4.evaluer()<<"/60000\n";

    return 0;
}