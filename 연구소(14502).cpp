#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	//variables
	int N, M;
	int answer = 0, count = 0;
	int a;
	int r1, r2, r3, c1, c2, c3;
	int r, c;
	int i1 = 0, i2 = 1, i3 = 2;

	vector <int> input_tmp;
	vector < vector <int> > input;
	vector < vector <int> > input_copy;

	vector < pair <int, int> > blank;
	queue < pair <int, int> > virus;

	//input
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a;
			if (a == 0) blank.push_back(make_pair(i, j));
			input_tmp.push_back(a);
		}

		input.push_back(input_tmp);
		input_tmp.clear();
	}

	input_copy.resize((int)input.size());
	copy(input.begin(), input.end(), input_copy.begin());

	//cout << blank.size() <<"debug point 1\n";

	//algorithm
	while (1)
	{
		//initialize
		vector < vector <bool> > visited(N, vector <bool>(M, 0));
		count = 0;
		copy(input.begin(), input.end(), input_copy.begin());

		// get location of install wall
		r1 = blank[i1].first;
		c1 = blank[i1].second;
		r2 = blank[i2].first;
		c2 = blank[i2].second;
		r3 = blank[i3].first;
		c3 = blank[i3].second;

		// install the wall
		input_copy[r1][c1] = 1;
		input_copy[r2][c2] = 1;
		input_copy[r3][c3] = 1;

		//virus spread
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (input_copy[i][j] == 2 && visited[i][j] == false)
				{
					virus.push(make_pair(i, j));
					visited[i][j] = true;
					while (!virus.empty())
					{
						r = virus.front().first;
						c = virus.front().second;
						virus.pop();

						if (r - 1 >= 0 && input_copy[r - 1][c] == 0 && visited[r - 1][c] == false)
						{
							virus.push(make_pair(r - 1, c));
							visited[r - 1][c] = true;
							input_copy[r - 1][c] = 2;
						}
						if (r + 1 < N && input_copy[r + 1][c] == 0 && visited[r + 1][c] == false)
						{
							virus.push(make_pair(r + 1, c));
							visited[r + 1][c] = true;
							input_copy[r + 1][c] = 2;
						}
						if (c - 1 >= 0 && input_copy[r][c - 1] == 0 && visited[r][c - 1] == false)
						{
							virus.push(make_pair(r, c - 1));
							visited[r][c - 1] = true;
							input_copy[r][c - 1] = 2;
						}
						if (c + 1 < M && input_copy[r][c + 1] == 0 && visited[r][c + 1] == false)
						{
							virus.push(make_pair(r, c + 1));
							visited[r][c + 1] = true;
							input_copy[r][c + 1] = 2;
						}
					}
				}
			}
		}

		//count safe zone;
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (input_copy[i][j] == 0) count++;

		//answer?
		if (count > answer) answer = count;

		//break decision or increasing index
		i3++;
		if (i3 == blank.size())
		{
			i2++;
			if (i2 == blank.size() - 1)
			{
				i1++;
				if (i1 == blank.size() - 2) break;
				else
				{
					i2 = i1 + 1;
					i3 = i2 + 1;
				}
			}
			else i3 = i2 + 1;
		}

		//cout << i1 << " " << i2 << " " << i3 << "\n";
	}

	//output
	cout << answer;

	return 0;
}