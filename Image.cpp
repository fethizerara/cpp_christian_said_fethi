#include "Image.h"
#include <cmath>
#include <iostream>
using namespace std;



Image::Image(char * x) : label(x)
{}

void Image::set_label(char *  x){
this->label = x;
}



char *  Image::get_label()
{
    return this->label;
}


double  Image::value_access(double *  arr,int pos)

{
    return arr[pos];
}

