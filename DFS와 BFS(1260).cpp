#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, V;
	int row, col;
	stack<int> dfs;
	queue<int> bfs;

	cin >> N >> M >> V;

	vector <vector <bool> > graph(N + 1, vector<bool>(N + 1, 0));
	vector <bool> memo1(N + 1, 0);
	vector <bool> memo2(N + 1, 0);

	//make graph
	for (int i = 0; i < M; i++)
	{
		cin >> row >> col;
		graph[row][col] = 1;
		graph[col][row] = 1;
	}

	//DFS
	dfs.push(V);

	while (!dfs.empty())
	{
		int tmp = dfs.top();
		dfs.pop();
		if (memo1[tmp] == 0) cout << tmp << " ";
		memo1[tmp] = 1;

		for (int i = N; i > 0; i--)
		{
			if (graph[tmp][i] == 1 && memo1[i] == 0) dfs.push(i);
		}
	}

	cout << "\n";
	//BFS
	bfs.push(V);

	while (!bfs.empty())
	{
		int tmp = bfs.front();
		bfs.pop();
		if (memo2[tmp] == 0) cout << tmp << " ";
		memo2[tmp] = 1;

		for (int i = 1; i < N + 1; i++)
		{
			if (graph[tmp][i] == 1 && memo2[i] == 0) bfs.push(i);
		}
	}

	return 0;
}