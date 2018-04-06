#include "string.h"
// Member constants
//----------------------------------------------------------------------
	const size_t string::MAX_SIZE; //Maximum size than can be allocated for the c-string pointed by pointer_.
  
// Member functions
//----------------------------------------------------------------------

  // Constructors
  string::string(const char* s) {  
    //precondition : s is null-terminated and is not nullptr
    
    //finding size of cstr
    int csize=0;
    while(s[csize] != '\0'){ 
      ++csize;
    }
    ++csize;
    
    //controlling that the size would not exceed MAX_SIZE
    if(csize>MAX_SIZE){
      throw std::length_error("size of c-string is greater than MAX_SIZE\n");
    }
    
    //copies the character sequence pointed by the given argument (s)
    try{ 
      pointer_ = new char[csize];
      for(int i=0; i<csize; ++i){ 
        pointer_[i]=s[i];
      }
      size_=csize-1; //same size than cstr without null character '\0'
      reserve(csize);
      
    //catch exceptions
    }catch (const std::length_error& le){
      throw std::length_error(le.what());
    }catch (const std::bad_alloc& ba){
      throw std::bad_alloc();
    }
  }

  string::string(const string& model){ 
/*Copy constructor : Construct a copy of model.
    INPUT:
      string& model: Reference to a string (model).
    OUTPUT:
      none
    PRECONDITIONS:
      none
    POSTCONDITIONS:
      none
    EXCEPTION SAFETY:
      There are no effects in case an exception is thrown (strong guarantee). 
      If the resulting string length would exceed the max_size, a length_error 
      exception is thrown.
      A bad_alloc exception is thrown if the function needs to allocate 
      storage and fails. */
		try{
		size_ = model.size_;
  		reserved_space_ = model.reserved_space_;
			char* ptr = new char[reserved_space_];
			for (int i=0; i<size_ + 1; ++i ){
				ptr[i]=model.pointer_[i];
			}
			pointer_ =ptr;

		//catch exceptions
    }catch (const std::length_error& le){
     	throw std::length_error(le.what());
    }catch (const std::bad_alloc& ba){
     	throw std::bad_alloc();
    	}
	} 

  // Destructor
  string::~string(){ //This deallocates all the storage capacity allocated by the string
    delete[] pointer_;
  }
  
  // Operator=
  string& string::operator= (const string& str){
	/*Assigns a new value to the string, replacing its current contents.
    INPUT:
      string& str: reference to a string. The content of str is copied as the new value for the string.
    OUTPUT:
      *this
    PRECONDITIONS:
      none
    POSTCONDITIONS:
      The object is modified: the string has been assigned a new value.
    EXCEPTION SAFETY:
      There are no effects in case an exception is thrown (strong guarantee). 
      If the resulting string length would exceed the max_size, a length_error 
      exception is thrown.
      A bad_alloc exception is thrown if the function needs to allocate 
      storage and fails. */
		try{
			delete[] pointer_;

			//copying str into *this:
			size_ = str.size_;
			pointer_ = new char[size_ + 1];
			for(int i=0; i<size_; ++i){
        pointer_[i]=str.pointer_[i];
      }
			pointer_[size_]= '\0';

			reserve(size_);
			return(*this);

		//catch exceptions
		}catch (const std::length_error& le) {
      throw std::length_error(le.what());
    }catch (std::bad_alloc& ba) {
      throw std::bad_alloc();
    }
	}

  string& string::operator= (const char* s){
  /*Assigns a new value to the string, replacing its current contents.
    INPUT:
      char* s: Pointer to a null-terminated sequence of characters. The sequence is copied as the new value for the string.
    OUTPUT:
      *this
    PRECONDITIONS:
      s is null-terminated and is not nullptr
    POSTCONDITIONS:
      The object is modified: the string has been assigned a new value
    EXCEPTION SAFETY:
      There are no effects in case an exception is thrown (strong guarantee). 
      If the resulting string length would exceed the max_size, a length_error 
      exception is thrown.
      A bad_alloc exception is thrown if the function needs to allocate 
      storage and fails. */

  // finding size of s
    try{
      int size=0;
      while(s[size] != '\0'){ //s is null-terminated
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
      return (*this);
    
    //catch exceptions
    }catch (const std::length_error& le) {
      throw std::length_error(le.what());
    }catch (std::bad_alloc& ba) {
      throw std::bad_alloc();
    }
  }

  string& string::operator=(char c){
  //Precondition : c is not null

    //copying c into this.pointer_ :
	  try{
      delete[] pointer_;
      char* ptr = new char[2];
      ptr[0]=c;
      ptr[1]='\0';
      pointer_=ptr;
      size_=1;
      reserve(2);
      return(*this);
      
    //catch exceptions
    }catch (const std::length_error& le){
      throw std::length_error(le.what());
    }catch (const std::bad_alloc& ba){
      throw std::bad_alloc();
    }
  }
  
  // Capacity
  size_t string::size() const noexcept{
 	/*Returns the size of the string, in terms of bytes, from the first
    character to the first null-character encountered (excluded). Synonym to length().
    INPUT:
      none
    OUTPUT:
      size_t size_ : the value corresponding to the number of bytes in the string.
    PRECONDITIONS:
      none
    POSTCONDITIONS:
      none
    EXCEPTION SAFETY:
      No-throw guarantee: this member function never throws exceptions.*/
		return size_;}

  size_t string::length() const noexcept{
    //Synonym of size()
    return size_;}
    
  size_t string::max_size() const noexcept{
    return MAX_SIZE;}

  void string::resize(size_t n, char c){
      
    //controlling that the size would not exceed MAX_SIZE
    if(n>MAX_SIZE){
      throw std::length_error("requested size is greater than MAX_SIZE\n");
    }
    
    try{
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
      
    //catch exceptions
    }catch (const std::length_error& le){
      throw std::length_error(le.what());
    }catch (const std::bad_alloc& ba){
      throw std::bad_alloc();
    }
  }


  size_t string::capacity() const noexcept{
  /*Returns the size of the storage space currently allocated for the string, 
    expressed in terms of bytes. This capacity is not necessarily equal to 
    the string length + 1 (for the '\0'). It can be equal or greater.
    Notice that this capacity does not suppose a limit on the length of 
    the string. When this capacity is exhausted and more is needed, 
    it is automatically expanded by the object (reallocating it storage space).
    INPUT:
      none
    OUTPUT:
      size_t reserved_space_: the size of the storage capacity currently allocated for the string.
    PRECONDITIONS:
      none
    POSTCONDITIONS:
      The object is unmodified
    EXCEPTION SAFETY:
      This member function never throws exceptions.*/
    return reserved_space_;
  }


  void string::reserve(size_t n){
  /*Requests that the string capacity be adapted to a planned change in 
    size to a length of up to n characters.
    If n is greater than the current string capacity, the function causes 
    the container to increase its capacity to n characters.
    In all other cases, it is taken as a non-binding request to shrink 
    the string capacity: the container will adapt its capacity to n OR to 
    the size of the string pointed by pointer_.
    This function has no effect on the string length and cannot alter its content.
    INPUT:
      size_t n: Planned length for the string. Note that the resulting string capacity may be equal or greater than n.
    OUTPUT:
      none
    PRECONDITIONS:
      none
    POSTCONDITIONS:
      The object is modified: the size of the container has (probably) changed in size.
    EXCEPTION SAFETY:
      If an exception is thrown, there are no changes in the string.
      If n is greater than the max_size, a length_error exception is thrown.
      A bad_alloc exception is thrown if the function needs to allocate storage and fails.*/

    //catch the length_error exceptions
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

      //catch the bad_alloc exceptions
      }catch(std::bad_alloc& ba){
        throw std::bad_alloc();
      }
    }
  }


  void string::clear() noexcept{
  /* Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
    INPUT:
      none
    OUTPUT:
    	none
    PRECONDITIONS:
      none
    POSTCONDITIONS:
      The object is modified : the string is now empty.
    EXCEPTION SAFETY:
      This member function never throws exceptions.*/
		resize( 0);	
	}


  bool string::empty() const noexcept{
  /*Returns whether the string is empty (i.e. whether its length is 0).
    INPUT:
      none
    OUTPUT:
      bool: true if the string length is 0, false otherwise.
    PRECONDITIONS:
      none
    POSTCONDITIONS:
      The object is unmodified.
    EXCEPTION SAFETY:
      This member function never throws exceptions.*/
    return (size_==0);
  }

  
  // String Operations
	const char* string::c_str() const noexcept {
  /*Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object. This array includes the same sequence of characters that make up the value of the string object plus an additional terminating null-character ('\0') at the end.
    INPUT:
      none
    OUTPUT:
      A pointer to the c-string representation of the string object's value.
    PRECONDITIONS:
      none
    POSTCONDITIONS:
      The object is unmodified.
    EXCEPTION SAFETY:
      This member function never throws exceptions.*/
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
    try{
      string result(lhs);
      
      // finding size of rhs
      int s=0;
      while(rhs[s] != '\0'){
        ++s;
      }
      ++s;
      
      //finding size of lhs
      size_t total_size = lhs.size_ + s -1;
      result.reserve(total_size+1);
      
      //concatenation of rhs into result
      for(int i=0; i<s; ++i){
        result.pointer_[i+lhs.size_]=rhs[i];
      }
      result.size_=total_size;
      return(result);
      
    //catch exceptions
    }catch (const std::length_error& le){
      throw std::length_error(le.what());
    }catch (const std::bad_alloc& ba){
      throw std::bad_alloc();
    }
  }
  
  string operator+(const char* lhs, const string& rhs){ 
    try{   
      string result(lhs);
      
      //finding size of lhs
      int csize=0;
      while(lhs[csize] != '\0'){
        ++csize;
      }
      ++csize;
      
      //reserve storage necessary
      size_t total_size = rhs.size_ + csize -1;
      result.reserve(total_size+1);
      
      //concatenation of rhs into result
      for(int i=0; i<csize; ++i){
        result.pointer_[i+csize-1]=rhs.pointer_[i];
      }
      result.size_=total_size;
      return(result);
      
    //catch exceptions
    }catch (const std::length_error& le){
      throw std::length_error(le.what());
    }catch (const std::bad_alloc& ba){
      throw std::bad_alloc();
    }
  }
  
	string operator+ (const string& lhs, char rhs){
		try{
			string result(lhs);
			size_t rsize=result.size(); //result's size
			result.reserve(rsize + 2);
			result.pointer_[rsize ]=rhs;
			result.pointer_[rsize + 1]='\0';
			result.size_ = rsize+1; //total size 
			return(result);

		//catch exceptions
 		}catch (const std::length_error& le){
      throw std::length_error(le.what());
    }catch (const std::bad_alloc& ba){
      throw std::bad_alloc();
    }
	}

	string operator+ (char lhs, const string& rhs){
		try{
			char clhs[]={lhs,'\0'};
			string result(clhs);
			size_t rsize=rhs.size(); //rhs's size
			result.reserve(rsize + 2);
			//copying rhs into result :
			for(int i=0; i<=rsize; ++i){
				result.pointer_[i+1]=rhs.pointer_[i];
			}
			result.pointer_[rsize+1]='\0';
			result.size_=rsize + 1; //total size
			return(result);

		// catch exceptions
 		}catch (const std::length_error& le){
      throw std::length_error(le.what());
    }catch (const std::bad_alloc& ba){
      throw std::bad_alloc();
    }
	}
