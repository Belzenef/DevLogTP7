/*This is an implementation of the standard c++ string class: http://www.cplusplus.com/reference/string/string/ */

#ifndef STRING_H  // if guard
#define STRING_H

#include <cstdio>
#include <stdexcept>

class string{
  
// Non-member functions
//----------------------------------------------------------------------
  // operator+

  friend string operator+ (const string& lhs, const string& rhs);
	friend string operator+(const string& lhs, const char* rhs);
	friend string operator+(const char* lhs, const string& rhs);
  friend string operator+(string str, char to_add);
  
// Member types
//----------------------------------------------------------------------
  protected :
  char* pointer_; //pointer to the null terminated string 
  size_t size_; //size of the string (number of char in the c-string, minus the '\0')
  size_t reserved_space_; //allocated space for the c-string. At least equal to size_+1 (for the '\0')
  
// Member constants
//----------------------------------------------------------------------
	const static size_t MAX_SIZE = 100; //Maximum size than can be allocated for the c-string pointed by pointer_.
  
// Member functions
//----------------------------------------------------------------------
  public :
  // Constructors
  string(const char* cstr); // From c-string constructor
  string(const string& model); // Copy constructor

  // Destructor
  ~string(); //This deallocates all the storage capacity allocated by the string
  
  // Operator=
  string operator=(string to_assign);
  string& operator= (const char* s); //Assigns a new value to the string, replacing its current contents.
  string& operator=(char to_assign);
  
  // Capacity
  size_t size() const noexcept;// returns the size_ of the string
  size_t length() const noexcept;
  size_t max_size() const noexcept;
  void resize(size_t n, char c=' ');
  size_t capacity() const noexcept; //Returns the size of the storage space currently allocated for the string, expressed in terms of bytes.
  void reserve(size_t n=0); //Requests that the string capacity be adapted to a planned change in size to a length of up to n characters.
  void clear() noexcept;
  bool empty() const noexcept; //Returns whether the string is empty (i.e. whether its length is 0).
  
  // String Operations
  const char* c_str() const noexcept;
  
};

// Non-member functions
//----------------------------------------------------------------------
// operator+

//Returns a newly constructed string object with its value being the concatenation of the characters in lhs followed by those of rhs.
string operator+(const string& lhs, const char* rhs);
string operator+(const char* lhs, const string& rhs);
string operator+(string str, char to_add);

#endif
