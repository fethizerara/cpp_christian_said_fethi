#ifndef IRIS_H
#define IRIS_H

#include <iostream>
#include "Input.h"


class Iris : public Input
{
private:
double description[4];

public:
  Iris(int index);
  double operator[](int index);
  char get_label ();

};

#endif
