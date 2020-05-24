#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include "Input.h"

using namespace std;

class Image: public Input
{
private:
    char pixel[784];
public:
    Image(int index);
    double operator[](int indice);
    char get_label ();
};

#endif
