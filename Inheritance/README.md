## Class Note
```=c++
class HourlyEmplyee : public Employee
{
// friend function無法繼承
// 繼承到的private memeber沒辦法用!!
public:
  //不能繼承Constructor
  HourlyEmployee();
  //ADD Some new functions
  ........
  //Redefine
  void printcheck();
private:
 //ADD some variable;
};

//Derived Class Constructor Example
HourlyEmployee::HourlyEmployee(string theName, string theNumber, double theWageRate, double theHours)
                                : Employee(theName, theNumber), wageRate(theWageRate), hours(theHours){}

```

