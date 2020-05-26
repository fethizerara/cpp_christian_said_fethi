#include <cmath>
#include "Tanh.h"

double Tanh::operator()(double arg){
    return (exp(arg)-exp(-arg))/(exp(arg)+exp(-arg));
};
double Tanh::prim(double arg){
    return 1-((exp(arg)-exp(-arg))/(exp(arg)+exp(-arg)))*((exp(arg)-exp(-arg))/(exp(arg)+exp(-arg)));
};