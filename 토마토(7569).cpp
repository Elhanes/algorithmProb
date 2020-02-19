#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, N, H, a;
	queue< vector<int> > bfs;

	cin >> M >> N >> H;

	vector < vector < vector <int> > > box;
	vector < vector <int> >tmp(N, vector<int>(M, 0));
	vector < vector < vector <bool> > > memo(H, vector < vector<bool> >(N, vector<bool> (M, 0)));

	//input box info

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> a;
				tmp[j][k] = a;
				if (a == 1)
				{
					vector<int> b;
					b.push_back(i);
					b.push_back(j);
					b.push_back(k);
					b.push_back(0);
					bfs.push(b);
				}
			}
		}
		box.push_back(tmp);
	}

	//test for input box info

	/*for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cout << box[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}*/

	//BFS

	vector <int> b(4, 0);
	int answer = 0;

	while (!bfs.empty())
	{
		int h = bfs.front()[0];
		int r = bfs.front()[1];
		int c = bfs.front()[2];
		int phase = bfs.front()[3];

		if (answer < phase) answer = phase;

		bfs.pop();

		memo[h][r][c] = 1;

		if (h - 1 >= 0 && memo[h - 1][r][c] == 0 && box[h - 1][r][c] == 0)
		{
			memo[h - 1][r][c] = 1;
			box[h - 1][r][c] = 1;
			b[0] = h - 1;
			b[1] = r;
			b[2] = c;
			b[3] = phase + 1;
			bfs.push(b);
		}

		if (h + 1 < H && memo[h + 1][r][c] == 0 && box[h + 1][r][c] == 0)
		{
			memo[h + 1][r][c] = 1;
			box[h + 1][r][c] = 1;
			b[0] = h + 1;
			b[1] = r;
			b[2] = c;
			b[3] = phase + 1;
			bfs.push(b);
		}

		if (r - 1 >= 0 && memo[h][r - 1][c] == 0 && box[h][r - 1][c] == 0)
		{
			memo[h][r - 1][c] = 1;
			box[h][r - 1][c] = 1;
			b[0] = h;
			b[1] = r - 1;
			b[2] = c;
			b[3] = phase + 1;
			bfs.push(b);
		}

		if (r + 1 < N && memo[h][r + 1][c] == 0 && box[h][r + 1][c] == 0)
		{
			memo[h][r + 1][c] = 1;
			box[h][r + 1][c] = 1;
			b[0] = h;
			b[1] = r + 1;
			b[2] = c;
			b[3] = phase + 1;
			bfs.push(b);
		}

		if (c - 1 >= 0 && memo[h][r][c - 1] == 0 && box[h][r][c - 1] == 0)
		{
			memo[h][r][c - 1] = 1;
			box[h][r][c - 1] = 1;
			b[0] = h;
			b[1] = r;
			b[2] = c - 1;
			b[3] = phase + 1;
			bfs.push(b);
		}

		if (c + 1 < M && memo[h][r][c + 1] == 0 && box[h][r][c + 1] == 0)
		{
			memo[h][r][c + 1] = 1;
			box[h][r][c + 1] = 1;
			b[0] = h;
			b[1] = r;
			b[2] = c + 1;
			b[3] = phase + 1;
			bfs.push(b);
		}
	}

	// test for output box
	/*
	cout << "\n";
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cout << box[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}*/

	//check -1

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (box[i][j][k] == 0)
				{
					cout << "-1";
					return 0;
				}
			}
		}
	}

	cout << answer;

	return 0;
}