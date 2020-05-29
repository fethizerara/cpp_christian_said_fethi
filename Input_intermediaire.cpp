#include "Input_intermediaire.h"

Input_intermediaire::Input_intermediaire(char label) {
    this->label = label;
}

void Input_intermediaire::add(double val) {
    v_intermediare.push_back(val);
}

double Input_intermediaire::operator[](int index) {
    return v_intermediare.at(index);
}

char Input_intermediaire::get_label() {
    return this->label;
}
