/*
* Author: Unfish0705
* Last Modified: 2020/4/18
*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

class Hotdogstand
{
public:
	void Just_sold();            //Increment the number of hot dogs sold
	int return_each_sold();      //Return the number of hot dogs sold by the stand
	int return_stand_ID();		 //Return stand ID
	static int return_total_sold();
	Hotdogstand(int input_stand_ID);          // constructor
	Hotdogstand();                            // default constructor

private:
	int stand_ID;
	int hot_dog_sold;
	static int total_sold;

};
int Hotdogstand::total_sold = 0;                   // Need to initialize !!!!!!!!!!!!!!!1

int main()
{
	Hotdogstand stand1(1919), stand2(19191), stand3;
	cout << stand1.return_stand_ID() << endl;
	stand1.Just_sold();
	stand2.Just_sold();
	cout << stand1.return_each_sold() << endl;
	cout << stand1.return_total_sold();

}

Hotdogstand::Hotdogstand(int input_stand_ID) : stand_ID(input_stand_ID), hot_dog_sold(0){}
Hotdogstand::Hotdogstand(): stand_ID(1), hot_dog_sold(0){}
int Hotdogstand::return_stand_ID()
{
	return stand_ID;
}

int Hotdogstand::return_each_sold()
{
	return hot_dog_sold;
}

int Hotdogstand::return_total_sold()                // Error: add static in front of declaration
{
	return total_sold ;
}

void Hotdogstand::Just_sold()
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int j = 0;
		j = rand();
		hot_dog_sold += j;
	}
	total_sold += hot_dog_sold;
}


