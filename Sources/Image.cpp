#include "..\Interfaces\Image.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <bitset>

/**
 * constructeur d'image
 * @param index : indice de l'image a recuperer
 */
Image::Image(int index){
    std::ostringstream ss;
    ss << index;
    std::string s(ss.str());
    //identification du path contenant les donnees de l'input correspondant a l'index
    std::string pixels = "..\\Ressources\\MNIST_training\\training"+ s;
    //identification du path contenant les labels de l'input
    std::string labels = "..\\Ressources\\train-labels.idx1-ubyte";
    //lecture du fichier de description en mode binaire
    std::ifstream pixelfile (pixels.c_str(),std::ios::binary);
    //lecture du fichier des labels en mode binaire
    std::ifstream labelfile (labels.c_str(), std::ios::binary);
    //deplacement de l'iterator a l'octect 1078, debut des octects contenant la description de l'image
    pixelfile.seekg(1078,ios::beg);
    //deplacement de l'iterator a l'octect à l'octect 8+indice de l'image pour avoir son label
    labelfile.seekg(8+index,ios::beg);
    //stockage des informations de description dans le champs pixel
    pixelfile.read(pixel,784);
    //fermeture du fichier pixel
    pixelfile.close();
    //stockage du label
    labelfile.read(&label,1);
    //fermeture du fichier des labels
    labelfile.close();
}
/**
 * fonction qui retourne le label d'une image
 * */
char Image::get_label (){
    return this->label;
}
/**
 * operator [] qui retourne la valeur d'une pixel correspondant a l'index en argument
 * */
double Image::operator[] (int index){
    //les inputs semblent retourner des valeurs negatives, donc nous avons choisi de retourner la valeur absolue
    return abs((double)(pixel[index]));
}





