#include "string.h"
// Member constants
//----------------------------------------------------------------------
	const size_t string::MAX_SIZE;
  
// Member functions
//----------------------------------------------------------------------

  // Constructors
  string::string(const char* cstr) {  // From c-string constructor
    // finding size of cstr
    int s=0;
    while(cstr[s] != '\0'){
      ++s;
    }
    ++s;
    if(s>MAX_SIZE){
      throw std::length_error("size of c-string is greater than MAX_SIZE\n");
    }
    
    try{ 
      pointer_ = new char[s];
      for(int i=0; i<s; ++i){
        pointer_[i]=cstr[i];
      }
      size_=s-1; // same size than cstr without null character '\0'
      reserve(s);
    }catch (const std::length_error& le){
      throw std::length_error(le.what());
    }catch (const std::bad_alloc& ba){
      throw std::bad_alloc();
    }
  }

  string::string(const string& model){ // Copy constructor
		size_ = model.size_;
  	reserved_space_ = model.reserved_space_;
		char* ptr = new char[reserved_space_];
		for (int i=0; i<size_ + 1; ++i ){
			ptr[i]=model.pointer_[i];
		}
		pointer_ =ptr;
	} 

  // Destructor
  string::~string(){
    delete[] pointer_;
  }
  
  // Operator=
  string string::operator=(string to_assign){}
  string& string::operator= (const char* s){
  // finding size of s
    try{
      int size=0;
      while(s[size] != '\0'){
        ++size;
      }
      ++size;
    //assign the c-str s to the current object
      delete[] pointer_;
      pointer_ = new char[size];
      for(int i=0; i<size; ++i){
        pointer_[i]=s[i];
      }
      size_=size-1; // same size than s without null character '\0'
      reserve(size);
    }catch (const std::length_error& le) {
      throw std::length_error(le.what());
    }catch (std::bad_alloc& ba) {
      throw std::bad_alloc();
    }
    return (*this);
  }
  string& string::operator=(char to_assign){
	  delete[] pointer_;
    char* ptr = new char[2];
    ptr[0]=to_assign;
    ptr[1]='\0';
    pointer_=ptr;
    size_=1;
    reserve(2);
    return(*this);
  }
  
  // Capacity
  size_t string::size() const noexcept{
		return size_;
	}
  size_t string::length() const noexcept{
    return size_;}
  size_t string::max_size() const noexcept{
    return MAX_SIZE;}

  void string::resize(size_t n, char c){
    if(n>size_){ // adding as many char c as necessary to obtain string of size n
      char* ptr = new char[n+1];
      for(int i=0; i<size_; ++i){
        ptr[i]=pointer_[i];
      }
      for(int j=size_; j<n; ++j){
        ptr[j]=c;
      }
      ptr[n]='\0';
      delete[] pointer_;
      pointer_ = ptr;
      size_=n;
      reserve(n+1);
    }
    if(n<size_){ // cutting string to size n
      char* ptr = new char[n+1];
      for(int i=0; i<n; ++i){
        ptr[i]=pointer_[i];
      }
      ptr[n]='\0';
      delete[] pointer_;
      pointer_ = ptr;
      size_=n;
      reserve(n+1);
    }
  }

  size_t string::capacity() const noexcept{
    return reserved_space_;
  }
  void string::reserve(size_t n){
    if(n>MAX_SIZE){
      throw std::length_error("requested space to reserve is greater than the maximum possible size");
    }else{
      try{
      //we must reserve at least enough space to contain our string
        if(n<size_+1){
          n=size_+1;      
        }
        char* future_pointer= new char[n]; //allocation of the desired space
        for(int i=0;i<size_+1;++i){ //copy of the string in the allocated space
          future_pointer[i]=pointer_[i];
        }
        delete[] pointer_;
        pointer_=future_pointer;
        reserved_space_=n;
      }catch(std::bad_alloc& ba){
        throw std::bad_alloc();
      }
    }
  }
  void string::clear() noexcept{
		//delete pointer_;
		//size_ = 0;
		
	}

  bool string::empty() const noexcept{
    return (size_==0);}
  
  // String Operations
	const char* string::c_str() const noexcept {
		return pointer_;
	}

// Non-member functions
//----------------------------------------------------------------------
  // operator+
  string operator+ (const string& lhs, const string& rhs){
    try{
      string result=string(lhs);
      size_t total_size = lhs.size_ + rhs.size_; //size of the concatenation of the two strings 
      result.reserve(total_size+1);
      result.size_=total_size;
      for (int i=0;i<rhs.size_+1;++i){
        result.pointer_[lhs.size_+i]=rhs.pointer_[i];
      }
      return result;
    }catch (const std::length_error& le) {
      throw std::length_error(le.what());
    }catch (std::bad_alloc& ba) {
      throw std::bad_alloc();
    }
  }

  string operator+(const string& lhs, const char* rhs){    
    string result(lhs);
    // finding size of rhs
    int s=0;
    while(rhs[s] != '\0'){
      ++s;
    }
    ++s;
    size_t total_size = lhs.size_ + s -1;
    result.reserve(total_size+1);
    for(int i=0; i<s; ++i){
      result.pointer_[i+lhs.size_]=rhs[i];
    }
    result.size_=total_size;
    return(result);
  }
  
  string operator+(const char* lhs, const string& rhs){    
    string result(lhs);
    // finding size of lhs
    int s=0;
    while(lhs[s] != '\0'){
      ++s;
    }
    ++s;
    size_t total_size = rhs.size_ + s -1;
    result.reserve(total_size+1);
    for(int i=0; i<s; ++i){
      result.pointer_[i+s-1]=rhs.pointer_[i];
    }
    result.size_=total_size;
    return(result);
  }
  
  string operator+(string str, char to_add){}
