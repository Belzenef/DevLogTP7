#include <iostream>
#include "string.h"

int main(int argc, char* argv[]){
	std::cout << "Creating c_string :" << std::endl;
	char cstr[] = {'H','e','l','l','o',' ','W','o','r','l','d',' ','!','\0'};
	std::cout << cstr << std::endl;
	
	std::cout << "Testing from c-string constructor :" << std::endl;
	string str = string(cstr);
	std::cout << str.c_str() << std::endl;
	std::cout << "str.size() = " << str.size() << std::endl;
	
	std::cout << "Testing length() :" << std::endl;
	std::cout << "str.length() = " << str.length() <<std::endl;
	
	std::cout << "Testing max_size() :" << std::endl;
	std::cout << "str.max_size() = " << str.max_size() <<std::endl;
	
	std::cout << "Testing resize() :" << std::endl;
	std::cout << "str.resize(5) : ";
	str.resize(5);
	std::cout << str.c_str() << std::endl;
	std::cout << "str.size() = " << str.size() << std::endl;
	std::cout << "str.resize(8,'o') : ";
	str.resize(8,'o');
	std::cout << str.c_str() << std::endl;
	std::cout << "str.size() = " << str.size() << std::endl;
	
	std::cout << "Testing operators :" << std::endl;
	str = 'e';
	std::cout << "str = 'e' : " << str.c_str()<<std::endl;
	std::cout << "str.size() = " << str.size() << std::endl;

	return 0;
}
