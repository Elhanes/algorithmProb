#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int m, score;
	int count = 0;
	char x;

	cin >> m;

	string *a = new string[m];

	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < m; i++)
	{
		score = 0;
		count = 0;

		for (int j = 0; j < a[i].size(); j++)
		{
			x = a[i].at(j);
			if (x == 'O')
			{
				count++;
				score += count;
			}
			else
				count = 0;
		}

		cout << score << "\n";
	}

	delete[] a;

	return 0; 
}