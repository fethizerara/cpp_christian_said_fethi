#ifndef INPUT_H
#define INPUT_H

#include <iostream>
using namespace std;
#include <string>   // pour std::string

class Input
{

private:
std::string label;


public:
  // Constructeur
Input(std::string label);
// Le destructeur.



void set_label(std::string  y);

std::string get_label ();

double value_access(double *  arr,int pos);

};

#endif
