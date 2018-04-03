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
  char* pointer_;
  size_t size_;
  size_t reserved_space_;
  
// Member constants
//----------------------------------------------------------------------
	const static size_t MAX_SIZE = 100;
  
// Member functions
//----------------------------------------------------------------------
  public :
  // Constructors
  string(const char* cstr); // From c-string constructor
  string(const string& model); // Copy constructor

  // Destructor
  ~string();
  
  // Operator=
  string operator=(string to_assign);
  string& operator= (const char* s);
  string& operator=(char to_assign);
  
  // Capacity
  size_t size() const noexcept;// returns the size_ of the string
  size_t length() const noexcept;
  size_t max_size() const noexcept;
  void resize(size_t n, char c=' ');
  size_t capacity() const noexcept;
  void reserve(size_t n=0);
  void clear() noexcept;
  bool empty() const noexcept;
  
  // String Operations
  const char* c_str() const noexcept;
  
};

// Non-member functions
//----------------------------------------------------------------------
// operator+
string operator+(const string& lhs, const char* rhs);
string operator+(const char* lhs, const string& rhs);
string operator+(string str, char to_add);

#endif
