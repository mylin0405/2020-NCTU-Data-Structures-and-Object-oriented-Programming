/*

*/
#include<iostream>
using namespace std;

class Fraction
{
public:
	void input();
	void output();
	void set(int new_num, int new_deno);  //mutator function
	int gcd();
	int get_numerator();  // Accessor function
	int get_denominator(); // Accessor function

private:
	int numerator;
	int denominator;
};

int main()
{
	Fraction fraction, fraction1;
	fraction.input();
	fraction1.set(20, 60);
	cout << fraction.get_numerator() << " " << fraction.get_denominator() << endl;
	fraction.output();
	fraction1.output();
}

void Fraction::set(int new_num, int new_deno)
{
	numerator = new_num;
	denominator = new_deno;
}

void Fraction::input()
{
	cout << "Please enter a numerator" << endl;
	cin >> numerator;
	cout << "Please enter a denominator" << endl;
	cin >> denominator;
}

int Fraction::gcd()
{
	int a, b, t;
	a = numerator; b = denominator;
	while (b!= 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void Fraction::output()
{
	int divide;
	divide = gcd();
	numerator /= divide;
	denominator /= divide;
	cout << numerator << "/" << denominator << endl;
}

int Fraction::get_numerator()
{
	return numerator;
}

int Fraction::get_denominator()
{
	return denominator;
}
