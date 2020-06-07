/* HW3 SimpleVector
* Author: Unfish0705
* Last Modified: 2020/6/7
*/

#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class SimpleVector
{
public:
	SimpleVector();
	SimpleVector(int size);
	~SimpleVector();
	int my_size();
	int my_capacity();
	int my_empty();
	void my_clear();
	void my_reverse();
	void my_extend();
	void my_pop_back();
	void my_push_back(T value);
	void my_insert(T value, int index);
	void my_set(T value, int index);
	void print();
	void my_reserve();
	T& operator [](int index);

private:
	T* vector;
	int size;
	int capacity;
};
// Default constructor, set length to 5;
template <class T>
SimpleVector<T>::SimpleVector()
{
	capacity = 5;
	size = 0;
	vector = new T[5];
}

// Construcotr, set vector length with int;
template <class T>
SimpleVector<T>::SimpleVector(int size_t):size(size_t)
{
	capacity = size;
	size = 0;
	vector = new T[size];
}

// Destructor, delete the vector space;
template <class T>
SimpleVector<T>::~SimpleVector()
{
	delete[] vector;
}

// Add a element to the back of vector, and then do size increment;
template <class T>
void SimpleVector<T>::my_push_back(T value)
{
	if (size >= capacity)
	{
		my_extend();
	}
	vector[size] = value;
	size++;
}

// Decrement size;
template<class T>
void SimpleVector<T>::my_pop_back()
{
	if(size > 0)
	{
		size--;
	} 
	else size = 0;
}

// Return exist element numbers in the vector;
template <class T>
int SimpleVector<T>::my_size()
{
	return size;
}

// Return capacity;
template <class T>
int SimpleVector<T>::my_capacity()
{
	return capacity;
}

// If vector is empty(size is 0), return 0. else return 1;
template <class T>
int SimpleVector<T>::my_empty()
{
	if (size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Call my_reserve, extend capacity to x2;
template <class T>
void SimpleVector<T>::my_extend()
{
	capacity = capacity * 2;
	my_reserve();
}

// Reserve the data and allocate new vector;
template <class T>
void SimpleVector<T>::my_reserve()
{
	T* new_vector = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		new_vector[i] = vector[i];
	}
	delete[] vector;
	vector = new_vector;
}

// Set all elements to '\0', and set size to 0;
template <class T>
void SimpleVector<T>::my_clear()
{
	for (int i = 0; i < size; i++)
	{
		vector[i] = '\0';
	}
	size = 0;
}

// Reverse all elements;
template<class T>
void SimpleVector<T>::my_reverse()
{
	T* temp_vector = new T[capacity];
	for (int i = size - 1, j = 0; i >= 0; i--, j++)
	{
		temp_vector[j] = vector[i];
	}
	delete[] vector;
	vector = temp_vector;
}

// Insert a element to vector with index;
template<class T>
void SimpleVector<T>::my_insert(T value, int index)
{
	if (size + 1 > capacity)
	{
		my_extend();
	}
	T* new_vector = new T[capacity];
	for (int i = index; i < capacity; i++)
	{
		new_vector[i] = vector[i];
	}
	vector[index] = value;
	for (int i = index + 1; i < capacity; i++)
	{
		vector[i] = new_vector[i-1];
	}
	delete[] new_vector;
	size++;
}

// Set vector value with index;
template<class T>
void SimpleVector<T>::my_set(T value, int index)
{
	vector[index] = value;
}

// Print vector elements;
template<class T>
void SimpleVector<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << vector[i] << "_";
	}
}

// Print vector elements with operator overloading [];
template<class T>
T& SimpleVector<T> :: operator[](int index)
{
	return vector[index];
}
