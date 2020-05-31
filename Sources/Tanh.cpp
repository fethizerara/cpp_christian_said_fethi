#include <cmath>
#include "..\Interfaces\Tanh.h"
/**
 * fonction calculant la tangante hyperbolique d'un argument
 * @param arg argument
 * @return valeur de la tangante hyperbolyque
 */
double Tanh::operator()(double arg){
    return (exp(arg)-exp(-arg))/(exp(arg)+exp(-arg));
};
/**
 * fonction retournant la derivee de la tangente hyperbolyque
 * @param arg argument
 * @return valeur de la derivee
 */
double Tanh::prim(double arg){
    return 1-((exp(arg)-exp(-arg))/(exp(arg)+exp(-arg)))*((exp(arg)-exp(-arg))/(exp(arg)+exp(-arg)));
};