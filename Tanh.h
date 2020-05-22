#ifndef TANH_H
#define TANH_H

#include "Fonction_activation.h"

class Tanh : public Fonction_activation
        {
    double operator()(double arg);
    double prim(double arg);
};


#endif
