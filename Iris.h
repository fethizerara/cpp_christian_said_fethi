#ifndef IRIS_H
#define IRIS_H

#include <iostream>
#include "Input.h"
using namespace std;

class Iris : public Input

{

private:
int index;


public:
  // Constructeur
Iris(int index);

void set_index(int  index);

int get_index ();


std::string label_Lookup (int index);

};

#endif
