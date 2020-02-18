#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int N, M;
	queue < pair < int, int > > bfs1;
	queue < pair < int, int > > bfs2;
	vector < vector <int> > input;
	vector < vector <int> > visited;
	int check_status = 0;
	int count = 0;
	int a = 0;

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		vector < int > tmp;
		int a;
		for (int j = 0; j < M; j++)
		{
			cin >> a;
			tmp.push_back(a);
		}
		input.push_back(tmp);
	}

	visited.assign(N, vector <int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (input[i][j] == 1 && visited[i][j] == 0)
			{
				bfs1.push(make_pair(i, j));
				visited[i][j] = 1;
			}
		}
	}

	while (1)
	{
		while (!bfs1.empty())
		{
			int row = bfs1.front().first;
			int col = bfs1.front().second;
			bfs1.pop();
			if (row - 1 >= 0 && input[row - 1][col] == 0 && visited[row - 1][col] == 0)
			{
				bfs2.push(make_pair(row - 1, col));
				input[row - 1][col] = 1;
				visited[row - 1][col] = 1;
			}
			if (row + 1 <= N - 1 && input[row + 1][col] == 0 && visited[row + 1][col] == 0)
			{
				bfs2.push(make_pair(row + 1, col));
				input[row + 1][col] = 1;
				visited[row + 1][col] = 1;
			}
			if (col - 1 >= 0 && input[row][col - 1] == 0 && visited[row][col - 1] == 0)
			{
				bfs2.push(make_pair(row, col - 1));
				input[row][col - 1] = 1;
				visited[row][col - 1] = 1;
			}
			if (col + 1 <= M - 1 && input[row][col + 1] == 0 && visited[row][col + 1] == 0)
			{
				bfs2.push(make_pair(row, col + 1));
				input[row][col + 1] = 1;
				visited[row][col + 1] = 1;
			}
		}

		if (bfs2.empty()) break;

		while (!bfs2.empty())
		{
			int row = bfs2.front().first;
			int col = bfs2.front().second;
			bfs1.push(make_pair(row, col));
			bfs2.pop();
		}

		count++;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (input[i][j] == 0)
			{
				count = -1;
				break;
			}
			else if (input[i][j] == -1) a++;
		}
	}

	if (a == N*M) count = -1;

	cout << count;

	return 0;
}