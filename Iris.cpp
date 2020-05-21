#include "Iris.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#define PATH "C:/Users/Yagami/workspace/Project_cpp/resources_iris/iris"

using namespace std;



Iris::Iris(int index) : Input(label_Lookup(index)){

	this->index = index;

}

std::string toString(int i){
   std::stringstream ss;
   ss << i;
   return ss.str();
}

std::string Iris::label_Lookup (int index){
	std::string  label ;
	std::string path = std::string(PATH) + toString(index);
	std::ifstream myfile (path.c_str());
	std::vector <std::string> data;
	std::string input;

	while (myfile >> input){

	    std::stringstream ss(input);

	    for (std::string i; ss >> i;) {
	    		data.push_back(i);
	        }

	}

	stringstream ss(data[0]);

	while (ss.good()) {
			std::string substr;
	        getline(ss, substr, ',');
	        data.push_back(substr);
	    }

	if (data[data.size()-1] == "Iris-setosa")
		label = "label 0";
	else if	(data[data.size()-1] == "Iris-virginica ")
		label =  "label 1";
	else if	(data[data.size()-1] == "Iris-versicolor")
		label =  "label 2";
	else
	label = 'Error';

	myfile.close();
	return label;

}

void Iris::set_index(int  index){
	this->index = index;

}

int Iris::get_index () {

	return this->index;

}

int main()
{
Iris iris = Iris(3);
std::cout << iris.get_label();
return 0;
}


