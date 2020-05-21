#include "Input.h"
#include <cmath>
#include <iostream>


using namespace std;



Input::Input(std::string x) : label(x)
{}

void Input::set_label(std::string  x){
this->label = x;
}



std::string  Input::get_label()
{
    return this->label;
}


double  Input::value_access(double *  arr,int pos)

{
    return arr[pos];
}



