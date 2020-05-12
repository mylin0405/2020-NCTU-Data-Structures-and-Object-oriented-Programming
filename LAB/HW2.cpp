/* HW2 String & Math
* Author: Unfish0705
* Last Modified: 2020/5/12
*/

#include <iostream>
#include <cmath>
#include <string>
#include <climits>
/*The header files above are those you might use.
You can include other header files if you need to use them.
But make sure those header files can be used in the test environment. */
using namespace std;


class Machine {  /* DO NOT add any code in this parent class and its virtual function*/
    protected:
        string type;
    public:
        virtual void welcome_message(){}
        virtual void problem_solver(){}
};


class Math_machine:public Machine{
    public:
        Math_machine(string type) {this->type = type;}
        void welcome_message(){cout<<"Solving the "<<type<<" problem."<<endl;}
        void problem_solver(int x) 
        {
            int Min_X, Min_Y, Min;
            Min_X = INT_MAX;
            Min_Y = INT_MAX;
            Min = INT_MAX;
            for (int y= 1; y<= x; y++)
            {
                int temp;
                int temp_min;
                if (x % y == 0)
                {
                    temp = x / y;
                    temp_min = abs(y - temp);
                    if (temp_min < Min)
                    {
                        Min = temp_min;
                        Min_X = y;
                        Min_Y = temp;
                    }
                }
                if ((x + 1) % y == 0)
                {
                    temp = (x + 1) / y;
                    temp_min = abs(y - temp);
                    if (temp_min < Min)
                    {
                        Min = temp_min;
                        Min_X = y;
                        Min_Y = temp;
                    }
                }
            }
            if (Min_X > Min_Y) swap(Min_X, Min_Y);
            cout << Min_X << " " << Min_Y << endl;
        }
};

class String_machine:public Machine{
    public:
        String_machine(string type) {this->type = type;}
        void welcome_message(){cout<<"Solving the "<<type<<" problem."<<endl;}
        void problem_solver(string str)
        { 
            int count_0 = 0;
            int count_1 = 0;
            int count = 0;
            for (int i = 0; i < str.length(); i++)
            {
                if (i == 0) 
                {
                    if (str[i] == '1') count_1++;
                    else count_0++;
                }
                else {
                    if (str[i] == '1') 
                    {
                        if (str[i - 1] == '1') count_1++;
                        else count_1 = 1;
                        if (count_0 >= count_1) count++;
                    }
                    else if (str[i] == '0') {
                        if (str[i - 1] == '0') count_0++;
                        else count_0 = 1;
                        if (count_1 >= count_0) count++;
                    }
                }
            }
            cout << count << endl;
        }         
};

int main()
{
    string type;
    while (cin >> type)
    {
        if (type == "math")
        {
            Math_machine Math(type);
            Math.welcome_message();
            int x;
            cin >> x;
            Math.problem_solver(x);
        }
        if (type == "string")
        {
            String_machine String(type);
            String.welcome_message();
            string sstring;
            cin >> sstring;
            String.problem_solver(sstring);
        }
    }
}
