## Chapter summary
• Operators, such as + and == , can be overloaded so that they can be used with objects  
of a class type that you define.  
• An operator is just a function that uses a different syntax for invocations.  
• A friend function of a class is an ordinary function except that it has access to the  
private members of the class, just like member functions do.  
• When an operator is overloaded as a member of a class, the first operand is the  
calling object.   
• If your classes each have a full set of accessor functions, then the only reason to make  
a function a friend is to make the definition of the friend function simpler and more  
efficient, but that is often reason enough.  
• A reference is a way of naming a variable. It is essentially an alias for the variable.  
• When overloading the >> or << operators, the type returned should be a stream type  
and should be a reference, which is indicated by appending an & to the name of the  
returned type.   

### Return by const value
```
const Money operator +( const Money& amount1, const Money& amount2);
```
The first const on the line is a new use of the const modifier. This is called **returning
a value as const or returning by const value or returning by constant value**.
Note that although it is legal, it is pointless to return basic types, such as int , by  
const value. The const has no effect in the case of basic types. When a function or  
operator returns a value of one of the basic types, such as int , double , or char , it  
returns the value, such as 5 , 5.5 , or 'A' . It does not return a variable or anything  
like a variable. Unlike a variable, the value cannot be changed—you cannot change 5 .  
Values of a basic type cannot be changed whether there is a const before the returned  
type or not. On the other hand, values of a class type—that is, objects—can be  
changed, since they have member variables, and so the const modifier has an effect  
on the object returned.  
Operator Overloading as 
```
const Money Money::operator +( const Money& amount1, const Money& amount2) const
First const returns a object as a const; Final const makes sure this member function cannot change the callingobjetct values.
```
### Friend Functions
Direct access to class memeber functions.
A friend function of a class is an ordinary function except that it has access to the private  
members of objects of that class. To make a function a friend of a class, you must list the  
function declaration for the friend function in the class defi nition. The function declaration  
is preceded by the keyword friend. The function declaration may be placed in either the  
private section or the public section, but it will be a public function in either case, so it is  
clearer to list it in the public section.
SYNTAX OF FRIEND FUNCTION
```
class Class_Name
{
public:
friend Declaration_for_Friend_Function_1
friend Declaration_for_Friend_Function_2
.
.
.
Member_Function_Declarations
private:
Private_Member_Declarations
};
```

### More overloading
```
ostream& operator <<(ostream& outputStream, const Money& amount)
{
/*This part is the same as the body of
Money::output which is given in Display 8.1 (except that
 dollars is replaced with amount.dollars
and cents is replaced by amount.cents).*/
return outputStream;
}
```
```
istream& operator >>(istream& inputStream, Money& amount)
{
/*This part is the same as the body of
Money::input, which is given in Display 8.1 (except that
 dollars is replaced with amount.dollars
and cents is replaced by amount.cents).*/
return inputStream;
}
```
```
DECLARATIONS
class Class_Name
{
. . .
public:
. . .
friend istream& operator >>(istream& Parameter_1,
Class_Name& Parameter_2);
friend ostream& operator <<(ostream& Parameter_3,
const Class_Name& Parameter_4);
```

