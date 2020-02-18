#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
	// variables
	int R, C;
	bool success = false;
	int count = 1;
	vector < vector <char> > input;
	queue < pair <int, int> > water_bfs1;
	queue < pair <int, int> > water_bfs2;
	queue < pair <int, int> > mob_bfs1;
	queue < pair <int, int> > mob_bfs2;

	cin >> R >> C;

	vector < vector < bool > > water_visited(R, vector <bool> (C, 0));
	vector < vector < bool > > mob_visited(R, vector <bool> (C, 0));

	cin.ignore();

	for (int i = 0; i < R; i++)
	{
		string input_tmp;
		vector < char > tmp;
		getline(cin, input_tmp);
		for (int j = 0; j < input_tmp.size(); j++)
		{
			tmp.push_back(input_tmp[j]);
			if (input_tmp[j] == '*')
			{
				water_bfs1.push(make_pair(i, j));
				water_visited[i][j] = true;
			}
			else if (input_tmp[j] == 'S')
			{
				mob_bfs1.push(make_pair(i, j));
				mob_visited[i][j] = true;
			}
		}

		input.push_back(tmp);
	}

	// algorithm
	while (1)
	{
		//moving water
		while (!water_bfs1.empty())
		{
			int r = water_bfs1.front().first;
			int c = water_bfs1.front().second;
			water_bfs1.pop();

			if (r - 1 >= 0 && input[r - 1][c] == '.' && water_visited[r - 1][c] == false)
			{
				water_bfs2.push(make_pair(r - 1, c));
				input[r - 1][c] = '*';
				//input[r - 1][c] = count + '0';
				water_visited[r - 1][c] = true;
			}
			if (r + 1 < R && input[r + 1][c] == '.' && water_visited[r + 1][c] == false)
			{
				water_bfs2.push(make_pair(r + 1, c));
				input[r + 1][c] = '*';
				//input[r + 1][c] = count + '0';
				water_visited[r + 1][c] = true;
			}
			if (c - 1 >= 0 && input[r][c - 1] == '.' && water_visited[r][c - 1] == false)
			{
				water_bfs2.push(make_pair(r, c - 1));
				input[r][c - 1] = '*';
				//input[r][c - 1] = count + '0';
				water_visited[r][c - 1] = true;
			}
			if (c + 1 < C && input[r][c + 1] == '.' && water_visited[r][c + 1] == false)
			{
				water_bfs2.push(make_pair(r, c + 1));
				input[r][c + 1] = '*';
				//input[r][c + 1] = count + '0';
				water_visited[r][c + 1] = true;
			}
		}

		//moving mob
		while (!mob_bfs1.empty())
		{
			int r = mob_bfs1.front().first;
			int c = mob_bfs1.front().second;
			mob_bfs1.pop();

			if (r - 1 >= 0 && mob_visited[r - 1][c] == false)
			{
				if (input[r - 1][c] == '.')
				{
					mob_bfs2.push(make_pair(r - 1, c));
					mob_visited[r - 1][c] = true;
				}
				else if (input[r - 1][c] == 'D')
				{
					success = true;
					break;
				}
			}
			if (r + 1 < R && mob_visited[r + 1][c] == false)
			{
				if (input[r + 1][c] == '.')
				{
					mob_bfs2.push(make_pair(r + 1, c));
					mob_visited[r + 1][c] = true;
				}
				else if (input[r + 1][c] == 'D')
				{
					success = true;
					break;
				}
			}
			if (c - 1 >= 0 && mob_visited[r][c - 1] == false)
			{
				if (input[r][c - 1] == '.')
				{
					mob_bfs2.push(make_pair(r, c - 1));
					mob_visited[r][c - 1] = true;
				}
				else if (input[r][c - 1] == 'D')
				{
					success = true;
					break;
				}
			}
			if (c + 1 < C && mob_visited[r][c + 1] == false)
			{
				if (input[r][c + 1] == '.')
				{
					mob_bfs2.push(make_pair(r, c + 1));
					mob_visited[r][c + 1] = true;
				}
				else if (input[r][c + 1] == 'D')
				{
					success = true;
					break;
				}
			}
		}

		//check success
		if (success) break;
		else
		{
			if (water_bfs2.empty() && mob_bfs2.empty()) break;

			while (!water_bfs2.empty())
			{
				int r = water_bfs2.front().first;
				int c = water_bfs2.front().second;
				water_bfs1.push(make_pair(r, c));
				water_bfs2.pop();
			}

			while (!mob_bfs2.empty())
			{
				int r = mob_bfs2.front().first;
				int c = mob_bfs2.front().second;
				mob_bfs1.push(make_pair(r, c));
				mob_bfs2.pop();
			}
			count++;
		}

	}
	
	// output
	/*cout << "\n";

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++) cout << input[i][j];
		cout << "\n";
	}*/

	if (success) cout << count;
	else cout << "KAKTUS";

	return 0;
}