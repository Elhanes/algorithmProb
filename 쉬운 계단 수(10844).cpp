#include <iostream>
#include <vector>

using namespace std;

#define NUM 1000000000

int main()
{
	int n;
	long long answer = 0;
	cin >> n;

	vector< vector<long long> >memo(n + 1, vector<long long> (10, 0));

	for (int i = 1; i < 10; i++)
	{
		memo[1][i] = 1;
	}

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) memo[i][j] = (memo[i - 1][j + 1]) % NUM;
			else if (j == 9) memo[i][j] = (memo[i - 1][j - 1]) % NUM;
			else memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j + 1] % NUM);
		}
	}

	for (int i = 0; i < 10; i++) answer += memo[n][i];
	cout << answer % NUM;

	return 0;
}