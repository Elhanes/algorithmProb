#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	string input;
	int x, y, z, length, tictoc = 0, count = 0;
	cin >> input;

	//c=, c-, dz=, d-, lj, nj, s=, z=

	length = input.size();

	for (int i = 0; i < input.size() - 1; i++)
	{
		x = input.at(i);
		y = input.at(i + 1);
		if ((x == 99 && y == 61) || (x == 99 && y == 45) || (x == 100 && y == 45) || (x == 108 && y == 106) || (x == 110 && y == 106) || (x == 115 && y == 61) || (x == 122 && y == 61))
			length--;
	}

	for (int i = 0; i < input.size() - 2; i++)
	{
		x = input.at(i);
		y = input.at(i + 1);
		z = input.at(i + 2);
		if (x == 100 && y == 122 && z == 61)
			length--;
	}

	cout << length;

	return 0; 
}