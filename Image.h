#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
using namespace std;

class Image
{

private:
char * label;


public:
  // Constructeur
Image(char * label);

void set_label(char *  y);

char * get_label ();

double value_access(double *  arr,int pos);

};

#endif
