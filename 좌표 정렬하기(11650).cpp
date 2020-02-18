#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair <int, int>& a, const pair <int, int>& b);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, a, b;
	vector < pair <int, int> > input;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		input.push_back(make_pair(a, b));
	}

	sort(input.begin(), input.end(), compare);

	for (int i = 0; i < N; i++) cout << input[i].first << " " << input[i].second << "\n";

	return 0;
}

bool compare(const pair <int, int>& a, const pair <int, int>& b)
{
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}