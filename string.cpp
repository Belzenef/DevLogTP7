#include "string.h"
// Member constants
//----------------------------------------------------------------------
	const size_t string::MAX_SIZE; //Maximum size than can be allocated for the c-string pointed by pointer_.
  
// Member functions
//----------------------------------------------------------------------

  // Constructors
  string::string(const char* s) {  
    /*From c-string constructor :
    Copies the character sequence pointed by the given argument (s)
    INPUT:
      const char* s: Pointer to a null-terminated sequence of characters.
    OUTPUT:
      none
    PRECONDITIONS:
      s is null-terminated and is not nullptr
    POSTCONDITIONS:
      none
    EXCEPTION SAFETY:
      There are no effects in case an exception is thrown (strong guarantee). 
      If the resulting string length would exceed the max_size, a length_error 
      exception is thrown.
      A bad_alloc exception is thrown if the function needs to allocate 
      storage and fails. */
      
    int csize=0;
    while(s[csize] != '\0'){ // finding size of cstr
      ++csize;
    }
    ++csize;
    
    if(csize>MAX_SIZE){
      throw std::length_error("size of c-string is greater than MAX_SIZE\n");
    }
    
    try{ 
      pointer_ = new char[csize];
      for(int i=0; i<csize; ++i){
        pointer_[i]=s[i];
      }
      size_=csize-1; // same size than cstr without null character '\0'
      reserve(csize);
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
  string::~string(){ //This deallocates all the storage capacity allocated by the string
    delete[] pointer_;
  }
  
  // Operator=
  string& string::operator= (const string& str){
		try{

			//assign char c to the current object
			//delete[] pointer_;
			//string copy(str);
			/*size_ = str.size_;
			pointer_ = new char[size_ + 1];
			
			for(int i=0; i<size_; ++i){
        pointer_[i]=str[i];
      }
			pointer_[size_ + 1]= '\0';
			reserve(size_);*/
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
  /*Assigns a new value to the string, replacing its current contents to 
   a single copy of the parameter given.
    INPUT:
      char c: a character, copied as the new value for the string.
    OUTPUT:
      *this
    PRECONDITIONS:
      c is not null
    POSTCONDITIONS:
      The object is modified: the string has been assigned a new value
    EXCEPTION SAFETY:
      There are no effects in case an exception is thrown (strong guarantee). 
      If the resulting string length would exceed the max_size, a length_error 
      exception is thrown.
      A bad_alloc exception is thrown if the function needs to allocate 
      storage and fails. */

	  try{
      delete[] pointer_;
      char* ptr = new char[2];
      ptr[0]=c;
      ptr[1]='\0';
      pointer_=ptr;
      size_=1;
      reserve(2);
      return(*this);
      
    }catch (const std::length_error& le){
      throw std::length_error(le.what());
    }catch (const std::bad_alloc& ba){
      throw std::bad_alloc();
    }
  }
  
  // Capacity
  size_t string::size() const noexcept{
		return size_;}
  size_t string::length() const noexcept{
    /*Returns the length of the string, in terms of bytes, from the first
    character to the first null-character encountered (excluded).  
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
    
  size_t string::max_size() const noexcept{
    /*Returns the maximum potential length the string can reach 
    due the limitation implemented as MAX_SIZE.
    INPUT:
      none
    OUTPUT:
      size_t MAX_SIZE : the value corresponding to the maximum length the string can reach.
    PRECONDITIONS:
      none
    POSTCONDITIONS:
      The object is not guaranteed to be able to reach that length: 
      it can still fail to allocate storage at any point before that length is reached. 
    EXCEPTION SAFETY:
      No-throw guarantee: this member function never throws exceptions.*/
      
    return MAX_SIZE;}

  void string::resize(size_t n, char c){
    /*Resizes the string to a length of n characters.
    If n is smaller than the current string length, the current value is 
    shortened to its first n character, removing the characters beyond the nth.
    If n is greater than the current string length, the current content is 
    extended by inserting at the end as many characters as needed to reach 
    a size of n. If c is specified, the new elements are initialized as copies of c, 
    otherwise, they are initialized as spaces (default value).
    INPUT:
      size_t n : the new string length, expressed in number of characters (unsigned)
      char c : (optional) a character used to fill in the spaces added to the string, if it is to be expanded.
    OUTPUT:
      none
    PRECONDITIONS:
      none
    POSTCONDITIONS:
      The object is modified: the string has been assigned a new value
    EXCEPTION SAFETY:
      There are no effects in case an exception is thrown (strong guarantee). 
      If n is greater than max_size, a length_error exception is thrown.
      A bad_alloc exception is thrown if the function needs to allocate storage and fails.*/
      
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
		return pointer_;
	}

// Non-member functions
//----------------------------------------------------------------------
  // operator+

/*Returns a newly constructed string object with its value being the 
 concatenation of the characters in lhs followed by those of rhs.
    INPUT:
      lhs, rhs: Arguments to the left- and right-hand side of the operator, respectively. If of type char*, it shall point to a null-terminated character sequence.
    OUTPUT:
      string result: A string whose value is the concatenation of lhs and rhs, in that order.
    PRECONDITIONS:
      if an input is a char*, it is null-terminated, and is not nullptr.
    POSTCONDITIONS:
      The object is unmodified.
    EXCEPTION SAFETY:
      If an exception is thrown, there are no changes in either string objects.
      If the resulting string length would exceed the max_size, a length_error 
      exception is thrown.
      A bad_alloc exception is thrown if the function needs to allocate 
      storage and fails.
*/

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
      size_t total_size = lhs.size_ + s -1;
      result.reserve(total_size+1);
      for(int i=0; i<s; ++i){
        result.pointer_[i+lhs.size_]=rhs[i];
      }
      result.size_=total_size;
      return(result);
    }catch (const std::length_error& le){
      throw std::length_error(le.what());
    }catch (const std::bad_alloc& ba){
      throw std::bad_alloc();
    }
  }
  
  string operator+(const char* lhs, const string& rhs){ 
    try{   
      string result(lhs);
      // finding size of lhs
      int csize=0;
      while(lhs[csize] != '\0'){
        ++csize;
      }
      ++csize;
      size_t total_size = rhs.size_ + csize -1;
      result.reserve(total_size+1);
      for(int i=0; i<csize; ++i){
        result.pointer_[i+csize-1]=rhs.pointer_[i];
      }
      result.size_=total_size;
      return(result);
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
 		}catch (const std::length_error& le){
      throw std::length_error(le.what());
    }catch (const std::bad_alloc& ba){
      throw std::bad_alloc();
    }
	}
