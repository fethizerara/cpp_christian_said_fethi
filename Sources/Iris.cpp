#include "..\Interfaces\Iris.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

/**
 * fonction split pour spliter les informaations d'un input de type iris venant du fichier
 */
vector<string> split(const string& str, const string& delim)
{
    vector<string> resultats;
    size_t previous = 0, position = 0;
    do
    {
        position = str.find(delim, previous);
        if (position == string::npos) position = str.length();
        string token = str.substr(previous, position-previous);
        if (!token.empty()) resultats.push_back(token);
        previous = position + delim.length();
    }
    while (position < str.length() && previous < str.length());
    return resultats;
}
/**
 * contructeur d'Iris
 * @param index: indice de l'Iris
 */
Iris::Iris(int index){
    std::ostringstream ss;
    ss << index;
    std::string s(ss.str());
    //identification du path contenant les donnees de l'input correspondant a l'index
    std::string path = "..\\Ressources\\iris_training\\iris"+ s;
    std::ifstream myfile(path.c_str());
    std::vector <std::string> data;
    std::string donnees;
    //lecture de la ligne correspondant a l'index
    getline(myfile,donnees);
    data = split(donnees,",");
    /*copie des donnees de description dans le tableau de description*/
    /*fonction atof pour transformer les strings en double*/
    for(int i=0; i<4; i++){
       description[i] = atof(data.at(i).c_str());
   }
    /*identification des labels*/
 if (data.at(data.size()-1) == "Iris-setosa")
     label = 0;
 else if(data.at(data.size()-1)== "Iris-virginica")
     label = 1;
 else if(data.at(data.size()-1) == "Iris-versicolor")
     label = 2;
    myfile.close();
}
/**
 * fonction retournant le label d'un iris
 * */
char Iris::get_label (){
    return this->label;
};
/**
 * operateur [] retournant la valeur correpondante à l'indice dans le tableau
 * */
double Iris::operator[] (int index){
    return description[index];
}






