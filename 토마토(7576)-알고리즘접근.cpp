#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// global variables
int N, M;
queue < pair < int, int > > bfs;
vector < vector <int> > input;
vector < vector <int> > input_copy;
vector < vector <int> > visited;

int search();
int grow();
int check();

int main()
{
	int check_status = 0;
	int count = 0;
	int k;

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

	input_copy.resize((int)input.size());
	copy(input.begin(), input.end(), input_copy.begin());
	visited.assign(N, vector <int>(M, 0));

	while (1)
	{
		search();
		grow();
		check_status = check();
		if (check_status == 2)
		{
			count = -1;
			break;
		}
		else if (check_status == 1) break;
		else count++;
	}

	cout << count;

	return 0;
}

int search()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (input[i][j] == 1 && visited[i][j] == 0)
			{
				bfs.push(make_pair(i, j));
				visited[i][j] = 1;
			}
		}
	}
	return 0;
}

int grow()
{
	while (!bfs.empty())
	{
		int row = bfs.front().first;
		int col = bfs.front().second;
		bfs.pop();
		if (row - 1 >= 0 && input_copy[row - 1][col] == 0) input_copy[row - 1][col] = 1;
		if (row + 1 <= N - 1 && input_copy[row + 1][col] == 0) input_copy[row + 1][col] = 1;
		if (col - 1 >= 0 && input_copy[row][col - 1] == 0) input_copy[row][col - 1] = 1;
		if (col + 1 <= M - 1 && input_copy[row][col + 1] == 0) input_copy[row][col + 1] = 1;
	}
	return 0;
}

int check()
{
	int a = 0;
	if (input_copy == input)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (input[i][j] == 0) return 2;
				else if (input[i][j] == -1) a++;
			}
		}

		if (a == N*M) return 2;
		else return 1;
	}
	else
	{
		input = input_copy;
		return 0;
	}
}