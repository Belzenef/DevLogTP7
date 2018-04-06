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
  friend string operator+ (char lhs, const string& rhs);
	friend string operator+ (const string& lhs, char rhs);
  
// Member types
//----------------------------------------------------------------------
  protected :
  char* pointer_; // Pointer to the null terminated string 
  size_t size_; // Size of the string (number of char in the c-string, minus the '\0')
  size_t reserved_space_; // Allocated space for the c-string. At least equal to size_+1 (for the '\0')
  
// Member constants
//----------------------------------------------------------------------
	const static size_t MAX_SIZE = 100; // Maximum size than can be allocated for the c-string pointed by pointer_.
  
// Member functions
//----------------------------------------------------------------------
  public :
  // Constructors
  string(const char* s); // From c-string constructor
  string(const string& model); // Copy constructor

  // Destructor
  ~string(); // This deallocates all the storage capacity allocated by the string
  
  // Operator=
  // Assigns a new value to the string, replacing its current contents.
  string& operator= (const string& str);
  string& operator= (const char* s);
  string& operator=(char c);
  
  // Capacity
  size_t size() const noexcept; // Returns the size_ of the string
  size_t length() const noexcept; // Synonym of size()
  size_t max_size() const noexcept; // Returns the maximum size that can be allocated to the string
  void resize(size_t n, char c=' '); // Resizes the string by cuting it or adding char c at the end (default value is space)
  size_t capacity() const noexcept; // Returns the size of the storage space currently allocated for the string, expressed in terms of bytes.
  void reserve(size_t n=0); // Requests that the string capacity be adapted to a planned change in size to a length of up to n characters.
  void clear() noexcept; // Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
  bool empty() const noexcept; // Returns whether the string is empty (i.e. whether its length is 0).
  
  // String Operations
  const char* c_str() const noexcept; // Returns a pointer to an array that contains a null-terminated sequence of characters representing the current value of the string object. 

  
};

// Non-member functions
//----------------------------------------------------------------------
// operator+

// Returns a newly constructed string object with its value being the concatenation of the characters in lhs followed by those of rhs.
string operator+(const string& lhs, const char* rhs);
string operator+(const char* lhs, const string& rhs);
string operator+ (char lhs, const string& rhs);
string operator+ (const string& lhs, char rhs);

#endif
