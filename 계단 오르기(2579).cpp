#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	int n, a, b, answer;
	vector <int> input;
	cin >> n;
	
	if (n == 1)
	{
		cin >> a;
		cout << a;
		return 0;
	}
	else if (n == 2)
	{
		cin >> a;
		cin >> b;
		cout << a + b;
		return 0;
	}

	vector < int > memo(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		input.push_back(a);
	}

	memo[0] = input[0];
	memo[1] = max(input[0] + input[1], input[1]);
	memo[2] = max(input[0] + input[2], input[1] + input[2]);

	for (int i = 3; i < n; i++) memo[i] = max(input[i] + memo[i - 2], input[i] + input[i - 1] + memo[i - 3]);

	cout << memo[n - 1];

	return 0;
}