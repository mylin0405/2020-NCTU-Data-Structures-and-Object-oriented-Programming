## Chapter Summary
• A constructor is a member function of a class that is called automatically when an  
object of the class is declared. A constructor must have the same name as the class of  
which it is a member.  
• A default constructor is a constructor with no parameters. You should always define a  
default constructor for your classes.  
• A member variable for a class may itself be of a class type. If a class has a class member  
variable, then the member variable constructor can be invoked in the initialization  
section of the outer class constructor.  
• A constant call-by-reference parameter is more efficient than a call-by-value parameter  
for class type parameters.  
• Making very short function definitions inline can improve the efficiency of your code.  
• Static member variables are variables that are shared by all objects of a class. //only static members can access static functions  
• Vector classes have objects that behave very much like arrays whose capacity to hold  
elements will automatically increase if more capacity is needed.   

### Constructor
* A constructor is a member function of a class that has the same name as the class.
* A constructor is called automatically when an object of the class is declared. Constructors
are used to initialize objects. A constructor must have the same name as the class of which  
it is a member.   

Preferable method to define constructor.  
```=c++
DayOfYear::DayOfYear(int monthValue, int dayValue)
 : month(monthValue), day(dayValue)
{/*Body intentionally empty*/}
```
Calling a Constructor  
A constructor is called automatically when an object is declared, but you must give the  
arguments for the constructor when you declare the object. A constructor can also be called  
explicitly, but the syntax is different from what is used for ordinary member functions.  
**SYNTAX FOR AN OBJECT DECLARATION WHEN YOU HAVE CONSTRUCTORS**
```
Class_Name Variable_Name(Arguments_for_Constructor);
EXAMPLE
DayOfYear holiday(7, 4);
```
**SYNTAX FOR AN EXPLICIT CONSTRUCTOR CALL**
```
Variable = Constructor_Name(Arguments_For_Constructor);
EXAMPLE
holiday = DayOfyear(10, 31);
```
A constructor must have the same name as the class of which it is a member. Thus, in the
previous syntax descriptions, Class_Name and Constructor_Name are the same identifier. 

Example (page 280)
* Line 25 shows how to call constructor(noticed: default constructor)
```=c++
#include <iostream>
 2 #include <cstdlib> //for exit
 3 using namespace std;
 4 class DayOfYear
 5 {
 6 public:
 7 DayOfYear( int monthValue, int dayValue);
 8 //Initializes the month and day to arguments.
 9 DayOfYear( int monthValue);
10 //Initializes the date to the first of the given month.
11 DayOfYear( );
12 //Initializes the date to January 1.
13 void input( );
14 void output( );
15 int getMonthNumber( );
16 //Returns 1 for January, 2 for February, etc.
17 int getDay( );
18 private:
19 int month;
20 int day;
21 void testDate( );
22 };
23 int main( )
24 {
25 DayOfYear date1(2, 21), date2(5), date3;
26 cout << "Initialized dates:\n";
27 date1.output( ); cout << endl;
28 date2.output( ); cout << endl;
29 date3.output( ); cout << endl;
30 date1 = DayOfYear(10, 31);
31 cout << "date1 reset to the following:\n";
32 date1.output( ); cout << endl;
33 return 0;
34 }
35
36 DayOfYear::DayOfYear( int monthValue, int dayValue)
37                              : month(monthValue), day(dayValue)
38 {
39 testDate( );
40 }
41 DayOfYear::DayOfYear( int monthValue) : month(monthValue), day(1)
42 {
43 testDate( );
44 }
45 DayOfYear::DayOfYear( ) : month(1), day(1)
46 { /*Body intentionally empty.*/}
47 //uses iostream and cstdlib:
48 void DayOfYear::testDate( )
49 {
50 if ((month < 1) || (month > 12))
51 {
52 cout << "Illegal month value!\n";
53 exit(1);
54 }
55 if ((day < 1) || (day > 31))
56 {
57 cout << "Illegal day value!\n";
58 exit(1);
59 }
60 } 
```

## Const.
const Parameter Modifier  
If you place the modifier const before the type for a call-by-reference parameter, the  
parameter is called a constant parameter. When you add the const you are telling the  
compiler that this parameter should not be changed. If you make a mistake in your  
definition of the function so that it does change the constant parameter, then the compiler  
will give an error message. Parameters of a class type that are not changed by the    
function ordinarily should be constant call-by-reference parameters rather than call-by-value  
parameters.  
If a member function does not change the value of its calling object, then you can mark the  
function by adding the const modifier to the function declaration. If you make a mistake in  
your definition of the function so that it does change the calling object and the function is  
marked with const, the computer will give an error message. The const is placed at the  
end of the function declaration, just before the final semicolon. The heading of the function  
definition should also have a const so that it matches the function declaration.  
```
EXAMPLE
class Sample
{
public:
Sample( );
void input( );
void output( ) const;
private:
int stuff;
double moreStuff;
};
int compare( const Sample& s1, const Sample& s2);
```
Use of the const modifier is an all or nothing proposition. You should use the const  
modifier whenever it is appropriate for a class parameter and whenever it is appropriate for  
a member function of the class. If you do not use const every time that it is appropriate for  
a class, then you should never use it for that class.  

### Static Variables
Sometimes you want to have one variable that is shared by all the objects of a class.  
For example, you might want one variable to count the number of times a particular  
member function is invoked by all objects of the class. Such variables are called static  
variables and can be used for objects of the class to communicate with each other or  
coordinate their actions.  
Notice that the keyword static is used in the member function declaration but is  
not used in the member function definition.   

## Vectors
```=c++
vector<type> sample(vector size); //example vector<double> v(10);
sample.push_back();
sample.size();

```
