## Chapter Summary
```=c++
SYNTAX
class Class_Name
{
.
public:
 Member_Specification_N+1
Member_Specification_N+2
.
.
.
private:
Member_Specification_1
Member_Specification_2
.
.
.
Member_Specification_N
};
```
A structure can be used to combine data of different types into a single (compound)
data value.  
* A class can be used to combine data and functions into a single (compound) object.
* A member variable or a member function for a class can be either public or private.
If it is public, it can be used outside the class. If it is private, it can be used only in  
the definition of a member function.  
* A function can have formal parameters of a class or structure type. A function can
return values of a class or structure type.
* A member function for a class can be overloaded in the same way as ordinary
functions are overloaded.
* When defining a C++ class, you should separate the interface and implementation so
that any programmer who uses the class need only know the interface and need not    
even look at the implementation. This is the principle of encapsulation.   
