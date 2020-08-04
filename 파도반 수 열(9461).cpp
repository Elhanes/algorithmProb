#include <iostream>
#include <vector>

using namespace std;

vector<long long> answer;
vector<long long> memo(101, 0);

int cal(int a);

int main()
{
	int T, n;

	cin >> T;

	memo[1] = 1;
	memo[2] = 1;
	memo[3] = 1;

	for (int i = 0; i < T; i++)
	{
		cin >> n;
		cal(n);
	}

	for (int i = 0; i < answer.size(); i++) cout << answer[i] << "\n";

	return 0;
}

int cal(int a)
{
	if (memo[a] != 0) answer.push_back(memo[a]);
	else
	{
		for (int i = 4; i <= a; i++)
		{
			memo[i] = memo[i - 3] + memo[i - 2];
		}
		answer.push_back(memo[a]);
	}

	return 0;
}