/* OOP HW1 BIG INTEGER
* Author: Unfish0705
* Last Modified: 2020/4/25
*/

// #ifndef "0617052_1.hpp" macro name does not a name of identifiers

#include<iostream>
#include<cmath>   // abs
#include<string>

using namespace std;

/*Class Large*/
class Large
{
	public:
		friend ostream& operator <<(ostream& os, const Large& test);
		friend istream& operator >>(istream& is, Large& test);
		friend bool operator >(const Large& a, const Large& b);
		friend bool operator ==(const Large& a, const Large& b);
		friend bool operator <(const Large& a, const Large& b);				
		friend Large operator -(const Large& a);	    
		friend Large operator +(const Large& a, const Large& b);
		friend Large operator -(const Large& a, const Large& b);
		friend Large operator *(const Large& a, const Large& b);
		friend Large operator /(const Large& a, const Large& b);
		
	private:
		string BigInteger;
};

ostream& operator <<(ostream& os, const Large& test)
{
	os << test.BigInteger << endl ;
	return os;
}

istream& operator >>(istream& is, Large& test)
{
	is >> test.BigInteger;
	return is;
}

Large operator -(const Large& a)
{
	Large temp = a, temp1 = a;
	if (temp.BigInteger[0] != '-')
	{ 
		temp.BigInteger = "-" + temp.BigInteger;
	}
	else 
	{
		temp.BigInteger.resize(temp.BigInteger.length()-1);
		for(int i=1; i<=temp.BigInteger.length(); i++)
		{
			temp.BigInteger[i-1] = temp1.BigInteger[i];
		}
	}
	return temp;
}

bool operator >(const Large& a, const Large& b)
{
	Large test1 = a, test2 = b, temp;
	int flag = 0;
	if (test1.BigInteger[0] == '-' && test2.BigInteger[0] == '-')
	{
		if (test1.BigInteger.length() > test2.BigInteger.length()) 
			flag = 0;
		else if (test1.BigInteger.length() < test2.BigInteger.length())
		{
			flag = 1; 
		}
		else
		{
			for (int i = 1; i < test1.BigInteger.length(); i++)
			{
				if (test1.BigInteger[i] < test2.BigInteger[i])
				{
					flag = 1; 
					break;
				}
				else if (test1.BigInteger[i] > test2.BigInteger[i])
				{
					flag = 0;
					break;	
				}	
				else flag = 0;
			}
		}
	}
	else if (test1.BigInteger[0] == '-' || test2.BigInteger[0] == '-')
	{
		if (test1.BigInteger[0] == '-')
		{
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
	else
	{
		if (test1.BigInteger.length() > test2.BigInteger.length())
		{
			flag = 1;
		}
		else if (test1.BigInteger.length() < test2.BigInteger.length())
		{
			flag = 0;
		}
		else
		{
			for (int i = 0; i < test1.BigInteger.length(); i++)
			{
				if (test1.BigInteger[i] > test2.BigInteger[i])
				{
					flag = 1;
					break;
				}
				else if(test1.BigInteger[i] < test2.BigInteger[i])
				{
					flag = 0;
					break;
				}
				else flag = 0;
			}
		}
	}
	if (flag == 1) return true;
	if (flag == 0) return false;
}

bool operator <(const Large& a, const Large& b)
{
	Large test1 = a, test2 = b, temp;
	int flag = 0;
	if (test1.BigInteger[0] == '-' && test2.BigInteger[0] == '-')
	{
		if (test1.BigInteger.length() > test2.BigInteger.length()) 
			flag = 1;
		else if (test1.BigInteger.length() < test2.BigInteger.length())
		{
			flag = 0; 
		}
		else
		{
			for (int i = 1; i < test1.BigInteger.length(); i++)
			{
				if (test1.BigInteger[i] > test2.BigInteger[i])
				{
					flag = 1; 
					break;
				}
				if (test1.BigInteger[i] < test2.BigInteger[i])
				{
					flag = 0;
					break;	
				}	
				else flag = 0;
			}
		}
	}
	else if (test1.BigInteger[0] == '-' || test2.BigInteger[0] == '-')
	{
		if (test1.BigInteger[0] == '-')
		{
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	}
	else
	{
		if (test1.BigInteger.length() > test2.BigInteger.length())
		{
			flag = 0;
		}
		else if (test1.BigInteger.length() < test2.BigInteger.length())
		{
			flag = 1;
		}
		else
		{
			for (int i = 0; i < test1.BigInteger.length(); i++)
			{
				if (test1.BigInteger[i] < test2.BigInteger[i])
				{
					flag = 1;
					break;
				}
				else if(test1.BigInteger[i] > test2.BigInteger[i])
				{
					flag = 0;
					break;
				} 
				else
				{
					flag = 0;
				}
			}
		}
	}
	if (flag == 1) return true;
	if (flag == 0) return false;
}

bool operator ==(const Large& a, const Large& b)
{
	Large test1 = a, test2 = b;
	int flag = 0;
	for (int i = 0; i < test1.BigInteger.length(); i++)
		if (test1.BigInteger[i] != test2.BigInteger[i])
		{
			flag = 0;
			break;
		} 		
		else flag = 1;
	if (flag == 1) return true;
	if (flag == 0) return false;
}

Large operator +(const Large& a, const Large& b)
{
	Large test1= a, test2= b, temp;
	if (test1.BigInteger[0] == '-' && test2.BigInteger[0] == '-'){
		if (test1.BigInteger.length() < test2.BigInteger.length())
		{
			temp.BigInteger = test1.BigInteger;
			test1.BigInteger = test2.BigInteger;
			test2.BigInteger = temp.BigInteger;
		}
		int length1 = test1.BigInteger.length();
		int length2 = test2.BigInteger.length();
		int carry = 0;
		int i, j, sum;
		for (; length1 > 1;length1--, length2--) 
		{
			i = test1.BigInteger[length1 - 1] - '0';
			if (length2 > 1)
				j = test2.BigInteger[length2 - 1] - '0';
			else
				j = 0;
			sum = i + j + carry;
			if (sum > 9) 
			{
				test1.BigInteger[length1 - 1] = sum % 10 + '0';
				carry = 1;
			}
			else
			{
				test1.BigInteger[length1 - 1] = sum + '0';
				carry = 0;
			}
		}
		if (carry == 1)
		{
			test1.BigInteger[0]	= 1;
			test1.BigInteger = '-' + test1.BigInteger;			
		}
		return test1;
	}
	else if(test1.BigInteger[0] == '-' || test2.BigInteger[0] == '-')
	{
		if(test1.BigInteger[0] == '-')
		{
			if (-test1 < test2)
			{
				test1 = test2 - (-test1);							
				return test1;	
			}
			else if(-test1 == test2)
			{
				test1 = test2 - (-test1);
				return test1;
			}
			else
			{
				test1 = (-test1) - test2; 
				return (-test1);
			}
		}
		if(test2.BigInteger[0] == '-')
		{
			if(test1 < -test2)
			{
				test1 = (-test2) - test1;
				return (-test1);
				
			}
			else if(test1 == -test2)
			{
				test1 = test1 - (-test2);
				return test1;
			}
			else
			{
				test1 = test1 - (-test2);
				return test1;
			}
		}
	} 
	else
	{
		if (test1.BigInteger.length() < test2.BigInteger.length())
		{
			temp.BigInteger = test1.BigInteger;
			test1.BigInteger = test2.BigInteger;
			test2.BigInteger = temp.BigInteger;
		}
		int length1 = test1.BigInteger.length();
		int length2 = test2.BigInteger.length();
		int carry = 0;
		int i, j, sum;
		for (; length1 > 0;length1--, length2--) 
		{
			i = test1.BigInteger[length1 - 1] - '0';
			if (length2 > 0)
				j = test2.BigInteger[length2 - 1] - '0';
			else
				j = 0;
			sum = i + j + carry;
			if (sum > 9) 
			{
				test1.BigInteger[length1 - 1] = sum % 10 + '0';
				carry = 1;
			}
			else
			{
				test1.BigInteger[length1 - 1] = sum + '0';
				carry = 0;
			}
		}
		if (carry == 1)
			test1.BigInteger = "1" + test1.BigInteger; 
	 
		return test1;
	}
}

Large operator -(const Large& a, const Large& b)
{
	Large test1 = a, test2 = b;  
	Large temp;
	if(test1.BigInteger[0] == '-' && test2.BigInteger[0] == '-') // all nagative
	{
		if(test1 < test2)
		{
			test1 = -test1;
			test2 = -test2;
			int length1 = test1.BigInteger.length();
			int length2 = test2.BigInteger.length();
			int carry = 0;
			int i, j, sum;
			for (; length1 > 0; length1--, length2--)
			{
				i = test1.BigInteger[length1 - 1] - '0';
				if (length2 > 0)
					j = test2.BigInteger[length2 - 1] - '0';
				else
					j = 0;
				sum = i - j + carry;
				if (sum < 0)
				{
					test1.BigInteger[length1 - 1] = 10 - abs(sum) + '0';
					carry = -1;
				}
				else
				{
					test1.BigInteger[length1 - 1] = sum + '0';
					carry = 0;
				}
			}
			while(test1.BigInteger[0] == '0' && test1.BigInteger.length() != 1)
			{
				test1.BigInteger.erase(test1.BigInteger.begin());
			}
			test1.BigInteger = "-" + test1.BigInteger;
			return test1;
		}
		else if(test1 == test2)
		{
			test1.BigInteger = "0" ;
			return test1;
		}
		else
		{
			test1 = -test1;
			test2 = -test2;
			temp.BigInteger = test1.BigInteger;
			test1.BigInteger = test2.BigInteger;
			test2.BigInteger = temp.BigInteger;
			int length1 = test1.BigInteger.length();
			int length2 = test2.BigInteger.length();
			int carry = 0;
			int i, j, sum;
			for (; length1 > 0; length1--, length2--)
			{
				i = test1.BigInteger[length1 - 1] - '0';
				if (length2 > 0)
					j = test2.BigInteger[length2 - 1] - '0';
				else
					j = 0;
				sum = i - j + carry;
				if (sum < 0)
				{
					test1.BigInteger[length1 - 1] = 10 - abs(sum) + '0';
					carry = -1;
				}
				else
				{
					test1.BigInteger[length1 - 1] = sum + '0';
					carry = 0;
				}
			}
			while(test1.BigInteger[0] == '0' && test1.BigInteger.length() != 1)
			{
				test1.BigInteger.erase(test1.BigInteger.begin());
			}
			return test1;			
		}
	}
	else if(test2.BigInteger[0] == '-') // one positive, one negative
	{
		test1 = test1 + (-test2);
		return test1;		
	}
	else if(test1.BigInteger[0] == '-')
	{
		test1 = (-test1) + test2;
		test1 = -test1;
		return test1;
	}
	else // all positive
	{ if(test1 > test2)
	{	
		if (test1.BigInteger.length() < test2.BigInteger.length())
		{
			temp.BigInteger = test1.BigInteger;
			test1.BigInteger = test2.BigInteger;
			test2.BigInteger = temp.BigInteger;
		}
		int length1 = test1.BigInteger.length();
		int length2 = test2.BigInteger.length();
		int carry = 0;
		int i, j, sum;
		for (; length1 > 0; length1--, length2--)
		{
			i = test1.BigInteger[length1 - 1] - '0';
			if (length2 > 0)
				j = test2.BigInteger[length2 - 1] - '0';
			else
				j = 0;
			sum = i - j + carry;
			if (sum < 0)
			{
				test1.BigInteger[length1 - 1] = 10 - abs(sum) + '0';
				carry = -1;
			}
			else
			{
				test1.BigInteger[length1 - 1] = sum + '0';
				carry = 0;
			}
		}
		while(test1.BigInteger[0] == '0' && test1.BigInteger.length() != 1)
		{
			test1.BigInteger.erase(test1.BigInteger.begin());
		}
		return test1;
	}
	 else if(test1 == test2)
	 {
	 	test1.BigInteger = "0";
		return test1;	
	 }
	 else
	 {
	 	temp.BigInteger = test1.BigInteger;
		test1.BigInteger = test2.BigInteger;
		test2.BigInteger = temp.BigInteger;
		int length1 = test1.BigInteger.length();
		int length2 = test2.BigInteger.length();
		int carry = 0;
		int i, j, sum;
		for (; length1 > 0; length1--, length2--)
		{
			i = test1.BigInteger[length1 - 1] - '0';
			if (length2 > 0)
				j = test2.BigInteger[length2 - 1] - '0';
			else
				j = 0;
			sum = i - j + carry;
			if (sum < 0)
			{
				test1.BigInteger[length1 - 1] = 10 - abs(sum) + '0';
				carry = -1;
			}
			else
			{
				test1.BigInteger[length1 - 1] = sum + '0';
				carry = 0;
			}
		}
		while(test1.BigInteger[0] == '0' && test1.BigInteger.length() != 1)
		{
			test1.BigInteger.erase(test1.BigInteger.begin());
		}
		test1.BigInteger = "-" + test1.BigInteger;
		return test1;
	 }
	
	}
}

Large operator *(const Large& a, const Large& b)
{
	Large test1 = a, test2 = b, temp;
	if (test1.BigInteger[0] == '-' && test2.BigInteger[0] == '-'){
	test1 = -test1;
	test2 = -test2;	
	if (test1.BigInteger.length() < test2.BigInteger.length())
		{
			temp.BigInteger = test1.BigInteger;
			test1.BigInteger = test2.BigInteger;
			test2.BigInteger = temp.BigInteger;
		}
	int length1 = test1.BigInteger.length();
	int length2 = test2.BigInteger.length();
	int result[length1+length2]={};    //Forget to Initialize QQQQQ;
	for(int i=length2-1, k=0; i >=0; i--,k++)
	{
		int temp_num1, temp_num2, temp_result;
		temp_num2 = test2.BigInteger[i] - '0';
		for(int j=length1-1, w=k; j>=0; j--,w++)
		{
			temp_num1 = test1.BigInteger[j] - '0';
			temp_result = temp_num1 * temp_num2;
			//cout << temp_result << "," ;
			result[w] += temp_result;
			//cout << result[w] << "result" << w << " " << "," ;
		}
	}
	for(int i=0; i < length1 + length2; i++)
	{
		if(result[i] >= 10)
		{
			result[i+1] += result[i] / 10;
			result[i] %= 10;
		}
	}
	//reverse;
	int final_array[length1+length2]={};
	for(int i=length1+length2-1, j=0; i>=0; i--,j++)
	{
		final_array[i] = result[j];
	}
	test1.BigInteger.resize(length1+length2);
	//copy;
	for(int i=length1+length2-1; i>=0; i--)
	{		
		test1.BigInteger[i] = final_array[i] + '0';
		//cout << final_array[i];
	}
	while(test1.BigInteger[0] == '0' && test1.BigInteger.length() != 1)
	{
		test1.BigInteger.erase(test1.BigInteger.begin());
	}	
	return test1;}
	// a is negative;
	else if (test1.BigInteger[0] == '-'){
	test1 = -test1;	
	if (test1.BigInteger.length() < test2.BigInteger.length())
		{
			temp.BigInteger = test1.BigInteger;
			test1.BigInteger = test2.BigInteger;
			test2.BigInteger = temp.BigInteger;
		}
	int length1 = test1.BigInteger.length();
	int length2 = test2.BigInteger.length();
	int result[length1+length2]={};    //Forget to Initialize QQQQQ;
	for(int i=length2-1, k=0; i >=0; i--,k++)
	{
		int temp_num1, temp_num2, temp_result;
		temp_num2 = test2.BigInteger[i] - '0';
		for(int j=length1-1, w=k; j>=0; j--,w++)
		{
			temp_num1 = test1.BigInteger[j] - '0';
			temp_result = temp_num1 * temp_num2;
			//cout << temp_result << "," ;
			result[w] += temp_result;
			//cout << result[w] << "result" << w << " " << "," ;
		}
	}
	int carry = 0;
	for(int i=0; i < length1 + length2; i++)
	{
		if(result[i] >= 10)
		{
			result[i+1] += result[i] / 10;
			result[i] %= 10;
		}
	}
	//reverse;
	int final_array[length1+length2]={};
	for(int i=length1+length2-1, j=0; i>=0; i--,j++)
	{
		final_array[i] = result[j];
	}
	test1.BigInteger.resize(length1+length2);
	//copy;
	for(int i=length1+length2-1; i>=0; i--)
	{		
		test1.BigInteger[i] = final_array[i] + '0';
		//cout << final_array[i];
	}
	while(test1.BigInteger[0] == '0' && test1.BigInteger.length() != 1)
	{
		test1.BigInteger.erase(test1.BigInteger.begin());
	}
	test1.BigInteger = "-" + test1.BigInteger;	
	return test1;}	
	
	else if (test2.BigInteger[0] == '-'){
	test2 = -test2;	
	if (test1.BigInteger.length() < test2.BigInteger.length())
		{
			temp.BigInteger = test1.BigInteger;
			test1.BigInteger = test2.BigInteger;
			test2.BigInteger = temp.BigInteger;
		}
	int length1 = test1.BigInteger.length();
	int length2 = test2.BigInteger.length();
	int result[length1+length2]={};    //Forget to Initialize QQQQQ;
	for(int i=length2-1, k=0; i >=0; i--,k++)
	{
		int temp_num1, temp_num2, temp_result;
		temp_num2 = test2.BigInteger[i] - '0';
		for(int j=length1-1, w=k; j>=0; j--,w++)
		{
			temp_num1 = test1.BigInteger[j] - '0';
			temp_result = temp_num1 * temp_num2;
			//cout << temp_result << "," ;
			result[w] += temp_result;
			//cout << result[w] << "result" << w << " " << "," ;
		}
	}
	int carry = 0;
	for(int i=0; i < length1 + length2; i++)
	{
		if(result[i] >= 10)
		{
			result[i+1] += result[i] / 10;
			result[i] %= 10;
		}
	}
	//reverse;
	int final_array[length1+length2]={};
	for(int i=length1+length2-1, j=0; i>=0; i--,j++)
	{
		final_array[i] = result[j];
	}
	test1.BigInteger.resize(length1+length2);
	//copy;
	for(int i=length1+length2-1; i>=0; i--)
	{		
		test1.BigInteger[i] = final_array[i] + '0';
		//cout << final_array[i];
	}
	while(test1.BigInteger[0] == '0' && test1.BigInteger.length() != 1)
	{
		test1.BigInteger.erase(test1.BigInteger.begin());
	}
	test1.BigInteger = "-" + test1.BigInteger;
	return test1;}
	else {	
	if (test1.BigInteger.length() < test2.BigInteger.length())
		{
			temp.BigInteger = test1.BigInteger;
			test1.BigInteger = test2.BigInteger;
			test2.BigInteger = temp.BigInteger;
		}
	int length1 = test1.BigInteger.length();
	int length2 = test2.BigInteger.length();
	int result[length1+length2]={};    //Forget to Initialize QQQQQ;
	for(int i=length2-1, k=0; i >=0; i--,k++)
	{
		int temp_num1, temp_num2, temp_result;
		temp_num2 = test2.BigInteger[i] - '0';
		for(int j=length1-1, w=k; j>=0; j--,w++)
		{
			temp_num1 = test1.BigInteger[j] - '0';
			temp_result = temp_num1 * temp_num2;
			//cout << temp_result << "," ;
			result[w] += temp_result;
			//cout << result[w] << "result" << w << " " << "," ;
		}
	}
	int carry = 0;
	for(int i=0; i < length1 + length2; i++)
	{
		if(result[i] >= 10)
		{
			result[i+1] += result[i] / 10;
			result[i] %= 10;
		}
	}
	//reverse;
	int final_array[length1+length2]={};
	for(int i=length1+length2-1, j=0; i>=0; i--,j++)
	{
		final_array[i] = result[j];
	}
	test1.BigInteger.resize(length1+length2);
	//copy;
	for(int i=length1+length2-1; i>=0; i--)
	{		
		test1.BigInteger[i] = final_array[i] + '0';
		//cout << final_array[i];
	}
	while(test1.BigInteger[0] == '0' && test1.BigInteger.length() != 1)
	{
		test1.BigInteger.erase(test1.BigInteger.begin());
	}
	return test1;}				
}

Large operator /(const Large& a, const Large& b)
{
	Large test1 = a, test2 = b, temp, plus; 
	temp.BigInteger = "0";
	plus.BigInteger = "1";
	if(test1.BigInteger[0] == '-' && test2.BigInteger[0] == '-' )
	{
		test1 = -test1;
		test2 = -test2;
		
		while (test1 > test2 || test1 == test2)
		{
			test1 = test1 - test2;
			temp = temp + plus;
		}
		return temp;
	}
	else if(test1.BigInteger[0] == '-')
	{
		int flag = 0;
		test1 = -test1;
		if(test1 < test2) flag = 1;
		while (test1 > test2 || test1 == test2)
		{
			test1 = test1 - test2;
			temp = temp + plus;
		}
		if (flag == 1) return temp;
		else return -temp;
	}
	else if(test2.BigInteger[0] == '-')
	{
		int flag = 0;
		test2 = -test2;
		if(test1 < test2) flag = 1;
		while (test1 > test2 || test1 == test2)
		{
			test1 = test1 - test2;
			temp = temp + plus;
		}
		if (flag == 1) return temp;
		else return -temp;
	}
	else
	{
		while (test1 > test2 || test1 == test2)
		{
			test1 = test1 - test2;
			temp = temp + plus;
		}
		return temp;	
	}
}
