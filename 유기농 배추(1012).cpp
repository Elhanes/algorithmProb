#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//global variable
int T; //test case number
vector <int> answer;

int getWorm(); // calculate num of worm

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) getWorm();

	//output
	for (int i = 0; i < T; i++) cout << answer[i] << "\n";
}

int getWorm()
{
	int N, M; // row, col of ground
	int K; // vegitable num
	int X, Y; // vegitable location
	int count = 0; // count of worm, add to answer vector

	queue <pair <int, int> > bfs;

	cin >> M >> N >> K;
	vector < vector <int> > input(N, vector<int>(M, 0));
	vector < vector <bool> > visited(N, vector<bool>(M, 0));

	for (int i = 0; i < K; i++)
	{
		cin >> X >> Y;
		input[Y][X] = 1;
	}

	//debug
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) cout << input[i][j];
		cout << "\n";
	}*/

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (input[i][j] == 1 && visited[i][j] == false)
			{
				bfs.push(make_pair(i, j));
				visited[i][j] == true;
				while (!bfs.empty())
				{
					int r = bfs.front().first;
					int c = bfs.front().second;
					bfs.pop();

					if (r - 1 >= 0 && input[r - 1][c] == 1 && visited[r - 1][c] == false)
					{
						bfs.push(make_pair(r - 1, c));
						visited[r - 1][c] = true;
					}
					
					if (r + 1 < N && input[r + 1][c] == 1 && visited[r + 1][c] == false)
					{
						bfs.push(make_pair(r + 1, c));
						visited[r + 1][c] = true;
					}

					if (c - 1 >= 0 && input[r][c - 1] == 1 && visited[r][c - 1] == false)
					{
						bfs.push(make_pair(r, c - 1));
						visited[r][c - 1] = true;
					}
					if (c + 1 < M && input[r][c + 1] == 1 && visited[r][c + 1] == false)
					{
						bfs.push(make_pair(r, c + 1));
						visited[r][c + 1] = true;
					}
				}
				count++;
			}
		}
	}

	answer.push_back(count);

	return 0;
}