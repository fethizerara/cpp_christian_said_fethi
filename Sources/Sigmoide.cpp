#include <cmath>
#include "..\Interfaces\Sigmoide.h"
/**
 * fonction calculant le sigmoide pour un argument donne
 * @param arg argument
 * @return valeur du sigmoide
 */
double Sigmoide::operator()(double arg){
    return 1/(1+exp(0-arg));
};
/**
 * fonction calculant la derivee d'un sigmoide
 * @param arg argument
 * @return derivee du sigmoide
 */
double Sigmoide::prim(double arg) {
    return (1/(1+exp(0-arg)))*(1 - (1/(1+exp(0-arg))));
};