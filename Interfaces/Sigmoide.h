#ifndef SIGMOIDE_H
#define SIGMOIDE_H


#include "Fonctionactivation.h"
/**
 * classe fonction d'activation de type sigmoide
 */
class Sigmoide : public Fonctionactivation
        {
        public:
                double operator()(double arg);
                double prim(double arg);
};


#endif
