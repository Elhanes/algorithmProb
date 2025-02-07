#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;

	cin >> n;

	if (n == 0)
	{
		cout << "0";
		return 0;
	}
	else if (n == 1)
	{
		cout << "1";
		return 0;
	}

	vector <long long> dp(n + 1, 0);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[n];

	return 0;
}