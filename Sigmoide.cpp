#include <cmath>
#include "Sigmoide.h"

double Sigmoide::operator()(double arg){
    return 1/(1+exp(0-arg));
};
double Sigmoide::prim(double arg) {
    return (1+exp(0-arg))*(1 - (1/(1+exp(0-arg))));
};