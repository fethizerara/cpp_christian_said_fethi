#ifndef FONCTION_ACTIVATION_H
#define FONCTION_ACTIVATION_H


class Fonctionactivation {
public:
    virtual double operator()(double arg)=0;
    virtual double prim(double arg)=0;
};


#endif //FONCTION_ACTIVATION_H
