#include "Iris.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>



vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

Iris::Iris(int index){
    std::ostringstream ss;
    ss << index;
    std::string s(ss.str());
    std::string path = "C:\\Users\\Ravoavy Christian\\Desktop\\New folder (2)\\cpp_christian_said_fethi\\Ressources\\iris_training\\iris"+ s;
    std::ifstream myfile(path.c_str());
    std::vector <std::string> data;
    std::string donnees;
    getline(myfile,donnees);
    data = split(donnees,",");
    for(int i=0; i<5; i++){
       description[i] = atof(data.at(i).c_str());
   }
 if (data.at(data.size()-1) == "Iris-setosa")
     label = 0;
 else if(data.at(data.size()-1)== "Iris-virginica")
     label = 1;
 else if(data.at(data.size()-1) == "Iris-versicolor")
     label = 2;
    myfile.close();
}

char Iris::get_label (){
    return this->label;
};

double Iris::operator[] (int index){
    return description[index];
}






