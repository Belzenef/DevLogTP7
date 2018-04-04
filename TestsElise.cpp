#include <iostream>
#include "string.h"

int main(int argc, char* argv[]){
	std::cout << "Creating c_string :" << std::endl;
	char cstr[] = {'H','e','l','l','o',' ','W','o','r','l','d',' ','!','\0'};
	std::cout << cstr << std::endl;
	
	std::cout << "Testing from c-string constructor :" << std::endl;
	string str(cstr);
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
	str = 'H';
	std::cout << "str = 'H' : " << str.c_str()<<std::endl;
	std::cout << "str.size() = " << str.size() << std::endl;
	char cstr1[] = {'H','e','l','l','o',' ','\0'};
	string str1(cstr1);
	char cstr2[] = {'W','o','r','l','d',' ','!','\0'};
	string str2(str1 + cstr2);
	std::cout << "string str2(str1 + cstr2) : " << str2.c_str()<<std::endl;
	std::cout << "str2.size() = " << str2.size() << std::endl;
	string str3(cstr2 + str1);
	std::cout << "string str3(cstr2 + str1) : " << str3.c_str()<<std::endl;
	std::cout << "str3.size() = " << str3.size() << std::endl;
	
	std::cout << "Testing exceptions :" << std::endl;
	char long_cstr[106];
	for(int i=0; i<105; ++i){
		long_cstr[i]='e';
	}
  long_cstr[105] = '\0';
  //string str4(long_cstr);
  //string str5(long_cstr + str1);
  //str.resize(200);
  std::cout << "Uncomment previous lines one by one to test exceptions.\nTests previously done went well" << std::endl;
	return 0;
}
