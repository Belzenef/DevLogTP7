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

  //Copy constructor
  string::string(const string& model){ 
		try{
			size_ = model.size_;
  		reserved_space_ = model.reserved_space_;
			char* ptr = new char[reserved_space_];
			//copying the content of model
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
  string::~string(){ 
    delete[] pointer_;//Only the space for the null terminated string was allocated
  }
  
  // Operator=
  string& string::operator= (const string& str){
	//Assigns a new value to the string, replacing its current contents.
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
 	//Returns the size of the string, in terms of bytes, from the first character to the first null-character encountered (excluded). Synonym to length().
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
    return reserved_space_;
  }


  void string::reserve(size_t n){
    //catch the length_error exceptions
    if(n>MAX_SIZE){
      throw std::length_error("requested space to reserve is greater than the maximum possible size");
    }else{

      try{
      //we must reserve at least enough space to contain our string (+the '\0' terminating it)
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
  // Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
		resize( 0);	
	}


  bool string::empty() const noexcept{
    return (size_==0); //the string is empty <=> string's size=0
  }

  
  // String Operations
	const char* string::c_str() const noexcept {
  //Returns a pointer to an array that contains a null-terminated sequence of characters representing the current value of the string object. 
		return pointer_;
	}

// Non-member functions
//----------------------------------------------------------------------
  // operator+

  string operator+ (const string& lhs, const string& rhs){
    try{
      string result=string(lhs); //result will be the concatenation of lhs and rhs in this order
      size_t total_size = lhs.size_ + rhs.size_; //size of the concatenation of the two strings 
      result.reserve(total_size+1); //the +1 stands for the '\0' terminating the string
      result.size_=total_size;
      
      //we go through rhs, copying each of its characters at the end of result (which was previously initialized with the value of lhs).
      for (int i=0;i<rhs.size_+1;++i){
        result.pointer_[lhs.size_+i]=rhs.pointer_[i];
      }
      return result;

    //catch exceptions
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
