#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// global variable
int answer_num = 0;
vector < int > answer;

// algorithm including function
int findArea(vector < vector <int> > input, int N);

int main()
{
	// local main variable
	int N, input_tmp;
	vector < vector <int> > input;
	vector < int > tmp;
	string a;

	// input
	cin >> N;

	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		getline(cin, a);
		for (int j = 0; j < a.size(); j++)
		{
			input_tmp = a[j] - '0';
			tmp.push_back(input_tmp);
		}
		
		input.push_back(tmp);
		tmp.clear();
	}

	// function call
	findArea(input, N);

	// output
	cout << answer_num << endl;
	// sort the answer
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) cout << answer[i] << endl;

	return 0;
}

int findArea(vector < vector <int> > input, int N)
{
	// local findArea variables
	queue < pair <int, int> > bfs_queue;
	vector < vector < int > > visited(N, vector <int> (N, 0));
	int count = 0;
	
	// BFS, and get answers
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (input[i][j] == 1 && visited[i][j] == 0)
			{
				answer_num++;
				bfs_queue.push(make_pair(i, j));
				visited[i][j] = 1;
				while (!bfs_queue.empty())
				{
					int row = bfs_queue.front().first;
					int col = bfs_queue.front().second;
					bfs_queue.pop();
					count++;

					if (row - 1 >= 0 && input[row - 1][col] == 1 && visited[row - 1][col] == 0)
					{
						bfs_queue.push(make_pair(row - 1, col));
						visited[row - 1][col] = 1;	
					}

					if (row + 1 <= N - 1 && input[row + 1][col] == 1 && visited[row + 1][col] == 0)
					{
						bfs_queue.push(make_pair(row + 1, col));
						visited[row + 1][col] = 1;
					}

					if (col - 1 >= 0 && input[row][col - 1] == 1 && visited[row][col - 1] == 0)
					{
						bfs_queue.push(make_pair(row, col - 1));
						visited[row][col - 1] = 1;
					}

					if (col + 1 <= N - 1 && input[row][col + 1] == 1 && visited[row][col + 1] == 0)
					{
						bfs_queue.push(make_pair(row, col + 1));
						visited[row][col + 1] = 1;						
					}
				}

				answer.push_back(count);
				count = 0;
			}
		}
	}

	return 0;
}