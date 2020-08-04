#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>;

using namespace std;

int main()
{
	int n, answer = -1;
	cin >> n;

	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	queue<int> bfs;
	unordered_map<int, int> memo;


	if (n % 3 == 0)
	{
		bfs.push(n / 3);
		memo[n / 3] = 1;
	}
	if (n % 2 == 0)
	{
		bfs.push(n / 2);
		memo[n / 2] = 1;
	}
	bfs.push(n - 1);
	memo[n - 1] = 1;

	while (!bfs.empty())
	{
		int tmp = bfs.front();
		bfs.pop();

		if (tmp == 1)
		{
			answer = memo[tmp];
			break;
		}

		if (tmp % 3 == 0 && !memo.count(tmp / 3))
		{
			bfs.push(tmp / 3);
			memo[tmp / 3] = memo[tmp] + 1;
		}
		if (tmp % 2 == 0 && !memo.count(tmp / 2))
		{
			bfs.push(tmp / 2);
			memo[tmp / 2] = memo[tmp] + 1;
		}
		if (!memo.count(tmp - 1))
		{
			bfs.push(tmp - 1);
			memo[tmp - 1] = memo[tmp] + 1;
		}
	}

	cout << answer;

	return 0;
}