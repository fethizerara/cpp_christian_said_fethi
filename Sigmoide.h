#ifndef SIGMOIDE_H
#define SIGMOIDE_H


#include "Fonctionactivation.h"

class Sigmoide : public Fonctionactivation
        {
        public:
                double operator()(double arg);
                double prim(double arg);
};


#endif
