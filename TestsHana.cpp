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

	//testing clear()
	std::cout << "Testing clear()" << std::endl;
	str2.clear();
	std::cout << "str2 = " << str2.c_str() << std::endl;		
	std::cout << "str2's length = " << str2.length() << std::endl;	

	//testing operator +(char)
	std::cout << "Testing operator +(char)" << std::endl;
	char c1 = 'T';
	std::cout << "str1's size = " << str1.size() << std::endl;	
	string str3(str1 + c1);
	std::cout << "str3 = str1 + 'T' = " << str3.c_str() << std::endl;	
	std::cout << "str3's size= " << str3.size() << std::endl;	
	string str4(c1 + str1);
	std::cout << "str4 = 'T' + str1= " << str4.c_str() << std::endl;
	std::cout << "str4's size= " << str4.size() << std::endl;	

	//testing operator =(string)
	std::cout << "Testing operator =(string)" << std::endl;
	str4 = str1;
	std::cout << "str4 = str1 = " << str4.c_str() << std::endl;	
	std::cout << "str4 = str1 size= " << str4.size() << std::endl;
	str3 = str2;		
	std::cout << "str3 = str2 = " << str3.c_str() << std::endl;	
	std::cout << "str3 = str2 size= " << str3.size() << std::endl;
	return 0;
}
