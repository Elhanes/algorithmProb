#include <iostream>
#include <vector>

using namespace std;

int Max(int a, int b) { return a > b ? a : b; }

int main()
{
	int n, input, max = 0;
	vector< vector<int> > triangle(501, vector<int> (501, 0));

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> input;
			triangle[i][j] = input;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1) triangle[i][j] += triangle[i - 1][j];
			else if (j == i) triangle[i][j] += triangle[i - 1][j - 1];
			else triangle[i][j] += Max(triangle[i - 1][j], triangle[i - 1][j - 1]);
		}
	}

	for (int i = 1; i <= n; i++) max = Max(max, triangle[n][i]);


	cout << max;

	return 0;
}