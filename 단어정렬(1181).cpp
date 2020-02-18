#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const pair <string, int>& a, const pair <string, int>& b);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	//char tmp;
	string line;
	vector < pair <string, int> > input;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> line;
		input.push_back(make_pair(line, line.size()));
	}

	sort(input.begin(), input.end(), compare);

	for (int i = 0; i < N; i++)
	{
		if (i > 0 && input[i].first == input[i - 1].first) continue;
		cout << input[i].first << "\n";
	}

	return 0;
}

bool compare(const pair <string, int>& a, const pair <string, int>& b)
{
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}