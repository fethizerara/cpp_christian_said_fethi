#ifndef IRIS_H
#define IRIS_H

#include <iostream>
#include "Input.h"

/**
 * classe heritant de la classe input contenant les informations des inputs de type Iris
 */
class Iris : public Input
{
private:
    //champ contenant la descrition d'un Iris
double description[4];

public:
  Iris(int index);
  double operator[](int index);
  char get_label ();

};

#endif
