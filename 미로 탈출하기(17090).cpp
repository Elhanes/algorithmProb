#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	//variables

	vector < vector < char > > input;
	vector < vector < int > > visited;
	stack < pair <int, int> > rc;
	vector < char > tmp;
	vector < int > tmp1;
	char a;
	int b, next_b, rc_r, rc_c;
	int answer = 0;
	int counter = 0;
	int N, M, r, c;

	//input

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a;
			tmp.push_back(a);
			tmp1.push_back(0);
		}
		input.push_back(tmp);
		visited.push_back(tmp1);
		tmp.clear();
		tmp1.clear();
	}

	//algorithm

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			counter = 0;
			a = input[i][j];
			b = visited[i][j];
			r = i;
			c = j;

			if (b == 1) answer++;
			else if (b == 2) continue;
			else
			{
				while (1)
				{
					rc.push(make_pair(r, c));
					a = input[r][c];
					b = visited[r][c];
					visited[r][c] = 3;

					if (a == 'U') r = r - 1;
					else if (a == 'R') c = c + 1;
					else if (a == 'D') r = r + 1;
					else if (a == 'L') c = c - 1;

					if (r >= N || c >= M || r < 0 || c < 0)
					{
						answer++;
						while (!rc.empty())
						{
							rc_r = rc.top().first;
							rc_c = rc.top().second;
							rc.pop();
							visited[rc_r][rc_c] = 1;
						}
						break;
					}
					else
					{
						if ((r == i && c == j))
						{
							while (!rc.empty())
							{
								rc_r = rc.top().first;
								rc_c = rc.top().second;
								rc.pop();
								visited[rc_r][rc_c] = 2;
							}
							break;
						}
						else
						{
							next_b = visited[r][c];
							if(b == 1)
							{
								answer++;
								while (!rc.empty())
								{
									rc_r = rc.top().first;
									rc_c = rc.top().second;
									rc.pop();
									visited[rc_r][rc_c] = 1;
								}
								break;
							}
							else if(b == 2)
							{
								while (!rc.empty())
								{
									rc_r = rc.top().first;
									rc_c = rc.top().second;
									rc.pop();
									visited[rc_r][rc_c] = 2;
								}
								break;
							}
							else if (b == 3)
							{
								while (!rc.empty())
								{
									rc_r = rc.top().first;
									rc_c = rc.top().second;
									rc.pop();
									visited[rc_r][rc_c] = 2;
								}
								break;
							}
						}
					}

					if (counter > M*N)
					{
						while (!rc.empty())
						{
							rc_r = rc.top().first;
							rc_c = rc.top().second;
							rc.pop();
							visited[rc_r][rc_c] = 2;
						}
						break;
					}

					counter++;
				}

				while (!rc.empty()) rc.pop();
			}
		}
	}

	cout << answer << endl;

	return 0;
}