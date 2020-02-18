#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string a;
	int count = 0;

	cin >> a;

	for (int i = 97; i < 123; i++)
	{
		count = -1;

		for (int j = 0; j < a.size(); j++)
		{
			if (i == a.at(j))
			{
				count = j;
				break;
			}
		}
		cout << count << " ";
	}

	return 0; 
}