#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	// variables
	string input = "";
	int check[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int answer = 0;
	int tmp;

	// input 

	cin >> input;

	// algorithm

	for (int i = 0; i < input.size(); i++)
	{
		tmp = input[i] - '0';
		check[tmp]++;
	}

	if (check[6] + check[9] != 0)
	{
		if ((check[6] + check[9]) % 2 == 1) check[6] = (check[6] + check[9]) / 2 + 1;
		else check[6] = (check[6] + check[9]) / 2;
	}

	for (int i = 0; i < 9; i++)
	{
		tmp = check[i];
		if (tmp > answer) answer = tmp;
	}

	// output

	cout << answer << endl;

	return 0;
}