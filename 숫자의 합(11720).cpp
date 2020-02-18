#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	int n, sum = 0;
	string a, b;

	cin >> n;
	cin.ignore(1, '\n');
	getline(cin, a);

	for (int i = 0; i < n; i++)
	{
		b = a.at(i);
		sum = sum + stoi(b);
	}

	cout << sum;

	return 0;
}