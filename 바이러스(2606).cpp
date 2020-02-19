#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	int row, col;
	int answer = 0;
	queue<int> bfs;

	cin >> N;
	cin >> M;

	vector <vector <bool> > graph(N + 1, vector<bool>(N + 1, 0));
	vector <bool> memo(N + 1, 0);

	//make graph
	for (int i = 0; i < M; i++)
	{
		cin >> row >> col;
		graph[row][col] = 1;
		graph[col][row] = 1;
	}

	//BFS
	bfs.push(1);

	while (!bfs.empty())
	{
		int tmp = bfs.front();
		bfs.pop();
		if (memo[tmp] == 0) answer++;
		memo[tmp] = 1;

		for (int i = 1; i < N + 1; i++)
		{
			if (graph[tmp][i] == 1 && memo[i] == 0) bfs.push(i);
		}
	}

	cout << answer - 1;

	return 0;
}