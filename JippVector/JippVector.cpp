#include <iostream>

#include "JippVector.h"

using namespace std;

int main()
{
	JippVector<int> intVector(8);
	intVector.size = 8;

	intVector.fill(0);

	for (size_t i = 0; i < intVector.size; i++)
	{
		cout << intVector.data[i] << endl;
	}

	cout << endl;

	intVector.fill(2, 3, 997);

	for (size_t i = 0; i < intVector.size; i++)
	{
		cout << intVector.data[i] << endl;
	}
}