#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector < vector <int> > input;
vector < vector <int> > memo;

int calculation(int a, int b);

int min(int a, int b);
int min(int a, int b, int c);

int main()
{
	//variable 
	int N, R, G, B, answer = 0;
	int a, b, c;

	cin >> N;

	//input
	for (int i = 0; i < N; i++)
	{
		vector <int> tmp1;
		vector <int> tmp2(3, 0);
		
		cin >> R >> G >> B;
		tmp1.push_back(R);
		tmp1.push_back(G);
		tmp1.push_back(B);
		
		input.push_back(tmp1);
		memo.push_back(tmp2);
	}

	memo[0][0] = input[0][0];
	memo[0][1] = input[0][1];
	memo[0][2] = input[0][2];

	a = calculation(N - 1, 0);
	b = calculation(N - 1, 1);
	c = calculation(N - 1, 2);

	cout << min(a, b, c);

	return 0;
}

int calculation(int a, int b)
{
	int result;

	if (b == 0)
	{
		if (!memo[a - 1][1]) memo[a - 1][1] = calculation(a - 1, 1);
		if (!memo[a - 1][2]) memo[a - 1][2] = calculation(a - 1, 2);

		result = min(memo[a - 1][1], memo[a - 1][2]) + input[a][b];
	}
	else if (b == 1)
	{
		if (!memo[a - 1][0]) memo[a - 1][0] = calculation(a - 1, 0);
		if (!memo[a - 1][2]) memo[a - 1][2] = calculation(a - 1, 2);

		result = min(memo[a - 1][0], memo[a - 1][2]) + input[a][b];
	}
	else if (b == 2)
	{
		if (!memo[a - 1][0]) memo[a - 1][0] = calculation(a - 1, 0);
		if (!memo[a - 1][1]) memo[a - 1][1] = calculation(a - 1, 1);

		result = min(memo[a - 1][0], memo[a - 1][1]) + input[a][b];
	}

	return result;
}

int min(int a, int b)
{
	if (a > b) return b;

	return a;
}

int min(int a, int b, int c)
{
	int tmp;

	tmp = min(a, b);

	if (tmp > c) return c;
	else return tmp;
}