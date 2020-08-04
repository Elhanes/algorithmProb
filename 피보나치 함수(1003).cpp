#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int cal(int a, vector< pair <int, int> > memo);

int main()
{
	int T, n;

	cin >> T;

	vector< pair<int, int> > memo;

	for (int i = 0; i < 41; i++) memo.push_back(make_pair(0, 0));

	memo[0] = make_pair(1, 0);
	memo[1] = make_pair(0, 1);

	for (int i = 0; i < T; i++) 
	{
		cin >> n;
		cal(n, memo);
	}

	return 0;
}

int cal(int a, vector< pair <int, int> > memo)
{
	if (memo[a].first != 0 || memo[a].second != 0) cout << memo[a].first << " " << memo[a].second << "\n";
	else
	{
		for (int i = 2; i <= a; i++)
		{
			memo[i].first = memo[i - 2].first + memo[i - 1].first;
			memo[i].second = memo[i - 2].second + memo[i - 1].second;
		}
		cout << memo[a].first << " " << memo[a].second << "\n";
	}

	return 0;
}