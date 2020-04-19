/*
* Author: Unfish0705
* Last Modified: 2020/4/19
*/

#include<iostream>
using namespace std;

void swap_call_by_value(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << a << " " << b << endl;
}

void swap_call_by_reference(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << a << " " << b << endl;
}

int main()
{
	int num1 = 1;
	int num2 = 2;
	/*cout << num1 << " " << num2 << endl;
	swap_call_by_value(num1, num2);
	cout << num1 << " " << num2 << endl;*/
	cout << num1 << " " << num2 << endl;
	swap_call_by_reference(num1, num2);
	cout << num1 << " " << num2 << endl;
     
}
