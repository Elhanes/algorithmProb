#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	//variables
	int n, l, tmp_input, diff;
	int up_count = 1;
	int down_count = 0;
	int answer = 0;
	bool down_check = 0;


	//input
	cin >> n >> l;

	vector<vector <int> > input(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp_input;
			input[i][j] = tmp_input;
		}
	}

	//algorithm
	//for column check
	for (int i = 0; i < n; i++)
	{
		//cout << "debug : start at column i = " << i << endl;
		for (int j = 0; j < n; j++)
		{
			if (j == n - 1)
			{
				if (down_check == 0)
				{
					//cout << "debug : completely passed away at column i = " << i << endl;
					answer++;
					break;
				}
				else
				{
					down_count++;
					if (down_count >= l)
					{
						//cout << "debug : completely passed away at row i = " << i << endl;
						answer++;
						break;
					}
					else
					{
						//cout << "debug : down_check activate at answer phase" << endl;
						break;
					}
				}
			}

			diff = input[i][j + 1] - input[i][j];
			if (diff > 1 || diff < -1)
			{
				//cout << "debug : over height" << endl;
				break;
			}

			if (diff == 0) // for stable
			{
				//cout << "debug : diff is 0" << endl;
				if (down_check == 1)
				{
					down_count++;
					if (down_count >= l)
					{
						down_check = 0;
						down_count = 0;
						up_count = 1;
					}
					else
					{
						up_count = 0;
					}
				}
				else if (down_check == 0)
				{
					up_count++;
				}
			}
			else if (diff == 1) // for higher
			{
				//cout << "debug : diff is 1" << endl;
				if (down_check == 1)
				{
					//cout << "debug : down check activate at diff 1" << endl;
					break;
				}
				else if (up_count < l)
				{
					//cout << "debug : lack of up_count at diff 1" << endl;
					break;
				}
				else
				{
					up_count = 1;
				}
			}
			else if (diff == -1) // for lower
			{
				//cout << "debug : diff is -1" << endl;
				if (down_check == 1)
				{
					down_count++;
					if (down_count >= l)
					{
						down_check = 1;
						down_count = 0;
						up_count = 1;
					}
					else
					{
						//cout << "debug : down check activate at diff -1" << endl;
						break;
					}
				}
				else
				{
					down_check = 1;
					down_check++;
					up_count = 0;
				}
			}
		}
		up_count = 1;
		down_count = 0;
		down_check = 0;
	}

	//for row check
	up_count = 1;
	down_count = 0;
	down_check = 0;

	for (int i = 0; i < n; i++)
	{
		//cout << "debug : start at row i = " << i << endl;
		for (int j = 0; j < n; j++)
		{
			if (j == n - 1)
			{
				if (down_check == 0)
				{
					//cout << "debug : completely passed away at row i = " << i << endl;
					answer++;
					break;
				}
				else
				{
					down_count++;
					if (down_count >= l)
					{
						//cout << "debug : completely passed away at row i = " << i << endl;
						answer++;
						break;
					}
					else
					{
						//cout << "debug : down_check activate at answer phase" << endl;
						break;
					}
				}
			}

			diff = input[j + 1][i] - input[j][i];
			if (diff > 1 || diff < -1)
			{
				//cout << "debug : over height" << endl;
				break;
			}

			if (diff == 0) // for stable
			{
				//cout << "debug : diff is 0" << endl;
				if (down_check == 1)
				{
					down_count++;
					if (down_count >= l)
					{
						down_check = 0;
						down_count = 0;
						up_count = 1;
					}
					else
					{
						up_count = 0;
					}
				}
				else if (down_check == 0)
				{
					up_count++;
				}
			}
			else if (diff == 1) // for higher
			{
				//cout << "debug : diff is 1" << endl;
				if (down_check == 1)
				{
					//cout << "debug : down check activate at diff 1" << endl;
					break;
				}
				else if (up_count < l)
				{
					//cout << "debug : lack of up_count at diff 1" << endl;
					break;
				}
				else
				{
					up_count = 1;
				}
			}
			else if (diff == -1) // for lower
			{
				//cout << "debug : diff is -1" << endl;
				if (down_check == 1)
				{
					down_count++;
					if (down_count >= l)
					{
						down_check = 1;
						down_count = 0;
						up_count = 1;
					}
					else
					{
						//cout << "debug : down check activate at diff -1" << endl;
						break;
					}
				}
				else
				{
					down_check = 1;
					down_check++;
					up_count = 0;
				}
			}
		}
		up_count = 1;
		down_count = 0;
		down_check = 0;
	}

	cout << answer;

	//free vector
	for (int i = 0; i < n; i++)
	{
		input[i].clear();
	}
	input.clear();

	return 0;
}