#include <iostream>

using namespace std;

int main()
{
	int score[5];
	int avg, sum = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> score[i];
		if (score[i] < 40)
			score[i] = 40;
	}

	for (int i = 0; i < 5; i++)
	{
		sum += score[i];
	}

	avg = sum / 5;
	cout << avg << "\n";

	return 0; 
}