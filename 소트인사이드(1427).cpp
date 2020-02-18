#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long input;
	vector <int> sorting;

	cin >> input;

	while (input != 0)
	{
		sorting.push_back(input%10);
		input /= 10;
	}

	sort(sorting.begin(), sorting.end(), greater<int>());

	for (int i = 0; i < sorting.size(); i++) cout << sorting[i];

	return 0;
}