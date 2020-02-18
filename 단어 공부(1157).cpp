#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int init_array(int a[26]);

int main()
{
	int count[26];
	string input;
	int max = 0, tmp = 0;
	int num = 0;
	char output;

	init_array(count);

	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		if (input.at(i) >= 65 && input.at(i) <= 90)
			count[input.at(i) - 65]++;
		else
			count[input.at(i) - 97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (max < count[i])
		{
			max = count[i];
			num = i;
		}
		else if (max == count[i])
			tmp = max;
		else
			continue;
	}

	if (max == tmp)
		cout << "?\n";
	else
	{
		output = num + 65;
		cout << output << "\n";
	}

	return 0; 
}

int init_array(int a[26])
{
	for (int i = 0; i < 26; i++)
		a[i] = 0;

	return 0;
}