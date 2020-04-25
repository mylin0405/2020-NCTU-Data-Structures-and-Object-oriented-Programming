/* OOP HW1 Polynomial
* Author: Unfish0705
* Last Modified: 2020/4/25
*/

#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace std;

class Polynomial
{
	public:
		void input(const int &y); // input x value;
		void input(int &n, int &temp_coef); // input coef to vector[n]
		void caculate();
		void firstDerivative();
		void secDerivative();
	
	private:
		vector<int> coef;
		int x;	
}; 

void Polynomial :: input(const int &y)
{
	x = y;
} 
void Polynomial :: input(int &n, int &temp_coef)
{
	coef.push_back(temp_coef);
}

void Polynomial :: caculate()
{
	int length;
	length = coef.size();
	long long sum=0, exp=1; //2^31 + 2^31 maybe overflow;
	for(int i=length-1;i>=0;i--)
	{		
		sum += coef[i]*exp;
		exp *= x;
	}
	cout << sum << " ";
}

void Polynomial :: firstDerivative()
{
	int length;
	length = coef.size();
	long long sum=0, exp=1; //2^31 + 2^31 maybe overflow;
	for(int i=length-2;i>=0;i--)
	{		
		sum += coef[i]*exp*(length-i-1);
		exp *= x;		
	}
	cout << sum << " ";
}

void Polynomial :: secDerivative()
{
	int length;
	length = coef.size();
	long long sum=0, exp=1; //2^31 + 2^31 maybe overflow;
	for(int i=length-3;i>=0;i--)
	{		
		sum += coef[i]*exp*(length-i-1)*(length-i-2);
		exp *= x;
		cout << sum;		
	}
	//cout << sum ;
}

int main()
{
	int y, temp;	
	while(cin >> y)
	{
		int n=0;
		Polynomial a;
		a.input(y);
		while(cin >> temp)
		{
			a.input(n,temp);
			if(getchar() == '\n')
			{
				break;	
			}
			n++;		
		}
		a.caculate();
		a.firstDerivative();
		a.secDerivative();
	}	
	return 0;		
} 
