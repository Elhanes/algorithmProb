#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int N, answer;
vector < pair <int, int> > input;
vector < int > memo;

int calculation(int day);

int main()
{
	cin >> N;

	input.resize(N + 1);
	memo.resize(N + 1, 0);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		input[i] = make_pair(a, b);
	}

	if (input[0].first <= N) memo[0] = input[0].second;
	//memo[0] = input[0].second;

	calculation(N);

	//for (int i = 0; i < N; i++) cout << memo[i] << " ";

	//cout << "\n";

	sort(memo.begin(), memo.end(), greater<int>());

	cout << memo[0];

	//cout << "\n";

	return 0;
}

int calculation(int day)
{
	//cout << "debug : day " << day << "\n";
	vector< int > tmp;

	/*if (input[day].first > N - day)
	{
		cout << "debug : over day\n";
		calculation(day - 1);
		return 0;
	}*/

	if (day == 0) return 0;

	for (int i = day - 1; i >= 0; i--)
	{
		if (input[i].first + i <= day)
		{
			if (memo[i] == 0) calculation(i);
			tmp.push_back(memo[i]);
		}
	}

	if (tmp.size() == 0)
	{
		//cout << "debug : on day, " << day << " tmp size is 0 and val is " << input[day].second << "\n";
		memo[day] = input[day].second;
	}
	else
	{
		//cout << "debug : on day, " << day << " tmp size is " << tmp.size() << "\n";
		if (tmp.size() > 1) sort(tmp.begin(), tmp.end(), greater<int>());
		//cout << "debug : on day, " << day << " max val is " << tmp[0] << "\n";
		memo[day] = tmp[0] + input[day].second;
	}

	return 0;
}
