#ifndef TANH_H
#define TANH_H

#include "Fonctionactivation.h"

class Tanh : public Fonctionactivation
        {
        public:
            double operator()(double arg);
            double prim(double arg);
};


#endif
