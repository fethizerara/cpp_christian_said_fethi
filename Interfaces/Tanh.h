#ifndef TANH_H
#define TANH_H

#include "Fonctionactivation.h"
/**
 * classe fonction d'activation de type Tanh ou tangante hyperbolyque
 */
class Tanh : public Fonctionactivation
        {
        public:
            double operator()(double arg);
            double prim(double arg);
};


#endif
