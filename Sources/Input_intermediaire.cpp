#include "..\Interfaces\Input_intermediaire.h"

/**
 * constructeur d'un input intermediaire
 * */
Input_intermediaire::Input_intermediaire(char label) {
    this->label = label;
}
/**
 * fonction add qui rajoute une valeur au vecteur des input intermediare
 * */
void Input_intermediaire::add(double val) {
    v_intermediare.push_back(val);
}
/**
 * operateur [] servant a retourner la valeur corresponant a l'index
 * */
double Input_intermediaire::operator[](int index) {
    return v_intermediare.at(index);
}
/**
 * fonction qui retourne le label d'un input intermediaire
 * */
char Input_intermediaire::get_label() {
    return this->label;
}
