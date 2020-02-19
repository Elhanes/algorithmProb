#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	queue<int> bfs;

	cin >> N >> K;

	vector < vector<int> > memo(200001, vector<int>(2, 0));
	bfs.push(N);
	memo[N][0] = 1;

	//BFS

	vector <int> b(4, 0);
	int answer = 0;
	int tmp = N;

	while (tmp != K)
	{
		if (bfs.empty())
		{
			break;
		}
		tmp = bfs.front();
		bfs.pop();

		if (tmp + 1 < 200000 && memo[tmp + 1][0] == 0)
		{
			bfs.push(tmp + 1);
			memo[tmp + 1][0] = 1;
			memo[tmp + 1][1] = memo[tmp][1] + 1;
		}

		if (tmp - 1 >= 0 && memo[tmp - 1][0] == 0)
		{
			bfs.push(tmp - 1);
			memo[tmp - 1][0] = 1;
			memo[tmp - 1][1] = memo[tmp][1] + 1;
		}

		if (tmp * 2 < 200000 && memo[tmp * 2][0] == 0)
		{
			bfs.push(tmp * 2);
			memo[tmp * 2][0] = 1;
			memo[tmp * 2][1] = memo[tmp][1] + 1;
		}
	}

	cout << memo[K][1];

	return 0;
}