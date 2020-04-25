/* OOP HW1 BIG INTEGER
* Author: Unfish0705
* Last Modified: 2020/4/25
*/

#include<iomanip>  // boolalpha
#include "0617052_1.hpp"

int main()
{
	Large a, b;
	cout << "Please ENTER two number a and b: ";
	cin >> a >> b;
	cout << "a = " << a ;
	cout << "-a = " << -a ;
	cout << "b = " << b ;
	cout << "-b = " << -b ;
	cout << "a > b ? " << boolalpha << (a > b) << endl ;
	cout << "a < b ? " << (a < b) << endl;
	cout << "a = b ? " << (a == b) << endl;
	cout << "a - b = " << (a - b) ;
	cout << "a + b = " << (a + b) ; 
	cout << "a * b = " << (a * b) ;
	cout << "a / b = " << (a / b) ;
} 
