#include <iostream>
#include <string.h>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	int N, M;
	char space_input;
	int x = 0, y = 0;
	int count = 1;
	char space[100][100];
	queue<int> save;
	int visit[2][10000];
	int visit_count = 0;
	int check = 0;

	//input
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> space_input;
			space[i][j] = space_input;
		}
	}

	save.push(0);
	save.push(0);
	save.push(1);
	visit[0][visit_count] = 0;
	visit[1][visit_count] = 0;


	//algorithm
	while (1)
	{
		if (save.empty() == 1) break;

		x = save.front();
		save.pop();
		y = save.front();
		save.pop();
		count = save.front();
		save.pop();

		//cout << x + 1 << " " << y << " " << count << "---" << '\n';

		if (x == M - 1 && y == N - 1)
		{
			//output
			cout << count;
		}

		if (space[y][x + 1] == '1' && y >= 0 && x + 1 >= 0 && y < N && x + 1 < M)
		{
			for (int i = 0; i <= visit_count; i++)
			{
				if (visit[0][i] == x + 1 && visit[1][i] == y) check++;
			}
			if (check == 0)
			{
				save.push(x + 1);
				save.push(y);
				save.push(count + 1);
				visit_count++;
				visit[0][visit_count] = x + 1;
				visit[1][visit_count] = y;
				//cout << x + 1 << ' ' << y << ' ' << count <<'\n';

			}
			else check = 0;
		}

		if (space[y][x - 1] == '1' && y >= 0 && x - 1 >= 0 && y < N && x - 1 < M)
		{
			for (int i = 0; i <= visit_count; i++)
			{
				if (visit[0][i] == x - 1 && visit[1][i] == y) check++;
			}
			if (check == 0)
			{
				save.push(x - 1);
				save.push(y);
				save.push(count + 1);
				visit_count++;
				visit[0][visit_count] = x - 1;
				visit[1][visit_count] = y;
				//cout << x - 1 << ' ' << y << ' ' << count << '\n';
			}
			else check = 0;
		}

		if (space[y + 1][x] == '1' && y + 1 >= 0 && x >= 0 && y + 1 < N && x < M)
		{
			for (int i = 0; i <= visit_count; i++)
			{
				if (visit[0][i] == x && visit[1][i] == y + 1) check++;
			}
			if (check == 0)
			{
				save.push(x);
				save.push(y + 1);
				save.push(count + 1);
				visit_count++;
				visit[0][visit_count] = x;
				visit[1][visit_count] = y + 1;
				//cout << x << ' ' << y + 1 << ' ' << count << '\n';
			}
			else check = 0;
		}

		if (space[y - 1][x] == '1' && y - 1 >= 0 && x >= 0 && y - 1 < N && x < M)
		{
			for (int i = 0; i <= visit_count; i++)
			{
				if (visit[0][i] == x && visit[1][i] == y - 1) check++;
			}
			if (check == 0)
			{
				save.push(x);
				save.push(y - 1);
				save.push(count + 1);
				visit_count++;
				visit[0][visit_count] = x;
				visit[1][visit_count] = y - 1;
				//cout << x << ' ' << y - 1 << ' ' << count << '\n';
			}
			else check = 0;
		}
	}
}