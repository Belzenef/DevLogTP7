#include <iostream>
#include "string.h"

int main(int argc, char* argv[]){
	std::cout << "Creating c_string :" << std::endl;
	char cstr[] = {'H','e','l','l','o',' ','W','o','r','l','d',' ','!','\0'};
	std::cout << cstr << std::endl;
  std::cout << "Creating another c_string :" << std::endl;
	char cstr2[] = {'H','i',' ','!','\0'};
	std::cout << cstr2 << std::endl;
	
	std::cout << "Testing from c-string constructor :" << std::endl;
	string str(cstr);
	std::cout << str.c_str() << std::endl;
	std::cout << "str.size() = " << str.size() << std::endl;
  std::cout << "str.capacity() = " << str.capacity() << std::endl;

  string str2(cstr2);
	std::cout << str2.c_str() << std::endl;
	std::cout << "str2.size() = " << str2.size() << std::endl;
  std::cout << "str2.capacity() = " << str2.capacity() << std::endl;
  
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
  std::cout << "str.empty() = " << str.empty() << std::endl;
  std::cout << str.c_str() << std::endl;

  std::cout << "Testing maximum size exception in reserve:" << std::endl;
  str2.reserve(100);
  std::cout << "str2.capacity() = " << str2.capacity() << std::endl;
  /*str2.reserve(101);
  std::cout << "str2.capacity() = " << str2.capacity() << std::endl;*/
  str2 = cstr;
  std::cout << str2.c_str() << std::endl;
	std::cout << "str2.size() = " << str2.size() << std::endl;
  std::cout << "str2.capacity() = " << str2.capacity() << std::endl;

  std::cout << "Testing operator+ :" << std::endl;
  string str3=(str+str2);
  std::cout << str3.c_str() << std::endl;
	std::cout << "(str+str2).size() = " << str3.size() << std::endl;
  std::cout << "(str+str2).capacity() = " << str3.capacity() << std::endl;



  std::cout << "Testing maximum size :" << std::endl;
  char too_long[200];
  for(int k=0; k<199;++k){
    too_long[k]='R';
  }
  too_long[199]='\0';
  /*str2=too_long;
  std::cout << "str2.capacity() = " << str2.capacity() << std::endl;*/

  char almost_too_long[100];
  for(int k=0; k<99;++k){
    almost_too_long[k]='R';
  }
  almost_too_long[99]='\0';
  string str4(almost_too_long);
  std::cout << "str4: " << str4.c_str() << std::endl;
  std::cout << "str2+almost_too_long = " << (str2+str4).c_str() << std::endl;


	return 0;
}
