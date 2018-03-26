#include "string.h"
  
// Member constants
//----------------------------------------------------------------------
	const size_t string::MAX_SIZE;
  
// Member functions
//----------------------------------------------------------------------

  // Constructors
  string::string(char* cstr) {} // From c-string constructor
  string::string(const string& model){} // Copy constructor

  // Destructor
  string::~string(){}
  
  // Operator=
  string string::operator=(string to_assign){}
  string string::operator=(char* to_assign){}
  string string::operator=(char to_assign){}
  
  // Capacity
  size_t string::size() const noexcept{}
  size_t string::length() const noexcept{}
  size_t string::max_size() const noexcept{}
  void string::resize(size_t n, char c){}
  size_t string::capacity() const noexcept{}
  void string::reserve(size_t n){}
  void string::clear() noexcept{}
  bool string::empty() const noexcept{}
  
  // String Operations
  const char* string::c_str() const noexcept{}

// Non-member functions
//----------------------------------------------------------------------
  // operator+
  string operator+(string str, string to_add){}
  string operator+(string str, char* to_add){}
  string operator+(string str, char to_add){}
