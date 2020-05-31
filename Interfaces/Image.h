#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include "Input.h"

using namespace std;
/**
 * classe image heritant de la classe input
 * */
class Image: public Input
{
private:
    /*tableau contenant la description de l'image*/
    char pixel[784];

public:
    //contrsucteur
    Image(int index);
    //redefinition de l'operateur []
    double operator[](int indice);
    //redefinition de la fonciton get_label
    char get_label ();
};

#endif
