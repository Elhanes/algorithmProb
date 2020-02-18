#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int init_array(int a[26]);

int main()
{
	int count[26];
	int size, check = 0;

	cin >> size;

	string *input = new string[size];

	for (int i = 0; i < size; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < input[i].size(); j++)
		{
			if (input[i].at(j) == input[i].at(j - 1))
			{
				input[i].erase(j - 1, 1);
				j--;
			}
		}
	} //remove continual alphabet

	for (int i = 0; i < size; i++)
	{
		init_array(count);

		for (int j = 0; j < input[i].size(); j++)
		{
			count[input[i].at(j) - 97]++;
		}

		for (int j = 0; j < 26; j++)
		{
			if (count[j] > 1)
			{
				check++;
				break;
			}
		}
	} // group word checker

	cout << size - check << "\n";

	delete[] input;

	return 0; 
}

int init_array(int a[26])
{
	for (int i = 0; i < 26; i++)

		a[i] = 0;

	return 0;
}