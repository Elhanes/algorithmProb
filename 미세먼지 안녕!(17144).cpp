#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main()
{
	//variables

	vector < vector < int > > input;
	vector < vector < int > > cal;
	vector < int > tmp;
	int a, b, cleaner1 = 0, cleaner2 = 0;
	int spread;
	int answer = 0;
	int R, C, T;
	
	//input

	cin >> R >> C >> T;
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> a;
			tmp.push_back(a);
			if (a == -1)
			{
				if(cleaner1 == 0) cleaner1 = i;
				else cleaner2 = i;
			}
			
		}
		input.push_back(tmp);
		tmp.clear();
	}

	cal.resize((int)input.size());
	copy(input.begin(), input.end(), cal.begin());

	//algorithm

	for (int i = 0; i < T; i++)
	{
		//1. Dust spread
		for (int j = 0; j < R; j++)
		{
			for (int k = 0; k < C; k++)
			{
				a = input[j].at(k);
				b = cal[j].at(k);
				spread = a / 5;
				//check Dust
				if (a < 5) continue;
				
				//check spread direction
				if (j == 0)
				{
					//two direction
					if (k == 0)
					{
						cal[j].at(k) = b - (spread * 2);
						cal[j + 1].at(k) += spread;
						cal[j].at(k + 1) += spread;
					}
					//two direction
					else if(k == C - 1)
					{
						cal[j].at(k) = b - (spread * 2);
						cal[j + 1].at(k) += spread;
						cal[j].at(k - 1) += spread;
					}
					//three direction
					else
					{
						cal[j].at(k) = b - (spread * 3);
						cal[j + 1].at(k) += spread;
						cal[j].at(k + 1) += spread;
						cal[j].at(k - 1) += spread;
					}
				}
				else if (j == R - 1)
				{
					//two direction
					if (k == 0)
					{
						cal[j].at(k) = b - (spread * 2);
						cal[j - 1].at(k) += spread;
						cal[j].at(k + 1) += spread;
					}
					//two direction
					else if (k == C - 1)
					{
						cal[j].at(k) = b - (spread * 2);
						cal[j - 1].at(k) += spread;
						cal[j].at(k - 1) += spread;
					}
					//three direction
					else
					{
						cal[j].at(k) = b - (spread * 3);
						cal[j - 1].at(k) += spread;
						cal[j].at(k + 1) += spread;
						cal[j].at(k - 1) += spread;
					}
				}
				else if (j == cleaner1 - 1)
				{
					//two direction
					if (k == 0)
					{
						cal[j].at(k) = b - (spread * 2);
						cal[j - 1].at(k) += spread;
						cal[j].at(k + 1) += spread;
					}
					//three direction
					else if (k == C - 1)
					{
						cal[j].at(k) = b - (spread * 3);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k - 1) += spread;
					}
					//four direction
					else
					{
						cal[j].at(k) = b - (spread * 4);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k - 1) += spread;
						cal[j].at(k + 1) += spread;
					}
				}
				else if (j == cleaner2 + 1)
				{
					//two direction
					if (k == 0)
					{
						cal[j].at(k) = b - (spread * 2);
						cal[j + 1].at(k) += spread;
						cal[j].at(k + 1) += spread;
					}
					//three direction
					else if (k == C - 1)
					{
						cal[j].at(k) = b - (spread * 3);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k - 1) += spread;
					}
					//four direction
					else
					{
						cal[j].at(k) = b - (spread * 4);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k - 1) += spread;
						cal[j].at(k + 1) += spread;
					}
				}
				else if (j == cleaner1)
				{
					//three direction
					if (k == 1)
					{
						cal[j].at(k) = b - (spread * 3);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k + 1) += spread;
					}
					//three direction
					else if (k == C - 1)
					{
						cal[j].at(k) = b - (spread * 3);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k - 1) += spread;
					}
					//four direction
					else
					{
						cal[j].at(k) = b - (spread * 4);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k - 1) += spread;
						cal[j].at(k + 1) += spread;
					}
				}
				else if (j == cleaner2)
				{
					//three direction
					if (k == 1)
					{
						cal[j].at(k) = b - (spread * 3);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k + 1) += spread;
					}
					//three direction
					else if (k == C - 1)
					{
						cal[j].at(k) = b - (spread * 3);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k - 1) += spread;
					}
					//four direction
					else
					{
						cal[j].at(k) = b - (spread * 4);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k - 1) += spread;
						cal[j].at(k + 1) += spread;
					}
				}
				else
				{
					//three direction
					if (k == 0)
					{
					cal[j].at(k) = b - (spread * 3);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k + 1) += spread;
					}
					//three direction
					else if (k == C - 1)
					{
						cal[j].at(k) = b - (spread * 3);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k - 1) += spread;
					}
					//four direction
					else
					{
						cal[j].at(k) = b - (spread * 4);
						cal[j - 1].at(k) += spread;
						cal[j + 1].at(k) += spread;
						cal[j].at(k - 1) += spread;
						cal[j].at(k + 1) += spread;
					}
				}
			}
		}

		//2. Dust moving by cleaner
		for (int j = 0; j < R; j++)
		{
			for (int k = 0; k < C; k++)
			{
				b = cal[j].at(k);

				if (b == -1) continue;
				else
				{
					if (j == 0)
					{
						if(k == C - 1) input[j].at(k) = cal[j + 1].at(k);
						else input[j].at(k) = cal[j].at(k + 1);
					}
					else if (j == cleaner1)
					{
						if (k == 0) continue;
						else if (k == 1) input[j].at(k) = 0;
						else input[j].at(k) = cal[j].at(k - 1);
					}
					else if (j == cleaner2)
					{
						if (k == 0) continue;
						else if (k == 1) input[j].at(k) = 0;
						else input[j].at(k) = cal[j].at(k - 1);
					}
					else if (j == R - 1)
					{
						if (k == C - 1) input[j].at(k) = cal[j - 1].at(k);
						else input[j].at(k) = cal[j].at(k + 1);
					}
					else
					{
						if (k == 0)
						{
							if (j < cleaner1 && j > 0)
							{
								input[j].at(k) = cal[j - 1].at(k);	
							}
							else if (j > cleaner2 && j < R - 1)
							{
								input[j].at(k) = cal[j + 1].at(k);
							}
						}
						else if (k == C - 1)
						{
							if (j < cleaner1 && j > 0) input[j].at(k) = cal[j + 1].at(k);
							else if (j > cleaner2 && j < R - 1) input[j].at(k) = cal[j - 1].at(k);
						}
						else input[j].at(k) = cal[j].at(k);
					}
				}
			}
		}
		//for debugging
		/*cout << "------------------------after " << i+1 << "s--------------------------------\n";
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << cal[i].at(j) << " ";
			}
			cout << endl;
		}
		cout << "\n";
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << input[i].at(j) << " ";
			}
			cout << endl;
		}*/
		copy(input.begin(), input.end(), cal.begin());
	}

	//output
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			answer += input[i].at(j);
		}
	}

	cout << answer + 2 << endl;

	//check spread for debugging
	/*cout << "\n";
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << cal[i].at(j) << " ";
		}
		cout << endl;
	}
	cout << "\n";
	*/

	return 0;
}