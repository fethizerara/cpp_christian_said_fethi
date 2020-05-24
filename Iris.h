#ifndef IRIS_H
#define IRIS_H

#include <iostream>
#include "Input.h"


class Iris : public Input

{

private:
double description[4];

public:
  // Constructeur
  Iris(int i);
  double operator[](int indice);
  char get_label ();

};

#endif
