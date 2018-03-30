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
  std::cout << "str.capacity() = " << str.capacity() << std::endl;
  
  std::cout << "Testing capacity and reserve :" << std::endl;
  std::cout << "str.capacity() = " << str.capacity() << std::endl;
  str.reserve(3);
  std::cout << "str.capacity() = " << str.capacity() << std::endl;
  str.reserve(13);
  std::cout << "str.capacity() = " << str.capacity() << std::endl;
  str.reserve(14);
  std::cout << "str.capacity() = " << str.capacity() << std::endl;
  str.reserve(20);
  std::cout << "str.capacity() = " << str.capacity() << std::endl;
  std::cout << str.c_str() << std::endl;
	return 0;
}
