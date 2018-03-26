#ifndef STRING_H  // if guard
#define STRING_H

class string{
  
// Non-member functions
//----------------------------------------------------------------------
  // operator+
  friend string operator+(string);
  friend string operator+(char*);
  friend string operator+(char);
  
// Member types
//----------------------------------------------------------------------
  protected :
  char* pointer_;
  size_t size_;
  size_t reserved_space_;
  
// Member constants
//----------------------------------------------------------------------
	const static size_t MAX_SIZE;
  
// Member functions
//----------------------------------------------------------------------
  public :
  // Constructors
  string(char* cstr); // From c-string constructor
  string(const string& model); // Copy constructor

  // Destructor
  ~string();
  
  // Operator=
  string operator=(string);
  string operator=(char*);
  string operator=(char);
  
  // Capacity
  size_t size() const noexcept;
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
  string operator+(string);
  string operator+(char*);
  string operator+(char);
