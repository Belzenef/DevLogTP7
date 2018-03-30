#include <iostream>
#include "string.h"

int main(int argc, char* argv[]){
	std::cout << "Hello world !" << std::endl;
	
	//testing copy ctor and c_str
	char cstr1[] = {'T', 'e', 's', 't', 'i', 'n', 'g',' ', 'c', 'o', 'p', 'y', 'c', 't', 'o', 'r', '\0'};
	std::cout << cstr1 << std::endl;
	string str1 = string(cstr1);
	std::cout << "str1 = " << str1.c_str() << std::endl;	
	string str2 = string(str1);
	std::cout << "using copy ctor, str2 = "<< str2.c_str() << std::endl;	

	return 0;
}
