#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int main()
{
	int r, c, d;
	int N, M;
	int space_input;
	int left, back, check = 0;
	int count = 0, tmp_count = 0;
	int space[50][50];

	//input
	cin >> N >> M;

	cin >> r >> c >> d;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> space_input;
			space[i][j] = space_input;
		}
	}

	// test case
	/*int space[11][10] = {1,1,1,1,1,1,1,1,1,1,
						 1,0,0,0,0,0,0,0,0,1,
						 1,0,0,0,1,1,1,1,0,1,
						 1,0,0,1,1,0,0,0,0,1,
						 1,0,1,1,0,0,0,0,0,1,
						 1,0,0,0,0,0,0,0,0,1,
						 1,0,0,0,0,0,0,1,0,1,
						 1,0,0,0,0,0,1,1,0,1,
						 1,0,0,0,0,0,1,1,0,1,
						 1,0,0,0,0,0,0,0,0,1,
						 1,1,1,1,1,1,1,1,1,1};*/
	
	//int space[3][3] = { 1,1,1,1,0,1,1,1,1 };

	//algorithm
	while (1)
	{
		//clean up
		if (space[r][c] == 0 && check == 0)
		{
			space[r][c] = 2;
			count++;
		}
		else check = 0;

		//decide left and back coordinate
		if (d == 0)
		{
			left = c - 1;
			back = r + 1;
		}
		else if (d == 1)
		{
			left = r - 1;
			back = c - 1;
		}
		else if (d == 2)
		{
			left = c + 1;
			back = r - 1;
		}
		else if (d == 3)
		{
			left = r + 1;
			back = c + 1;
		}
		
		if (d == 0 || d == 2)
		{
			if (tmp_count < 4)
			{
				//rule 1
				if (space[r][left] == 0)
				{
					if (d == 0) d = 3;
					else d--;
					c = left;
					tmp_count = 0;
				}
				//rule 2
				else if (space[r][left] == 1 || space[r][left] == 2 || left < 0 || left >= M)
				{
					if (d == 0) d = 3;
					else d--;
					tmp_count++;
				}
			}
			//rule 3, 4
			else
			{
				if (space[back][c] == 1 || back < 0 || back >= N)
					break;
				else if (space[back][c] == 2)
				{
					r = back;
					check = 1;
					tmp_count = 0;
				}
			}
		}
		else
		{
			if (tmp_count < 4)
			{
				//rule 1
				if (space[left][c] == 0)
				{
					if (d == 0) d = 3;
					else d--;
					r = left;
					tmp_count = 0;
				}
				//rule 2
				else if (space[left][c] == 1 || space[left][c] == 2 || left < 0 || left >= N)
				{
					if (d == 0) d = 3;
					else d--;
					tmp_count++;
				}
			}
			//rule 3, 4
			else
			{
				if (space[r][back] == 1 || back < 0 || back >= M)
					break;
				else if(space[r][back] == 2)
				{
					c = back;
					check = 1;
					tmp_count = 0;
				}
			}
		}
	}

	//output
	cout << count << "\n";

	//test ouput - space
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) cout << space[i][j];
		cout << "\n";
	}*/
}