#include "Image.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <c++/4.8.3/bitset>


Image::Image(int index){
    std::ostringstream ss;
    ss << index;
    std::string s(ss.str());
    std::string pixels = "training"+ s;
    std::string labels = "train-labels.idx1-ubyte";
    std::ifstream pixelfile (pixels.c_str(),std::ios::binary);
    std::ifstream labelfile (labels.c_str(), std::ios::binary);
    pixelfile.seekg(1078,ios::beg);
    labelfile.seekg(8+index,ios::beg);
    pixelfile.read(pixel,784);
    pixelfile.close();
    labelfile.read(&label,1);

}

char Image::get_label (){
    return this->label;
}

double Image::operator[] (int index){
    return atoi(&pixel[index]);
}

int main(){
    Image my = Image(1);
    cout<<static_cast<unsigned>(my.get_label());
}





