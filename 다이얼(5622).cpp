#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int num, time = 0;
	string dial;

	cin >> dial;

	for (int i = 0; i < dial.size(); i++)
	{
		num = dial.at(i);
		if (num == 65 || num == 66 || num == 67)
			time += 3;
		else if (num == 68 || num == 69 || num == 70)
			time += 4;
		else if (num == 71 || num == 72 || num == 73)
			time += 5;
		else if (num == 74 || num == 75 || num == 76)
			time += 6;
		else if (num == 77 || num == 78 || num == 79)
			time += 7;
		else if (num == 80 || num == 81 || num == 82 || num == 83)
			time += 8;
		else if (num == 84 || num == 85 || num == 86)
			time += 9;
		else if (num == 87 || num == 88 || num == 89 || num == 90)
			time += 10;
		else
			continue;
	}

	cout << time;

	return 0; 
}