#include <cmath>
#include "Tanh.h"

double Tanh::operator()(double arg){
    return (exp(arg)-exp(0-arg))/(exp(arg)+exp(0-arg));
};
double Tanh::prim(double arg){
    return 1-(exp(arg)-exp(0-arg))*(exp(arg)+exp(0-arg)) ;
};